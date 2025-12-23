#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QStackedWidget>
#include <QWidget>
#include <QVariantMap>

// 前向声明
class LoginWidget;
class RegisterWidget;
class PasswordResetWidget;
class PersonCenterWindow;
class FlightDetailWidget;
class FlightSearchWidget;
class ChangeTicketWidget;

/**
 * @brief 简单的界面管理器
 * 
 * 负责管理主要界面的切换和参数传递
 * 使用QStackedWidget实现界面切换
 */
class ViewManager : public QObject
{
    Q_OBJECT

public:
    explicit ViewManager(QStackedWidget* stackedWidget, QObject *parent = nullptr);
    ~ViewManager();

    // 界面标识
    enum ViewType {
        LoginView = 0,
        RegisterView = 1,
        PasswordResetView = 2,
        UserCenterView = 3,
        FlightSearchView = 4  // 航班搜索界面
    };

    // 初始化所有界面
    void initializeViews();
    
    // 显示指定界面
    void showView(ViewType viewType, const QVariantMap& params = QVariantMap());
    
    // 获取当前界面类型
    ViewType currentView() const;
    
    // 设置当前用户ID（用于需要用户信息的界面）
    void setCurrentUserId(int userId);
    int getCurrentUserId() const;

public slots:
    // 界面跳转槽函数
    void showLoginView();
    void showRegisterView();
    void showPasswordResetView();
    void showUserCenterView();
    void showMainView();
    
    // 处理登录成功
    void onLoginSuccessful(int userId);
    void onAdminLoginSuccessful();
    
    // 处理注册和密码重置完成
    void onRegistrationCompleted();
    void onPasswordResetCompleted();
    
    // 处理改签页面打开
    void onOpenChangeTicketPage(const QString& departCity, const QString& arriveCity, 
                               const QString& flightNo, const QDate& flightDate);

signals:
    // 界面切换信号
    void viewChanged(ViewType from, ViewType to);
    
    // 用户状态变化信号
    void userLoggedIn(int userId);
    void userLoggedOut();

private:
    void connectViewSignals();
    void setupViewStyles();
    
private:
    QStackedWidget* m_stackedWidget;
    
    // 界面实例
    LoginWidget* m_loginWidget;
    RegisterWidget* m_registerWidget;
    PasswordResetWidget* m_passwordResetWidget;
    PersonCenterWindow* m_userCenterWidget;
    FlightSearchWidget* m_flightSearchWidget;  // 航班搜索界面
    
    // 当前状态
    ViewType m_currentViewType;
    int m_currentUserId;
};

#endif // VIEWMANAGER_H