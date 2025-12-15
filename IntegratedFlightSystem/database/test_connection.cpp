// 数据库连接测试程序
// 编译方式: 将此文件临时添加到CMakeLists.txt中，或单独编译测试

#include "databasemanager.h"
#include <QCoreApplication>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

void testDatabaseConnection()
{
    qDebug() << "=== 开始测试数据库连接 ===\n";
    
    DatabaseManager* dbManager = DatabaseManager::instance();
    
    // 初始化所有数据库
    if (!dbManager->initializeAllDatabases()) {
        qCritical() << "数据库初始化失败:" << dbManager->getLastError();
        return;
    }
    
    qDebug() << "✓ 数据库初始化成功\n";
    
    // 测试航班数据库
    qDebug() << "--- 测试航班数据库 (flightdb) ---";
    if (dbManager->isDatabaseConnected(DatabaseManager::FlightDB)) {
        QSqlQuery query = dbManager->createQuery(DatabaseManager::FlightDB);
        if (query.exec("SELECT COUNT(*) FROM flights")) {
            query.next();
            qDebug() << "✓ 航班数据库连接成功";
            qDebug() << "  航班总数:" << query.value(0).toInt();
        } else {
            qWarning() << "✗ 查询失败:" << query.lastError().text();
        }
    } else {
        qWarning() << "✗ 航班数据库未连接";
    }
    
    // 测试用户数据库
    qDebug() << "\n--- 测试用户数据库 (planedbconn) ---";
    if (dbManager->isDatabaseConnected(DatabaseManager::PlaneDB)) {
        QSqlQuery query = dbManager->createQuery(DatabaseManager::PlaneDB);
        if (query.exec("SELECT COUNT(*) FROM uesr_info1")) {
            query.next();
            qDebug() << "✓ 用户数据库连接成功";
            qDebug() << "  用户总数:" << query.value(0).toInt();
        } else {
            qWarning() << "✗ 查询失败:" << query.lastError().text();
        }
    } else {
        qWarning() << "✗ 用户数据库未连接";
    }
    
    // 测试个人中心数据库
    qDebug() << "\n--- 测试个人中心数据库 (personcenterdatabase) ---";
    if (dbManager->isDatabaseConnected(DatabaseManager::PersonCenterDB)) {
        QSqlQuery query = dbManager->createQuery(DatabaseManager::PersonCenterDB);
        if (query.exec("SHOW TABLES")) {
            qDebug() << "✓ 个人中心数据库连接成功";
            qDebug() << "  数据表列表:";
            while (query.next()) {
                qDebug() << "    -" << query.value(0).toString();
            }
        } else {
            qWarning() << "✗ 查询失败:" << query.lastError().text();
        }
    } else {
        qWarning() << "✗ 个人中心数据库未连接";
    }
    
    qDebug() << "\n=== 测试完成 ===";
}

// 如果要单独运行此测试，取消下面的注释
/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    testDatabaseConnection();
    return 0;
}
*/
