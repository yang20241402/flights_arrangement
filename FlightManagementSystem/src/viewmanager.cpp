#include "viewmanager.h"
#include "loginwidget.h"
#include "registerwidget.h"
#include "passwordresetwidget.h"
#include "personcenterwindow.h"
#include "flightsearchwidget.h"
#include "changeticketwidget.h"
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>

ViewManager::ViewManager(QStackedWidget* stackedWidget, QObject *parent)
    : QObject(parent)
    , m_stackedWidget(stackedWidget)
    , m_loginWidget(nullptr)
    , m_registerWidget(nullptr)
    , m_passwordResetWidget(nullptr)
    , m_userCenterWidget(nullptr)
    , m_flightSearchWidget(nullptr)
    , m_currentViewType(LoginView)
    , m_currentUserId(-1)
{
    if (!m_stackedWidget) {
        qWarning() << "ViewManager: stackedWidget is null!";
        return;
    }
    
    initializeViews();
    connectViewSignals();
    setupViewStyles();
}

ViewManager::~ViewManager()
{
    // QStackedWidget会自动管理子widget的内存
}

void ViewManager::initializeViews()
{
    // 创建登录界面
    m_loginWidget = new LoginWidget();
    m_stackedWidget->addWidget(m_loginWidget);  // index 0
    
    // 创建注册界面
    m_registerWidget = new RegisterWidget();
    m_stackedWidget->addWidget(m_registerWidget);  // index 1
    
    // 创建密码重置界面
    m_passwordResetWidget = new PasswordResetWidget();
    m_stackedWidget->addWidget(m_passwordResetWidget);  // index 2
    
    // 创建用户中心界面
    m_userCenterWidget = new PersonCenterWindow();
    m_stackedWidget->addWidget(m_userCenterWidget);  // index 3
    
    // 创建航班搜索界面
    m_flightSearchWidget = new FlightSearchWidget();
    m_stackedWidget->addWidget(m_flightSearchWidget);  // index 4
    
    // 默认显示登录界面
    m_stackedWidget->setCurrentIndex(LoginView);
    m_currentViewType = LoginView;
}

void ViewManager::connectViewSignals()
{
    // 连接登录界面信号
    if (m_loginWidget) {
        connect(m_loginWidget, &LoginWidget::loginSuccessful, 
                this, &ViewManager::onLoginSuccessful);
        connect(m_loginWidget, &LoginWidget::adminLoginSuccessful, 
                this, &ViewManager::onAdminLoginSuccessful);
        connect(m_loginWidget, &LoginWidget::registerRequested, 
                this, &ViewManager::showRegisterView);
        connect(m_loginWidget, &LoginWidget::passwordResetRequested, 
                this, &ViewManager::showPasswordResetView);
    }
    
    // 连接注册界面信号
    if (m_registerWidget) {
        connect(m_registerWidget, &RegisterWidget::registrationCompleted, 
                this, &ViewManager::onRegistrationCompleted);
        connect(m_registerWidget, &RegisterWidget::backToLoginRequested, 
                this, &ViewManager::showLoginView);
    }
    
    // 连接密码重置界面信号
    if (m_passwordResetWidget) {
        connect(m_passwordResetWidget, &PasswordResetWidget::passwordResetCompleted, 
                this, &ViewManager::onPasswordResetCompleted);
        connect(m_passwordResetWidget, &PasswordResetWidget::backToLoginRequested, 
                this, &ViewManager::showLoginView);
    }
}

void ViewManager::setupViewStyles()
{
    // 设置整体样式
    if (m_stackedWidget) {
        m_stackedWidget->setStyleSheet(R"(
            QStackedWidget {
                background-color: #ffffff;
                border: none;
            }
        )");
    }
}

