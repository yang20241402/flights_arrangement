#include "personcenterwindow.h"
#include "ui_personcenterwindow.h"
#include "myorderdialog.h"
#include "passengerdialog.h"
#include "pointsdialog.h"
#include "mymsgdialog.h"
#include "profileeditwidget.h"
#include "databasemanager.h"
#include <QStackedWidget>
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

    QWidget *central = ui->centralwidget;
    QLayout *oldLayout = central->layout();
    if (oldLayout) {
        oldLayout->deleteLater();
    }
    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    central->setStyleSheet("background:#FFFFFF;");

    ui->topUserWidget->setFixedHeight(100);
    mainLayout->addWidget(ui->topUserWidget);

    auto setupFuncButton = [&](QPushButton *btn, const QString &text, const QString &iconPath) {
        btn->setText(text);
        
        // 设置图标
        if (!iconPath.isEmpty()) {
            QIcon icon(iconPath);
            btn->setIcon(icon);
            btn->setIconSize(QSize(24, 24));
        }
        
        btn->setStyleSheet(R"(
            QPushButton {
                width:100%;
                border:none;
                border-top:1px solid #F2F2F2;
                background:white;
                text-align:left;
                padding-left:50px;
                font-size:14px;
                color:#333;
                min-height:50px;
            }
            QPushButton:hover {
                background:#F5F7FA;
            }
        )");
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        mainLayout->addWidget(btn);
    };

    setupFuncButton(ui->myOrderBtn, "我的订单", ":/newimages/newimages/我的订单 .png");
    setupFuncButton(ui->commonInfoBtn, "常用信息", ":/newimages/newimages/常用信息.png");
    setupFuncButton(ui->myPointsBtn, "我的积分", ":/newimages/newimages/我的积分.png");
    setupFuncButton(ui->myMsgBtn, "我的消息", ":/newimages/newimages/我的消息.jpg");

    resize(400, 600);
    setMinimumSize(800, 600);
    setWindowTitle("个人中心");
}

PersonCenterWindow::~PersonCenterWindow()
{
    delete ui;
}

void PersonCenterWindow::setUserId(int userId)
{
    m_currentUserId = userId;
    loadUserInfo();
}

int PersonCenterWindow::getUserId() const
{
    return m_currentUserId;
}

void PersonCenterWindow::showMyOrders()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(this, "提示", "请先登录");
        return;
    }
    
    try {
        MyOrderDialog* dialog = new MyOrderDialog(m_currentUserId, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose, true);
        dialog->setModal(true);
        dialog->exec();
    } catch (...) {
        QMessageBox::critical(this, "错误", "无法打开订单界面");
    }
}

void PersonCenterWindow::showPassengerInfo()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(this, "提示", "请先登录");
        return;
    }
    
    try {
        PassengerDialog* dialog = new PassengerDialog(m_currentUserId, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose, true);
        dialog->setModal(true);
        dialog->exec();
    } catch (...) {
        QMessageBox::critical(this, "错误", "无法打开乘客信息界面");
    }
}

void PersonCenterWindow::showMyPoints()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(this, "提示", "请先登录");
        return;
    }
    
    try {
        PointsDialog* dialog = new PointsDialog(m_currentUserId, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose, true);
        dialog->setModal(true);
        dialog->exec();
    } catch (...) {
        QMessageBox::critical(this, "错误", "无法打开积分界面");
    }
}

void PersonCenterWindow::showMyMessages()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(this, "提示", "请先登录");
        return;
    }
    
    try {
        mymsgdialog* dialog = new mymsgdialog(m_currentUserId, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose, true);
        dialog->setModal(true);
        dialog->exec();
    } catch (...) {
        QMessageBox::critical(this, "错误", "无法打开消息界面");
    }
}

void PersonCenterWindow::showProfileEdit()
{
    if (m_currentUserId <= 0) {
        QMessageBox::warning(this, "提示", "请先登录");
        return;
    }
    
    try {
        ProfileEditWidget* widget = new ProfileEditWidget(m_currentUserId, nullptr);
        widget->setAttribute(Qt::WA_DeleteOnClose, true);
        widget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
        
        // 连接信号，当资料更新后刷新个人中心信息
        connect(widget, &ProfileEditWidget::profileUpdated, this, &PersonCenterWindow::loadUserInfo);
        
        widget->show();
        widget->activateWindow();
    } catch (...) {
        QMessageBox::critical(this, "错误", "无法打开个人资料编辑界面");
    }
}

void PersonCenterWindow::on_myOrderBtn_clicked()
{
    showMyOrders();
}

void PersonCenterWindow::on_commonInfoBtn_clicked()
{
    showPassengerInfo();
}

void PersonCenterWindow::on_myPointsBtn_clicked()
{
    showMyPoints();
}

void PersonCenterWindow::on_myMsgBtn_clicked()
{
    showMyMessages();
}

void PersonCenterWindow::on_editBtn_clicked()
{
    showProfileEdit();
}

void PersonCenterWindow::loadUserInfo()
{
    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

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
        QString nicknameHex = query.value("nickname_hex").toString();
        QString nickname = QString::fromUtf8(QByteArray::fromHex(nicknameHex.toUtf8()));

        ui->labNickname->setText(nickname + "（普通会员）"); // 对应主页的"张三（普通会员）"区域
    }
}