# 数据库管理类使用说明

## 概述
DatabaseManager 是一个单例模式的数据库管理类，统一管理整个系统的所有MySQL数据库连接。

## 数据库配置
- 主机: localhost
- 端口: 3306
- 用户名: root
- 密码: 208751

## 支持的数据库
1. **FlightDB** - 航班数据库 (flightdb)
2. **PlaneDB** - 飞机连接数据库 (planedbconn)
3. **PersonCenterDB** - 个人中心数据库 (personcenterdatabase)

## 使用方法

### 1. 获取数据库管理器实例
```cpp
DatabaseManager* dbManager = DatabaseManager::instance();
```

### 2. 获取数据库连接
```cpp
// 获取航班数据库
QSqlDatabase db = dbManager->getDatabase(DatabaseManager::FlightDB);

// 获取用户数据库
QSqlDatabase userDb = dbManager->getDatabase(DatabaseManager::PlaneDB);
```

### 3. 创建查询
```cpp
// 方法1: 直接创建查询
QSqlQuery query = dbManager->createQuery(DatabaseManager::FlightDB);
query.prepare("SELECT * FROM flights WHERE id = ?");
query.addBindValue(flightId);
query.exec();

// 方法2: 使用数据库连接创建查询
QSqlDatabase db = dbManager->getDatabase(DatabaseManager::FlightDB);
QSqlQuery query(db);
```

### 4. 检查连接状态
```cpp
if (dbManager->isDatabaseConnected(DatabaseManager::FlightDB)) {
    // 数据库已连接
}
```

## 示例代码

### 航班查询示例
```cpp
#include "database/databasemanager.h"

void FlightQueryWidget::queryFlights() {
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlQuery query = dbManager->createQuery(DatabaseManager::FlightDB);
    
    query.prepare("SELECT * FROM flights WHERE departure_city = ?");
    query.addBindValue(city);
    
    if (query.exec()) {
        while (query.next()) {
            // 处理查询结果
        }
    }
}
```

### 用户登录示例
```cpp
#include "database/databasemanager.h"

void Widget::login() {
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlQuery query = dbManager->createQuery(DatabaseManager::PlaneDB);
    
    query.prepare("SELECT * FROM uesr_info1 WHERE username = ?");
    query.addBindValue(username);
    
    if (query.exec() && query.next()) {
        // 登录成功
    }
}
```