void ViewManager::showView(ViewType viewType, const QVariantMap& params)
{
    if (!m_stackedWidget) {
        qWarning() << "ViewManager: stackedWidget is null!";
        return;
    }
    
    ViewType previousView = m_currentViewType;
    
    // 根据参数更新界面
    switch (viewType) {
    case UserCenterView:
        if (m_currentUserId > 0 && m_userCenterWidget) {
            // 设置用户中心的用户ID
            m_userCenterWidget->setUserId(m_currentUserId);
        }
        break;
    case FlightSearchView:
        if (m_currentUserId > 0 && m_flightSearchWidget) {
            // 设置航班搜索界面的用户ID
            m_flightSearchWidget->setUserId(m_currentUserId);
        }
        break;
    default:
        break;
    }
    
    // 根据界面类型调整主窗口大小
    QMainWindow* mainWindow = qobject_cast<QMainWindow*>(m_stackedWidget->window());
    if (mainWindow) {
        switch (viewType) {
        case LoginView:
        case RegisterView:
        case PasswordResetView:
            // 登录相关界面使用固定大小
            mainWindow->resize(920, 551);
            mainWindow->setMinimumSize(920, 551);
            mainWindow->setMaximumSize(920, 551);
            m_stackedWidget->setGeometry(0, 0, 920, 551);
            break;
        case UserCenterView:
        case FlightSearchView:
            // 其他界面使用较大尺寸
            mainWindow->resize(1200, 800);
            mainWindow->setMinimumSize(800, 600);
            mainWindow->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
            m_stackedWidget->setGeometry(0, 0, 1200, 800);
            break;
        }
    }
    
    // 切换界面
    m_stackedWidget->setCurrentIndex(static_cast<int>(viewType));
    m_currentViewType = viewType;
    
    // 发出界面切换信号
    emit viewChanged(previousView, viewType);
    
    qDebug() << "ViewManager: switched from" << previousView << "to" << viewType;
}

ViewManager::ViewType ViewManager::currentView() const
{
    return m_currentViewType;
}

void ViewManager::setCurrentUserId(int userId)
{
    m_currentUserId = userId;
    qDebug() << "ViewManager: current user ID set to" << userId;
}

int ViewManager::getCurrentUserId() const
{
    return m_currentUserId;
}

// 界面跳转槽函数实现
void ViewManager::showLoginView()
{
    showView(LoginView);
}

void ViewManager::showRegisterView()
{
    showView(RegisterView);
}

void ViewManager::showPasswordResetView()
{
    showView(PasswordResetView);
}

void ViewManager::showUserCenterView()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(nullptr, "提示", "请先登录");
        showView(LoginView);
        return;
    }
    showView(UserCenterView);
}

void ViewManager::showMainView()
{
    showView(FlightSearchView);
}

// 处理登录成功
void ViewManager::onLoginSuccessful(int userId)
{
    qDebug() << "ViewManager: 用户登录成功，用户ID：" << userId;
    
    // 设置当前用户ID
    setCurrentUserId(userId);
    
    emit userLoggedIn(m_currentUserId);
    
    // 登录成功后跳转到航班搜索界面
    showView(FlightSearchView);
    
    QMessageBox::information(nullptr, "登录成功", QString("欢迎使用航班管理系统！\n用户ID：%1").arg(userId));
}

void ViewManager::onAdminLoginSuccessful()
{
    // 管理员登录成功，可以跳转到管理界面
    // 暂时跳转到航班搜索界面
    setCurrentUserId(-1);  // 管理员使用特殊ID
    showView(FlightSearchView);
}

void ViewManager::onRegistrationCompleted()
{
    QMessageBox::information(nullptr, "注册成功", "注册成功，请登录");
    showView(LoginView);
}

void ViewManager::onPasswordResetCompleted()
{
    QMessageBox::information(nullptr, "密码重置成功", "密码重置成功，请使用新密码登录");
    showView(LoginView);
}


void ViewManager::onOpenChangeTicketPage(const QString& departCity, const QString& arriveCity, 
                                         const QString& flightNo, const QDate& flightDate)
{
    qDebug() << "ViewManager: 打开改签页面";
    qDebug() << "  出发城市：" << departCity;
    qDebug() << "  到达城市：" << arriveCity;
    qDebug() << "  原航班号：" << flightNo;
    qDebug() << "  原航班日期：" << flightDate;
    
    // 创建改签窗口
    ChangeTicketWidget* changeWidget = new ChangeTicketWidget(departCity, arriveCity, flightNo, flightDate);
    changeWidget->setAttribute(Qt::WA_DeleteOnClose, true);
    changeWidget->setWindowTitle("航班改签");
    changeWidget->resize(1000, 700);
    
    // 显示改签窗口
    changeWidget->show();
}
