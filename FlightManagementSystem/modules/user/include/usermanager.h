#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>

class UserManager : public QObject
{
    Q_OBJECT

public:
    explicit UserManager(QObject *parent = nullptr);
    
    // 获取用户信息
    void loadUserProfile(int userId);
    
    // 更新用户信息
    bool updateUserProfile(int userId, const QString &name, const QString &email);

signals:
    void userProfileLoaded();
    void userProfileUpdated();

private:
    // TODO: 添加私有成员变量
};

#endif // USERMANAGER_H