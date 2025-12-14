# 航班管理系统 - 整合版

这是一个整合了登录、航班查询和个人中心功能的Qt应用程序。

## 项目结构

```
IntegratedFlightSystem/
├── main.cpp                    # 主程序入口
├── IntegratedFlightSystem.pro  # Qt项目配置文件
├── login/                      # 登录模块 (来自文件夹1)
│   ├── widget.cpp/h/ui        # 登录主界面
│   ├── mainwindow.cpp/h/ui    # 主窗口
│   ├── form.cpp/h/ui          # 注册表单
│   ├── formpwd.cpp/h/ui       # 密码找回表单
│   └── ClickableLabel.cpp/h   # 可点击标签组件
├── flight/                     # 航班查询模块 (来自flightdetail)
│   ├── flightquerywidget.cpp/h/ui    # 航班查询界面
│   └── flightdetailwidget.cpp/h/ui   # 航班详情界面
├── person/                     # 个人中心模块 (来自PersonCenter)
│   ├── personcenterwindow.cpp/h/ui   # 个人中心主窗口
│   ├── myorderdialog.cpp/h/ui        # 我的订单
│   ├── passengerdialog.cpp/h/ui      # 常用旅客
│   └── pointsdialog.cpp/h/ui         # 积分管理
└── resources/                  # 资源文件
    ├── images/                 # 图片资源
    ├── avatar.png             # 头像
    └── resources.qrc          # Qt资源文件

```

## 功能模块

### 1. 登录模块 (login/)
- 用户登录
- 用户注册
- 密码找回
- 浅色主题UI

### 2. 航班查询模块 (flight/)
- 航班查询
- 航班详情查看
- 数据库连接

### 3. 个人中心模块 (person/)
- 我的订单管理
- 常用旅客信息
- 积分查询

## 编译说明

### 使用Qt Creator
1. 打开 `IntegratedFlightSystem.pro`
2. 配置Qt Kit (Qt 5.x 或 Qt 6.x)
3. 点击构建按钮

### 使用命令行
```bash
qmake IntegratedFlightSystem.pro
make
```

## 依赖项
- Qt Core
- Qt Widgets
- Qt SQL
- Qt Network
- ODBC驱动

## 数据库配置
项目使用SQL数据库，需要配置ODBC连接。请确保：
1. 安装MySQL或其他数据库
2. 配置ODBC数据源
3. 导入数据库脚本 (flight_db_20251201.sql)

## 注意事项
- 确保所有模块的数据库连接配置一致
- 资源文件路径已更新到 resources/ 目录
- PersonCenter的MainWindow已重命名为PersonCenterWindow避免冲突
