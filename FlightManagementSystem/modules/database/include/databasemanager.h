#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QMutex>
#include <QString>
/**
 * @brief 数据库管理器 - 单例模式
 * 
 * 负责管理与 MySQL 数据库的连接，使用 ODBC 驱动
 * 数据库名称: flight_management_system
 * 连接名称: main_connection
 */
class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief 获取单例实例
     * @return DatabaseManager 实例指针
     */
    static DatabaseManager* instance();
    
    /**
     * @brief 使用默认配置初始化数据库连接
     * 使用预设的数据库凭据 (root/208751)
     * @return 连接是否成功
     */
    bool initializeWithDefaults();
    
    /**
     * @brief 初始化数据库连接
     * @param host 数据库主机地址 (默认: localhost)
     * @param port 数据库端口 (默认: 3306)
     * @param username 用户名 (默认: root)
     * @param password 密码 (默认: 208751)
     * @return 连接是否成功
     */
    bool initialize(const QString& host = "localhost",
                   int port = 3306,
                   const QString& username = "root",
                   const QString& password = "208751");
    
    /**
     * @brief 获取数据库连接对象
     * @return QSqlDatabase 连接对象
     */
    QSqlDatabase getDatabase();
    
    /**
     * @brief 检查数据库连接是否有效
     * @return 连接是否有效
     */
    bool isConnected() const;
    
    /**
     * @brief 关闭数据库连接
     */
    void close();
    
    /**
     * @brief 获取最后的错误信息
     * @return 错误信息字符串
     */
    QString getLastError() const;

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();
    
    // 禁止拷贝和赋值
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    
    /**
     * @brief 创建ODBC连接字符串
     * @param host 主机地址
     * @param port 端口
     * @param database 数据库名
     * @param username 用户名
     * @param password 密码
     * @return ODBC连接字符串
     */
    QString createOdbcConnectionString(const QString& host,
                                     int port,
                                     const QString& database,
                                     const QString& username,
                                     const QString& password) const;

private:
    static DatabaseManager* m_instance;
    static QMutex m_mutex;
    
    // 数据库连接配置
    static const QString DATABASE_NAME;
    static const QString CONNECTION_NAME;
    
    // ==================== 数据库凭据配置 ====================
    // 注意: 如需修改数据库连接信息，请修改以下常量
    static const QString DEFAULT_HOST;
    static const int DEFAULT_PORT;
    static const QString DEFAULT_USERNAME;
    static const QString DEFAULT_PASSWORD;
    // ======================================================
    
    // 连接状态
    bool m_isInitialized;
    QString m_lastError;
};

#endif // DATABASEMANAGER_H
