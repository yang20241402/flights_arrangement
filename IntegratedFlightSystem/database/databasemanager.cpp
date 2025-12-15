#include "databasemanager.h"
#include <QDebug>
#include <QMutexLocker>

// 静态成员初始化
DatabaseManager* DatabaseManager::m_instance = nullptr;
QMutex DatabaseManager::m_mutex;

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
    , m_host("localhost")
    , m_port(3306)
    , m_username("root")
    , m_password("208751")
{
    // 初始化连接名称映射
    m_connectionNames[FlightDB] = "flight_db_connection";
    m_connectionNames[PlaneDB] = "plane_db_connection";
    m_connectionNames[PersonCenterDB] = "person_center_db_connection";
}

DatabaseManager::~DatabaseManager()
{
    closeAllDatabases();
}

DatabaseManager* DatabaseManager::instance()
{
    if (m_instance == nullptr) {
        QMutexLocker locker(&m_mutex);
        if (m_instance == nullptr) {
            m_instance = new DatabaseManager();
        }
    }
    return m_instance;
}

bool DatabaseManager::initializeAllDatabases()
{
    qDebug() << "开始初始化所有数据库连接...";
    
    bool success = true;
    
    // 初始化航班数据库
    if (!initDatabase(FlightDB, "flight_db", m_connectionNames[FlightDB])) {
        qWarning() << "航班数据库初始化失败";
        success = false;
    }
    
    // 初始化飞机连接数据库
    if (!initDatabase(PlaneDB, "plane_db_conn", m_connectionNames[PlaneDB])) {
        qWarning() << "飞机连接数据库初始化失败";
        success = false;
    }
    
    // 初始化个人中心数据库
    if (!initDatabase(PersonCenterDB, "personcenter_database", m_connectionNames[PersonCenterDB])) {
        qWarning() << "个人中心数据库初始化失败";
        success = false;
    }
    
    if (success) {
        qDebug() << "所有数据库连接初始化成功！";
    } else {
        qWarning() << "部分数据库连接初始化失败，请检查配置";
    }
    
    return success;
}

bool DatabaseManager::initDatabase(DatabaseType type, const QString& dbName, const QString& connName)
{
    // 如果连接已存在，先移除
    if (QSqlDatabase::contains(connName)) {
        {
            QSqlDatabase oldDb = QSqlDatabase::database(connName, false);
        }
        QSqlDatabase::removeDatabase(connName);
    }

    
    // 创建新的数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connName);
    setupDatabaseConnection(db, dbName);
    
    // 尝试打开数据库
    if (!db.open()) {
        m_lastError = QString("无法连接到数据库 %1: %2")
                          .arg(dbName)
                          .arg(db.lastError().text());
        qCritical() << m_lastError;
        return false;
    }
    
    // // 设置字符集为 UTF-8
    // QSqlQuery query(db);
    // query.exec("SET NAMES utf8mb4");
    // query.exec("SET CHARACTER SET utf8mb4");
    // query.exec("SET character_set_connection=utf8mb4");
    
    qDebug() << QString("数据库 %1 连接成功 (连接名: %2)").arg(dbName).arg(connName);
    return true;
}

void DatabaseManager::setupDatabaseConnection(QSqlDatabase& db, const QString& dbName)
{
    QString dsn = QString(
                      "Driver={MySQL ODBC 8.0 Unicode Driver};"
                      "Server=%1;"
                      "Database=%2;"
                      "User=%3;"
                      "Password=%4;"
                      "Port=%5;"
                      "Option=3;"
                      "Charset=utf8mb4;"
                      )
                      .arg(m_host)
                      .arg(dbName)
                      .arg(m_username)
                      .arg(m_password)
                      .arg(m_port);

    db.setDatabaseName(dsn);
}


QSqlDatabase DatabaseManager::getDatabase(DatabaseType type)
{
    QString connName = m_connectionNames.value(type);
    
    if (!QSqlDatabase::contains(connName)) {
        m_lastError = QString("数据库连接 %1 不存在").arg(connName);
        qWarning() << m_lastError;
        return QSqlDatabase();
    }
    
    QSqlDatabase db = QSqlDatabase::database(connName);
    
    // 检查连接是否有效，如果无效则尝试重新连接
    if (!db.isOpen()) {
        qWarning() << "数据库连接已断开，尝试重新连接...";
        if (!db.open()) {
            m_lastError = QString("重新连接数据库失败: %1").arg(db.lastError().text());
            qCritical() << m_lastError;
        }
    }
    
    return db;
}

QString DatabaseManager::getConnectionName(DatabaseType type)
{
    return m_connectionNames.value(type);
}

QSqlQuery DatabaseManager::createQuery(DatabaseType type)
{
    QSqlDatabase db = getDatabase(type);
    return QSqlQuery(db);
}

bool DatabaseManager::isDatabaseConnected(DatabaseType type)
{
    QString connName = m_connectionNames.value(type);
    
    if (!QSqlDatabase::contains(connName)) {
        return false;
    }
    
    QSqlDatabase db = QSqlDatabase::database(connName);
    return db.isOpen() && db.isValid();
}

void DatabaseManager::closeAllDatabases()
{
    qDebug() << "关闭所有数据库连接...";
    
    for (auto it = m_connectionNames.begin(); it != m_connectionNames.end(); ++it) {
        QString connName = it.value();
        if (QSqlDatabase::contains(connName)) {
            QSqlDatabase db = QSqlDatabase::database(connName);
            if (db.isOpen()) {
                db.close();
                qDebug() << QString("数据库连接 %1 已关闭").arg(connName);
            }
            QSqlDatabase::removeDatabase(connName);
        }
    }
}

QString DatabaseManager::getLastError() const
{
    return m_lastError;
}
