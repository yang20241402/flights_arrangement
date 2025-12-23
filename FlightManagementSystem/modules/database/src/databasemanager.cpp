#include "databasemanager.h"
#include <QSqlError>
#include <QMutexLocker>
#include <QDebug>
#include<QString>

// 静态成员初始化
DatabaseManager* DatabaseManager::m_instance = nullptr;
QMutex DatabaseManager::m_mutex;
const QString DatabaseManager::DATABASE_NAME = "flight_management_system";
const QString DatabaseManager::CONNECTION_NAME = "main_connection";

// ==================== 数据库凭据配置 ====================
// 注意: 如需修改数据库连接信息，请修改以下常量
const QString DatabaseManager::DEFAULT_HOST = "localhost";
const int DatabaseManager::DEFAULT_PORT = 3306;
const QString DatabaseManager::DEFAULT_USERNAME = "root";
const QString DatabaseManager::DEFAULT_PASSWORD = "208751";
// ======================================================

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
    , m_isInitialized(false)
{
}

DatabaseManager::~DatabaseManager()
{
    close();
}

DatabaseManager* DatabaseManager::instance()
{
    if (!m_instance) {
        QMutexLocker locker(&m_mutex);
        if (!m_instance) {
            m_instance = new DatabaseManager();
        }
    }
    return m_instance;
}

bool DatabaseManager::initializeWithDefaults()
{
    return initialize(DEFAULT_HOST, DEFAULT_PORT, DEFAULT_USERNAME, DEFAULT_PASSWORD);
}

bool DatabaseManager::initialize(const QString& host,
                                int port,
                                const QString& username,
                                const QString& password)
{
    QMutexLocker locker(&m_mutex);
    
    // 如果已经初始化，先关闭现有连接
    if (m_isInitialized) {
        close();
    }
    
    // 移除可能存在的旧连接
    if (QSqlDatabase::contains(CONNECTION_NAME)) {
        QSqlDatabase::removeDatabase(CONNECTION_NAME);
    }
    
    // 创建新的数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", CONNECTION_NAME);
    
    // 使用直接连接字符串
    QString connectionString = createOdbcConnectionString(host, port, DATABASE_NAME, username, password);
    qDebug() << "Connecting to database:" << host << ":" << port << "as user:" << username;
    
    db.setDatabaseName(connectionString);
    
    // 尝试打开连接
    if (!db.open()) {
        m_lastError = QString("Failed to connect to database: %1").arg(db.lastError().text());
        qCritical() << "DatabaseManager:" << m_lastError;
        QSqlDatabase::removeDatabase(CONNECTION_NAME);
        return false;
    }
    
    // 验证连接
    if (!db.isValid()) {
        m_lastError = "Database connection is not valid";
        qCritical() << "DatabaseManager:" << m_lastError;
        db.close();
        QSqlDatabase::removeDatabase(CONNECTION_NAME);
        return false;
    }
    
    m_isInitialized = true;
    m_lastError.clear();
    
    qInfo() << "DatabaseManager: Successfully connected to database" << DATABASE_NAME 
            << "on" << host << ":" << port << "as user" << username;
    return true;
}

QSqlDatabase DatabaseManager::getDatabase()
{
    if (!m_isInitialized) {
        qWarning() << "DatabaseManager: Database not initialized. Call initialize() first.";
        return QSqlDatabase();
    }
    
    if (!QSqlDatabase::contains(CONNECTION_NAME)) {
        qWarning() << "DatabaseManager: Connection does not exist.";
        return QSqlDatabase();
    }
    
    QSqlDatabase db = QSqlDatabase::database(CONNECTION_NAME);
    
    // 检查连接是否仍然有效
    if (!db.isOpen()) {
        qWarning() << "DatabaseManager: Connection is closed. Attempting to reopen...";
        if (!db.open()) {
            m_lastError = QString("Failed to reopen database connection: %1").arg(db.lastError().text());
            qCritical() << "DatabaseManager:" << m_lastError;
            return QSqlDatabase();
        }
    }
    
    return db;
}

bool DatabaseManager::isConnected() const
{
    if (!m_isInitialized) {
        return false;
    }
    
    if (!QSqlDatabase::contains(CONNECTION_NAME)) {
        return false;
    }
    
    QSqlDatabase db = QSqlDatabase::database(CONNECTION_NAME);
    return db.isOpen() && db.isValid();
}

void DatabaseManager::close()
{
    QMutexLocker locker(&m_mutex);
    
    if (QSqlDatabase::contains(CONNECTION_NAME)) {
        QSqlDatabase db = QSqlDatabase::database(CONNECTION_NAME);
        if (db.isOpen()) {
            db.close();
            qInfo() << "DatabaseManager: Database connection closed";
        }
        QSqlDatabase::removeDatabase(CONNECTION_NAME);
    }
    
    m_isInitialized = false;
    m_lastError.clear();
}

QString DatabaseManager::getLastError() const
{
    return m_lastError;
}

QString DatabaseManager::createOdbcConnectionString(const QString& host,
                                                  int port,
                                                  const QString& database,
                                                  const QString& username,
                                                  const QString& password) const
{
    // 创建标准的 MySQL ODBC 连接字符串
    QString connectionString = QString(
        "DRIVER={MySQL ODBC 8.0 Unicode Driver};"
        "SERVER=%1;"
        "PORT=%2;"
        "DATABASE=%3;"
        "UID=%4;"
        "PWD=%5;"
        "OPTION=3;"
        "CHARSET=utf8mb4;"
    )
    .arg(host)
    .arg(port)
    .arg(database)
    .arg(username)
    .arg(password);
    
    return connectionString;
}
