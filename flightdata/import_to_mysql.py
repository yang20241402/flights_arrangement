"""
将航班数据导入MySQL数据库，每1000条数据创建一个新表
"""

import pandas as pd
import pymysql
from datetime import datetime
import sys


class FlightDataImporter:
    def __init__(self, host='localhost', user='root', password='', database='flight_db', batch_size=1000):
        """初始化数据库连接"""
        self.host = host
        self.user = user
        self.password = password
        self.database = database
        self.batch_size = batch_size  # 每批数据的大小
        self.connection = None
        self.current_table_index = 1  # 当前表序号
        self.current_batch_count = 0  # 当前批次计数

    def connect(self):
        """连接数据库"""
        try:
            # 先连接到MySQL服务器
            self.connection = pymysql.connect(
                host=self.host,
                user=self.user,
                password=self.password,
                charset='utf8mb4',
                cursorclass=pymysql.cursors.DictCursor
            )
            print(f"✓ 成功连接到MySQL服务器")

            # 创建数据库（如果不存在）
            with self.connection.cursor() as cursor:
                cursor.execute(f"CREATE DATABASE IF NOT EXISTS {self.database} CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci")
                cursor.execute(f"USE {self.database}")
            self.connection.commit()
            print(f"✓ 数据库 '{self.database}' 已准备就绪")

        except Exception as e:
            print(f"✗ 数据库连接失败: {e}")
            sys.exit(1)

    def create_table(self, table_suffix=None):
        """创建航班表，支持表名后缀"""
        table_name = self._get_table_name(table_suffix)

        create_table_sql = f"""
        CREATE TABLE IF NOT EXISTS {table_name} (
            id INT AUTO_INCREMENT PRIMARY KEY,
            航段序号 INT,
            航空公司代码 VARCHAR(10),
            航空公司 VARCHAR(50),
            飞行时长 VARCHAR(20),
            航班号 VARCHAR(20),
            出发城市 VARCHAR(50),
            出发机场 VARCHAR(100),
            出发航站楼 VARCHAR(10),
            起飞时间 DATETIME,
            到达城市 VARCHAR(50),
            到达机场 VARCHAR(100),
            到达航站楼 VARCHAR(10),
            到达时间 DATETIME,
            机型 VARCHAR(50),
            机型代码 VARCHAR(10),
            实际承运 VARCHAR(100),
            成人价格 VARCHAR(20),
            儿童价格 VARCHAR(20),
            数据来源 VARCHAR(100),
            创建时间 TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            INDEX idx_flight_no (航班号),
            INDEX idx_depart_city (出发城市),
            INDEX idx_arrive_city (到达城市),
            INDEX idx_depart_time (起飞时间),
            INDEX idx_airline (航空公司)
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
        """

        try:
            with self.connection.cursor() as cursor:
                cursor.execute(create_table_sql)
            self.connection.commit()
            print(f"✓ 航班表 '{table_name}' 创建成功")
        except Exception as e:
            print(f"✗ 创建表失败: {e}")
            sys.exit(1)

    def _get_table_name(self, table_suffix=None):
        """获取表名"""
        if table_suffix is None:
            table_suffix = self.current_table_index
        return f"flights_batch_{table_suffix:03d}"

    def _should_create_new_table(self):
        """判断是否需要创建新表"""
        return self.current_batch_count >= self.batch_size

    def _reset_batch_counter(self):
        """重置批次计数器"""
        self.current_batch_count = 0
        self.current_table_index += 1

    def import_csv(self, csv_file='flights_json_extracted.csv'):
        """导入CSV数据，每1000条数据创建一个新表"""
        try:
            # 读取CSV
            df = pd.read_csv(csv_file, encoding='utf-8-sig')
            print(f"✓ 读取CSV文件: {len(df)} 条记录")
            print(f"✓ 每 {self.batch_size} 条数据创建一个新表")

            # 删除所有已存在的批次表（可选）
            self._cleanup_existing_tables()

            # 创建第一个表
            self.create_table(self.current_table_index)

            # 准备插入语句
            insert_sql_template = """
            INSERT INTO {} (
                航段序号, 航空公司代码, 航空公司, 飞行时长, 航班号,
                出发城市, 出发机场, 出发航站楼, 起飞时间,
                到达城市, 到达机场, 到达航站楼, 到达时间,
                机型, 机型代码, 实际承运, 成人价格, 儿童价格, 数据来源
            ) VALUES (
                %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s
            )
            """

            success_count = 0
            error_count = 0
            total_records = len(df)

            with self.connection.cursor() as cursor:
                for index, row in df.iterrows():
                    try:
                        # 检查是否需要创建新表
                        if self._should_create_new_table():
                            self._reset_batch_counter()
                            self.create_table(self.current_table_index)

                        # 处理日期时间
                        depart_time = pd.to_datetime(row['起飞时间']) if pd.notna(row['起飞时间']) else None
                        arrive_time = pd.to_datetime(row['到达时间']) if pd.notna(row['到达时间']) else None

                        values = (
                            int(row['航段序号']) if pd.notna(row['航段序号']) else None,
                            str(row['航空公司代码']) if pd.notna(row['航空公司代码']) else '',
                            str(row['航空公司']) if pd.notna(row['航空公司']) else '',
                            str(row['飞行时长']) if pd.notna(row['飞行时长']) else '',
                            str(row['航班号']) if pd.notna(row['航班号']) else '',
                            str(row['出发城市']) if pd.notna(row['出发城市']) else '',
                            str(row['出发机场']) if pd.notna(row['出发机场']) else '',
                            str(row['出发航站楼']) if pd.notna(row['出发航站楼']) else '',
                            depart_time,
                            str(row['到达城市']) if pd.notna(row['到达城市']) else '',
                            str(row['到达机场']) if pd.notna(row['到达机场']) else '',
                            str(row['到达航站楼']) if pd.notna(row['到达航站楼']) else '',
                            arrive_time,
                            str(row['机型']) if pd.notna(row['机型']) else '',
                            str(row['机型代码']) if pd.notna(row['机型代码']) else '',
                            str(row['实际承运']) if pd.notna(row['实际承运']) else '',
                            str(row['成人价格']) if pd.notna(row['成人价格']) else '',
                            str(row['儿童价格']) if pd.notna(row['儿童价格']) else '',
                            str(row['数据来源']) if pd.notna(row['数据来源']) else ''
                        )

                        current_table_name = self._get_table_name()
                        insert_sql = insert_sql_template.format(current_table_name)
                        cursor.execute(insert_sql, values)

                        success_count += 1
                        self.current_batch_count += 1

                        # 每100条提交一次，减少数据库压力
                        if (index + 1) % 100 == 0:
                            self.connection.commit()
                            progress = (index + 1) / total_records * 100
                            current_table = self._get_table_name()
                            print(f"  进度: {index + 1}/{total_records} ({progress:.1f}%) - 当前表: {current_table}")

                    except Exception as e:
                        error_count += 1
                        print(f"  ✗ 第 {index + 1} 行导入失败: {e}")

                self.connection.commit()

            print(f"\n✓ 导入完成!")
            print(f"  成功: {success_count} 条")
            print(f"  失败: {error_count} 条")
            print(f"  共创建了 {self.current_table_index} 个表")

        except Exception as e:
            print(f"✗ 导入CSV失败: {e}")
            import traceback
            traceback.print_exc()

    def _cleanup_existing_tables(self):
        """清理已存在的批次表"""
        try:
            with self.connection.cursor() as cursor:
                # 获取所有表名
                cursor.execute("SHOW TABLES LIKE 'flights_batch_%'")
                existing_tables = [list(table.values())[0] for table in cursor.fetchall()]

                if existing_tables:
                    print(f"  发现 {len(existing_tables)} 个已存在的批次表，正在清理...")
                    for table in existing_tables:
                        cursor.execute(f"DROP TABLE {table}")
                    self.connection.commit()
                    print(f"  ✓ 已清理 {len(existing_tables)} 个旧表")

        except Exception as e:
            print(f"✗ 清理旧表失败: {e}")

    def show_statistics(self):
        """显示所有表的统计信息"""
        try:
            with self.connection.cursor() as cursor:
                # 获取所有批次表
                cursor.execute("SHOW TABLES LIKE 'flights_batch_%'")
                batch_tables = [list(table.values())[0] for table in cursor.fetchall()]

                if not batch_tables:
                    print("没有找到批次表")
                    return

                print(f"\n数据库统计 (共 {len(batch_tables)} 个表):")

                total_records = 0
                table_stats = []

                for table in sorted(batch_tables):
                    cursor.execute(f"SELECT COUNT(*) as count FROM {table}")
                    count = cursor.fetchone()['count']
                    total_records += count
                    table_stats.append((table, count))

                print(f"  总记录数: {total_records}")

                # 显示每个表的记录数
                print(f"\n  各表记录分布:")
                for table, count in table_stats:
                    print(f"    {table}: {count} 条记录")

                # 按航空公司统计（从第一个表取样）
                if table_stats:
                    sample_table = table_stats[0][0]
                    cursor.execute(f"""
                        SELECT 航空公司, COUNT(*) as count 
                        FROM {sample_table} 
                        GROUP BY 航空公司 
                        ORDER BY count DESC 
                        LIMIT 5
                    """)
                    print(f"\n  航空公司TOP5 (取样):")
                    for row in cursor.fetchall():
                        print(f"    {row['航空公司']}: {row['count']} 个航班")

        except Exception as e:
            print(f"✗ 统计信息获取失败: {e}")

    def get_all_tables(self):
        """获取所有批次表名"""
        try:
            with self.connection.cursor() as cursor:
                cursor.execute("SHOW TABLES LIKE 'flights_batch_%'")
                return [list(table.values())[0] for table in cursor.fetchall()]
        except Exception as e:
            print(f"✗ 获取表列表失败: {e}")
            return []

    def close(self):
        """关闭连接"""
        if self.connection:
            self.connection.close()
            print("\n✓ 数据库连接已关闭")


