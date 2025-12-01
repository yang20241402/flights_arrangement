"""
批量提取航班信息 - 通用版本
支持处理多个response文件（response1.txt, response2.txt, ...）
统一输出为 flights_json_extracted.csv 和 flights_json_extracted.json
"""

import json
import re
import pandas as pd
from datetime import datetime
import os
import glob


def find_response_files(pattern='response*.txt'):
    """查找所有response文件"""
    files = glob.glob(pattern)
    # 按数字排序
    files.sort(key=lambda x: int(re.search(r'\d+', x).group()) if re.search(r'\d+', x) else 0)
    return files


def extract_flights_from_json(filename):
    """从JSON文件中提取航班信息"""
    
    print(f"\n正在处理: {filename}")
    
    # 读取文件
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"✗ 读取文件失败: {e}")
        return []
    
    # 解析JSON
    try:
        data = json.loads(content)
        print(f"  ✓ JSON解析成功")
    except json.JSONDecodeError as e:
        print(f"  ✗ JSON解析失败: {e}")
        return []
    
    # 提取航班列表
    flights = []
    
    if 'data' in data and 'flightItineraryList' in data['data']:
        flight_list = data['data']['flightItineraryList']
        print(f"  ✓ 找到 {len(flight_list)} 个航班组合")
        
        for idx, item in enumerate(flight_list, 1):
            # 提取每个航段
            if 'flightSegments' in item:
                for seg_idx, segment in enumerate(item['flightSegments'], 1):
                    flight_info = extract_segment_info(segment, seg_idx)
                    
                    # 添加价格信息
                    if 'priceList' in item and item['priceList']:
                        price_info = item['priceList'][0]
                        flight_info['成人价格'] = f"¥{price_info.get('adultPrice', 0)}"
                        flight_info['儿童价格'] = f"¥{price_info.get('childPrice', 0)}"
                    
                    # 添加来源文件信息
                    flight_info['数据来源'] = filename
                    
                    flights.append(flight_info)
        
        print(f"  ✓ 提取 {len(flights)} 个航班")
    else:
        print(f"  ✗ 未找到航班数据")
    
    return flights


def extract_segment_info(segment, seg_no):
    """提取单个航段信息"""
    flight_info = {
        '航段序号': seg_no,
        '航空公司代码': segment.get('airlineCode', ''),
        '航空公司': segment.get('airlineName', ''),
        '飞行时长': f"{segment.get('duration', 0)}分钟",
    }
    
    # 提取航班详细信息
    if 'flightList' in segment and segment['flightList']:
        flight = segment['flightList'][0]
        
        flight_info.update({
            '航班号': flight.get('flightNo', ''),
            '出发城市': flight.get('departureCityName', ''),
            '出发机场': flight.get('departureAirportName', ''),
            '出发航站楼': flight.get('departureTerminal', ''),
            '起飞时间': flight.get('departureDateTime', ''),
            '到达城市': flight.get('arrivalCityName', ''),
            '到达机场': flight.get('arrivalAirportName', ''),
            '到达航站楼': flight.get('arrivalTerminal', ''),
            '到达时间': flight.get('arrivalDateTime', ''),
            '机型': flight.get('aircraftName', ''),
            '机型代码': flight.get('aircraftCode', ''),
        })
        
        # 如果有实际承运航班
        if flight.get('operateAirlineCode') and flight.get('operateAirlineCode') != flight.get('marketAirlineCode'):
            flight_info['实际承运'] = f"{flight.get('operateAirlineName', '')} {flight.get('operateFlightNo', '')}"
    
    return flight_info


def save_results(flights, output_prefix='flights_json_extracted'):
    """保存结果到统一的输出文件"""
    if not flights:
        print("\n✗ 没有数据可保存")
        return
    
    # 保存为CSV
    df = pd.DataFrame(flights)
    csv_file = f'{output_prefix}.csv'
    df.to_csv(csv_file, index=False, encoding='utf-8-sig')
    print(f"\n✓ CSV已保存: {csv_file}")
    
    # 保存为JSON
    json_file = f'{output_prefix}.json'
    with open(json_file, 'w', encoding='utf-8') as f:
        json.dump(flights, f, ensure_ascii=False, indent=2)
    print(f"✓ JSON已保存: {json_file}")
    
    # 尝试保存为Excel
    try:
        excel_file = f'{output_prefix}.xlsx'
        df.to_excel(excel_file, index=False, engine='openpyxl')
        print(f"✓ Excel已保存: {excel_file}")
    except Exception as e:
        print(f"✗ Excel保存失败: {e}")


def display_summary(all_flights):
    """显示汇总信息"""
    print(f"\n{'='*80}")
    print("提取汇总")
    print('='*80)
    
    if not all_flights:
        print("未提取到任何航班数据")
        return
    
    # 统计信息
    df = pd.DataFrame(all_flights)
    
    print(f"总航班数: {len(all_flights)}")
    
    # 按来源文件统计
    if '数据来源' in df.columns:
        print(f"\n按文件统计:")
        source_counts = df['数据来源'].value_counts()
        for source, count in source_counts.items():
            print(f"  {source}: {count} 个航班")
    
    # 按航空公司统计
    if '航空公司' in df.columns:
        print(f"\n按航空公司统计 (前10):")
        airline_counts = df['航空公司'].value_counts().head(10)
        for airline, count in airline_counts.items():
            print(f"  {airline}: {count} 个航班")
    
    # 按出发城市统计
    if '出发城市' in df.columns:
        print(f"\n按出发城市统计:")
        city_counts = df['出发城市'].value_counts()
        for city, count in city_counts.items():
            print(f"  {city}: {count} 个航班")
    
    # 显示前5个航班示例
    print(f"\n{'='*80}")
    print("航班示例 (前5个)")
    print('='*80)
    
    for idx, flight in enumerate(all_flights[:5], 1):
        print(f"\n【航班 {idx}】")
        print("-" * 70)
        # 只显示关键信息
        key_fields = ['航班号', '出发城市', '出发机场', '起飞时间', 
                     '到达城市', '到达机场', '到达时间', '成人价格', '数据来源']
        for key in key_fields:
            if key in flight and flight[key]:
                print(f"  {key:12s}: {flight[key]}")


def main():
    """主函数"""
    print("\n" + "="*80)
    print("携程航班信息批量提取工具".center(70))
    print("="*80)
    
    # 查找所有response文件
    response_files = find_response_files('response*.txt')
    
    if not response_files:
        print("\n✗ 未找到任何response文件")
        print("请确保当前目录下有 response1.txt, response2.txt 等文件")
        return
    
    print(f"\n找到 {len(response_files)} 个response文件:")
    for f in response_files:
        print(f"  - {f}")
    
    # 批量提取所有文件
    all_flights = []
    
    print(f"\n{'='*80}")
    print("开始批量提取")
    print('='*80)
    
    for filename in response_files:
        flights = extract_flights_from_json(filename)
        all_flights.extend(flights)
    
    # 显示汇总
    display_summary(all_flights)
    
    # 保存结果
    if all_flights:
        print(f"\n{'='*80}")
        print("保存结果")
        print('='*80)
        save_results(all_flights, 'flights_json_extracted')
        
        print(f"\n✓ 批量提取完成！")
        print(f"\n生成的文件:")
        print(f"  - flights_json_extracted.csv (CSV格式)")
        print(f"  - flights_json_extracted.json (JSON格式)")
        print(f"  - flights_json_extracted.xlsx (Excel格式，如果可用)")
    else:
        print(f"\n✗ 未提取到任何航班数据")
    
    print("\n" + "="*80 + "\n")


if __name__ == "__main__":
    main()
