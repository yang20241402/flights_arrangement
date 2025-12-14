# 快速开始指南

## 1. 环境准备

### 必需软件
- Qt 5.15+ 或 Qt 6.x
- Qt Creator (推荐) 或其他C++编译器
- MySQL 数据库
- ODBC驱动

## 2. 数据库配置

### 导入数据库
```bash
mysql -u root -p < ../flight_db_20251201.sql
```

### 配置ODBC数据源 (Windows)
1. 打开"ODBC数据源管理器"
2. 添加MySQL ODBC驱动
3. 配置连接参数：
   - 数据源名称: flight_db
   - 服务器: localhost
   - 数据库: flight_db
   - 用户名: root
   - 密码: (你的密码)

## 3. 编译项目

### 方法1: 使用Qt Creator (推荐)
1. 打开Qt Creator
2. 文件 -> 打开文件或项目
3. 选择 `IntegratedFlightSystem.pro`
4. 配置Kit (选择Qt版本)
5. 点击左下角的"运行"按钮 (绿色三角形)

### 方法2: 使用qmake命令行
```bash
cd IntegratedFlightSystem
qmake IntegratedFlightSystem.pro
make
./IntegratedFlightSystem
```

### 方法3: 使用CMake
```bash
cd IntegratedFlightSystem
mkdir build
cd build
cmake ..
cmake --build .
```

## 4. 运行程序

程序启动后会显示登录界面，包含以下功能：

### 登录模块
- 用户登录
- 新用户注册
- 忘记密码

### 航班查询模块
- 查询航班信息
- 查看航班详情
- 显示所有航班

### 个人中心模块
- 我的订单
- 常用旅客管理
- 积分查询

## 5. 常见问题

### Q: 编译时找不到头文件
A: 确保在.pro文件中添加了正确的INCLUDEPATH

### Q: 数据库连接失败
A: 检查ODBC配置和数据库服务是否启动

### Q: 资源文件加载失败
A: 确保resources.qrc文件路径正确，图片文件存在

### Q: UI文件无法加载
A: 运行qmake重新生成ui_*.h文件

## 6. 项目结构说明

```
IntegratedFlightSystem/
├── login/      # 登录、注册、密码找回
├── flight/     # 航班查询和详情
├── person/     # 个人中心功能
└── resources/  # 图片和资源文件
```

## 7. 开发建议

- 修改UI后需要重新运行qmake
- 添加新文件后需要更新.pro文件
- 数据库连接字符串在各模块的initDB()函数中
- 建议使用Qt Creator的调试功能排查问题
