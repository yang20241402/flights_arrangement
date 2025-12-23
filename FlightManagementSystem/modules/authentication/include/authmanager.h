#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>

class AuthManager : public QObject
{
    Q_OBJECT

public:
    explicit AuthManager(QObject *parent = nullptr);
    
    // 用户登录
    bool login(const QString &username, const QString &password);
    
    // 用户注册
    bool registerUser(const QString &username, const QString &password);
    
    // 用户登出
    void logout();

signals:
    void loginSuccessful();
    void loginFailed();
    void registrationSuccessful();
    void registrationFailed();

private:
    bool m_isLoggedIn = false;
};

#endif // AUTHMANAGER_H