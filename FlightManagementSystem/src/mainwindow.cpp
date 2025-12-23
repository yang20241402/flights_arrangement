#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewmanager.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_stackedWidget(nullptr)
    , m_viewManager(nullptr)
{
    ui->setupUi(this);
    setupUI();
    setupMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    // 设置窗口属性 - 适应登录界面大小
    setWindowTitle("航班管理系统 - Flight Management System");
    resize(920, 551);  // 匹配登录界面大小
    setMinimumSize(920, 551);
    setMaximumSize(920, 551);  // 固定窗口大小
    
    // 创建中央widget和布局
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    

    
    // 创建StackedWidget用于界面切换
    m_stackedWidget = new QStackedWidget(centralWidget);
    m_stackedWidget->setGeometry(0, 0, 920, 551);  // 设置为全窗口大小
    // mainLayout->addWidget(m_stackedWidget);
    
    // 创建ViewManager
    m_viewManager = new ViewManager(m_stackedWidget, this);
    
    // 连接信号
    connect(m_viewManager, QOverload<ViewManager::ViewType, ViewManager::ViewType>::of(&ViewManager::viewChanged),
            this, [this](ViewManager::ViewType from, ViewManager::ViewType to) {
                onViewChanged(static_cast<int>(from), static_cast<int>(to));
            });
    connect(m_viewManager, &ViewManager::userLoggedIn, this, &MainWindow::onUserLoggedIn);
    
    // 设置状态栏
    statusBar()->showMessage("欢迎使用航班管理系统", 3000);
}

void MainWindow::setupMenuBar()
{

    menuBar()->hide();
}

void MainWindow::onViewChanged(int from, int to)
{
    Q_UNUSED(from);

    QString statusText;
    switch (to) {
    case ViewManager::LoginView:
        statusText = "请登录您的账户";
        break;
    case ViewManager::RegisterView:
        statusText = "创建新账户";
        break;
    case ViewManager::PasswordResetView:
        statusText = "重置密码";
        break;
    case ViewManager::UserCenterView:
        statusText = "个人中心";
        break;
    case ViewManager::FlightSearchView:
        statusText = "航班查询";
        break;
    default:
        statusText = "航班管理系统";
        break;
    }

    statusBar()->showMessage(statusText);
}


void MainWindow::onUserLoggedIn(int userId)
{
    statusBar()->showMessage(QString("用户 %1 已登录").arg(userId), 3000);
}
