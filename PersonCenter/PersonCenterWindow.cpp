#include "PersonCenterWindow.h"
#include "ui_PersonCenterWindow.h"
#include "myorderdialog.h"  // 包含订单窗口头文件
#include "passengerdialog.h"
#include "pointsdialog.h"
#include"mymsgdialog.h"
#include"profileeditwidget.h"
#include <QStackedWidget> // 仅手动创建时需要加
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
PersonCenterWindow::PersonCenterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PersonCenterWindow)
{
    ui->setupUi(this);
    m_currentUserId = 1;
    loadUserInfo();

    // ========== 1. 初始化centralwidget主布局（修正析构警告） ==========
    QWidget *central = ui->centralwidget;
    // 先获取布局指针，再删除（避免直接delete不完整类型）
    QLayout *oldLayout = central->layout();
    if (oldLayout) {
        oldLayout->deleteLater(); // 改用deleteLater，安全析构QLayout
    }
    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    central->setStyleSheet("background:#FFFFFF;");


    // ========== 2. 顶部用户信息区（固定高度） ==========
    ui->topUserWidget->setFixedHeight(100); // 根据你的UI调整高度
    mainLayout->addWidget(ui->topUserWidget);


    // ========== 3. 四行长按钮（自适应拉伸） ==========
    auto setupFuncButton = [&](QPushButton *btn, const QString &text) {
        // 按钮文字左对齐 + 自适应拉伸
        btn->setText(text);
        btn->setStyleSheet(R"(
            QPushButton {
                width:100%;
                border:none;
                border-top:1px solid #F2F2F2;
                background:white;
                text-align:left;
                padding-left:20px;
                font-size:14px;
                color:#333;
            }
            QPushButton:hover {
                background:#F5F7FA;
            }
        )");
        // 核心：自适应尺寸策略
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        mainLayout->addWidget(btn);
    };

    // 配置四个功能按钮
    setupFuncButton(ui->myOrderBtn, "我的订单");
    setupFuncButton(ui->commonInfoBtn, "常用信息");
    setupFuncButton(ui->myPointsBtn, "我的积分");
    setupFuncButton(ui->myMsgBtn, "我的信息");


    // ========== 4. 窗口配置 ==========
    resize(400, 600);
    setMinimumSize(800, 600);
    setWindowTitle("个人中心");


}

PersonCenterWindow::~PersonCenterWindow()
{
    delete ui;
}

void PersonCenterWindow::on_myOrderBtn_clicked()
{
    MyOrderDialog dialog(1, this);
    dialog.exec();
}

void PersonCenterWindow::on_commonInfoBtn_clicked()
{
    int currentUserId = 1;
    PassengerDialog dialog(currentUserId, this);
    dialog.exec();
}

void PersonCenterWindow::on_myPointsBtn_clicked()
{
    int currentUserId = 1;
    PointsDialog dialog(currentUserId, this);
    dialog.exec();
}

void PersonCenterWindow::on_myMsgBtn_clicked()
{

    mymsgdialog *msgdialog = new mymsgdialog(m_currentUserId, this);
    msgdialog->exec();
    delete msgdialog;
}

void PersonCenterWindow::on_editBtn_clicked()
{
    ProfileEditWidget *profileWidget=new ProfileEditWidget(m_currentUserId,nullptr);
    connect(profileWidget, &ProfileEditWidget::profileUpdated, this, &PersonCenterWindow::loadUserInfo);
    profileWidget->show();
}

void PersonCenterWindow::loadUserInfo()
{
    // 1. 连接数据库（复用项目中的数据库连接，或单独创建）
    QSqlDatabase db = QSqlDatabase::database("ProfileEditConnection"); // 复用编辑资料的连接
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
        db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");
        if (!db.open()) {
            qDebug() << "主页数据库连接失败：" << db.lastError().text();
            return;
        }
    }

    // 2. 用HEX查询用户信息（和编辑资料页面完全一致）
    QSqlQuery query(db);
    QString sql = "SELECT "
                  "HEX(username) AS username_hex, "
                  "HEX(nickname) AS nickname_hex, "
                  "HEX(phone) AS phone_hex, "
                  "HEX(email) AS email_hex "
                  "FROM user WHERE id=?";
    query.prepare(sql);
    query.addBindValue(m_currentUserId); // 登录后保存的用户ID

    if (query.exec() && query.next()) {
        // 3. HEX解码（和编辑资料页面逻辑一致）
        QString nicknameHex = query.value("nickname_hex").toString();
        QString nickname = QString::fromUtf8(QByteArray::fromHex(nicknameHex.toUtf8()));

        // 4. 更新主页控件（示例：更新昵称标签）
        ui->labNickname->setText(nickname + "（普通会员）"); // 对应主页的“张三（普通会员）”区域
        // 若主页有其他信息（手机号、邮箱），同理解码后更新对应控件
    }
}
