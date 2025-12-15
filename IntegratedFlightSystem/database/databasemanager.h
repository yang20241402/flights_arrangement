#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QMutex>

/**
 * @brief 数据库管理类 - 单例模式
 * 统一管理所有数据库连接，支持多个数据库
 */
class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    // 数据库类型枚举
    enum DatabaseType {
        FlightDB,           // 航班数据库 (flightdb)
        PlaneDB,            // 飞机连接数据库 (planedbconn)
        PersonCenterDB      // 个人中心数据库 (personcenterdatabase)
    };

    // 获取单例实例
    static DatabaseManager* instance();
    
    // 初始化所有数据库连接
    bool initializeAllDatabases();
    
    // 获取指定类型的数据库连接
    QSqlDatabase getDatabase(DatabaseType type);
    
    // 获取指定类型的数据库连接名称
    QString getConnectionName(DatabaseType type);
    
    // 创建查询对象
    QSqlQuery createQuery(DatabaseType type);
    
    // 检查数据库连接是否有效
    bool isDatabaseConnected(DatabaseType type);
    
    // 关闭所有数据库连接
    void closeAllDatabases();
    
    // 获取最后的错误信息
    QString getLastError() const;

private:
    // 私有构造函数（单例模式）
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();
    
    // 禁止拷贝和赋值
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    
    // 初始化单个数据库
    bool initDatabase(DatabaseType type, const QString& dbName, const QString& connName);
    
    // 设置数据库连接参数
    void setupDatabaseConnection(QSqlDatabase& db, const QString& dbName);

private:
    static DatabaseManager* m_instance;
    static QMutex m_mutex;
    
    // 数据库连接配置
    QString m_host;
    int m_port;
    QString m_username;
    QString m_password;
    
    // 连接名称映射
    QMap<DatabaseType, QString> m_connectionNames;
    
    // 最后的错误信息
    QString m_lastError;
};

#endif // DATABASEMANAGER_H