def main():
    """主函数"""
    print("\n" + "="*80)
    print("航班数据分表导入MySQL".center(70))
    print("="*80 + "\n")

    # 数据库配置（请根据实际情况修改）
    DB_CONFIG = {
        'host': 'localhost',
        'user': 'root',
        'password': '208751',  # 请填写你的MySQL密码
        'database': 'flight_db',
        'batch_size': 1000     # 每1000条数据创建一个新表
    }

    print("数据库配置:")
    print(f"  主机: {DB_CONFIG['host']}")
    print(f"  用户: {DB_CONFIG['user']}")
    print(f"  数据库: {DB_CONFIG['database']}")
    print(f"  批次大小: {DB_CONFIG['batch_size']} 条/表")
    print()

    # 创建导入器
    importer = FlightDataImporter(**DB_CONFIG)

    try:
        # 连接数据库
        importer.connect()

        # 导入数据（会自动创建表）
        importer.import_csv('flightdata.csv')

        # 显示统计
        importer.show_statistics()

        # 显示所有表
        tables = importer.get_all_tables()
        if tables:
            print(f"\n  创建的表列表:")
            for table in sorted(tables):
                print(f"    - {table}")

    except KeyboardInterrupt:
        print("\n\n✗ 用户中断")
    except Exception as e:
        print(f"\n✗ 程序执行出错: {e}")
        import traceback
        traceback.print_exc()
    finally:
        importer.close()

    print("\n" + "="*80)
    print("分表导入完成")
    print("="*80 + "\n")


if __name__ == "__main__":
    main()