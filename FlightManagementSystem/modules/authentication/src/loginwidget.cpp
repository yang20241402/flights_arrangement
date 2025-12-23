#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "databasemanager.h"
#include "utils.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QSqlError>
#include <QTimer>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDateTime>
#include <QtGlobal>
#include <QDialog>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    ui->tip1Label->setVisible(false);
    ui->tip2Label->setVisible(false);
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);
    ui->tip5Label->setVisible(false);

    g_countdownTimer = new QTimer(this);
    g_countdownTimer->setInterval(1000);
    g_countdownTimer->setSingleShot(false);
    connect(g_countdownTimer, &QTimer::timeout, this, [=](){
        static int count = 60;
        ui->getCode->setText(QString("重新获取(%1s)").arg(count--));
        ui->getCode->setEnabled(false);
        if (count < 0) {
            g_countdownTimer->stop();
            ui->getCode->setText("获取验证码");
            ui->getCode->setEnabled(true);
            count = 60;
        }
    });

    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    ui->phoneEdit->setValidator(new QRegularExpressionValidator(phoneReg, this));
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

QString LoginWidget::generateVerifyCode()
{
    QString code;
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX);
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10);
    }
    return code;
}

void LoginWidget::on_pushButton_clicked()
{
    QString username = ui->userEdit->text().trimmed();
    QString password = ui->pwdEdit->text().trimmed();

    ui->tip1Label->setVisible(false);
    ui->tip2Label->setVisible(false);
    ui->tip4Label->setVisible(false);

    if (username.isEmpty()) {
        ui->tip1Label->setVisible(true);
        ui->pwdEdit->clear();
        return;
    }

    if (password.isEmpty()) {
        ui->tip2Label->setVisible(true);
        return;
    }

    if (!ui->radioButton->isChecked()) {
        ui->tip4Label->setVisible(true);
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    // 普通用户登录
    // 转义用户名中的单引号，防止SQL注入
    QString escapedUsername = username;
    escapedUsername.replace("'", "''");
    
    // 注意：数据库中的字段名是 id，不是 user_id
    // 并且 user 表只有 username 字段，没有 phone 和 email
    QString sql = QString("SELECT id, password FROM user WHERE username = '%1' LIMIT 1")
                      .arg(escapedUsername);

    QSqlQuery query(db);
    
    qDebug() << "执行SQL：" << sql;

    if (!query.exec(sql)) {
        qDebug() << "查询失败：" << query.lastError().text();
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        return ;
    }

    if (query.next()) {
        int userId = query.value("id").toInt();  // 字段名是 id
        QString dbPwd = query.value("password").toString();

        if (password == dbPwd) {
            qDebug() << "用户登录成功，用户ID：" << userId;
            emit loginSuccessful(userId);  // 传递用户ID
            return ;
        } else {
            QMessageBox::critical(this, "登录提示", "登录失败，用户名或密码错误！");
            return ;
        }
    } else {
        QMessageBox::critical(this, "登录提示", "登录失败，该账号不存在！");
        return ;
    }
}

// 新增：管理员登录按钮槽函数
void LoginWidget::on_adminLoginBtn_clicked()
{
    QString username = ui->userEdit->text().trimmed();
    QString password = ui->pwdEdit->text().trimmed();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入管理员账号");
        return;
    }

    if (password.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入管理员密码");
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QString sql = "SELECT password FROM admin_info WHERE username = :uname LIMIT 1";

    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":uname", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        return ;
    }

    if (query.next()) {
        QString dbPwd = query.value("password").toString();

        if (password == dbPwd) {
            QMessageBox::information(this,"登录提示","管理员登录成功");
            emit adminLoginSuccessful();
            return ;
        } else {
            QMessageBox::critical(this, "登录提示", "管理员密码错误！");
            return ;
        }
    } else {
        QMessageBox::critical(this, "登录提示", "管理员账号不存在！");
        return ;
    }
}

void LoginWidget::on_switchLabel_clicked()
{
    int currentIndex = ui->loginStackWidget->currentIndex();
    if (currentIndex == 0) {
        ui->loginStackWidget->setCurrentIndex(1);
        ui->switchLabel->setText("账号密码登录");
    } else {
        ui->loginStackWidget->setCurrentIndex(0);
        ui->switchLabel->setText("验证码登录");
    }
}

void LoginWidget::on_pushButton_2_clicked()
{
    // 验证码登录功能暂时禁用，因为数据库中没有 phone 字段
    QMessageBox::warning(this, "功能提示", "验证码登录功能暂不可用，请使用账号密码登录！\n\n提示：注册时使用的手机号即为用户名");
    return;
    
    /* 原验证码登录代码已禁用
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);

    QString phone=ui->phoneEdit->text().trimmed();
    if (phone.isEmpty()) {
        ui->tip3Label->setVisible(true);
        ui->pwdEdit->clear();
        return;
    }

    if (!ui->radioButton->isChecked()) {
        ui->tip4Label->setVisible(true);
        return;
    }

    QString code=ui->codeEdit->text().trimmed();

    if(code==m_verifyCode){
        // 验证码登录成功，查询用户ID
        DatabaseManager* dbManager = DatabaseManager::instance();
        QSqlDatabase db = dbManager->getDatabase();
        
        if (!db.isValid()) {
            QMessageBox::critical(this, "数据库错误", "数据库连接无效");
            return;
        }

        QString sql = "SELECT user_id FROM user WHERE phone = :phone LIMIT 1";
        QSqlQuery query(db);
        query.prepare(sql);
        query.bindValue(":phone", phone);

        if (!query.exec()) {
            QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
            return;
        }

        if (query.next()) {
            int userId = query.value("user_id").toInt();
            qDebug() << "验证码登录成功，用户ID：" << userId;
            emit loginSuccessful(userId);  // 传递用户ID
        } else {
            QMessageBox::critical(this, "登录失败", "无法获取用户信息");
        }
    }else{
        QMessageBox::warning(this, "登录提示", "登录失败，验证码错误！");
    }
    */
}

void LoginWidget::on_getCode_clicked()
{
    // 验证码功能暂时禁用，因为数据库中没有 phone 字段
    QMessageBox::warning(this, "功能提示", "验证码登录功能暂不可用，请使用账号密码登录！");
    return;
    
    /* 原获取验证码代码已禁用
    ui->tip5Label->setVisible(false);
    QString phone = ui->phoneEdit->text().trimmed();
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch match = phoneReg.match(phone);

    if (!match.hasMatch()) {
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QString sql = "SELECT password FROM user WHERE phone = :phone LIMIT 1";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":phone", phone);

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        return ;
    }

    if (!query.next()){
        QMessageBox::warning(this, "提示", "该手机号未注册");
        return;
    }
    m_verifyCode = generateVerifyCode();
    QMessageBox::information(this,"验证码",QString("您的验证码是：%1\n有效期60秒").arg(m_verifyCode));
    g_countdownTimer->start();
    */
}

void LoginWidget::on_registerLabel_clicked()
{
    emit registerRequested();
}

void LoginWidget::on_label_9_clicked()
{
    emit passwordResetRequested();
}

void LoginWidget::on_label_2_clicked()
{
    // 游客登录，使用特殊的用户ID 0
    qDebug() << "游客登录";
    emit loginSuccessful(0);
}

void LoginWidget::on_label_4_clicked()
{
    QDialog *agreementDlg = new QDialog(this);
    agreementDlg->setWindowTitle("用户服务协议");
    agreementDlg->resize(600, 450);
    agreementDlg->setModal(true);

    QPlainTextEdit *plainText = new QPlainTextEdit(agreementDlg);
    plainText->setReadOnly(true);
    plainText->setFont(QFont("SimHei", 10));

    QString agreementText = R"(
==================== 用户服务协议 ====================
1. 服务范围
   本软件提供航班信息查询服务，票务预订、支付等操作，
   所有航班数据仅供参考，具体以航空公司官方公布为准。

2. 隐私政策
   本软件不会收集、存储您的个人身份信息（如姓名、身份证号），
   仅在本地缓存查询记录（关闭软件后自动清除）。

3. 免责声明
   因数据更新不及时等原因导致的查询错误，
   本软件不承担任何法律责任。

4. 其他
   您使用本软件即表示同意本协议，如不同意请立即关闭软件。
=====================================================
    )";
    plainText->setPlainText(agreementText);

    QPushButton *closeBtn = new QPushButton("关闭", agreementDlg);
    connect(closeBtn, &QPushButton::clicked, agreementDlg, &QDialog::close);

    QVBoxLayout *layout = new QVBoxLayout(agreementDlg);
    layout->addWidget(plainText);
    layout->addWidget(closeBtn, 0, Qt::AlignRight);
    layout->setContentsMargins(10, 10, 10, 10);

    agreementDlg->exec();
}

void LoginWidget::on_label_6_clicked()
{
    QDialog *agreementDlg = new QDialog(this);
    agreementDlg->setWindowTitle("个人信息保护政策");
    agreementDlg->resize(600, 450);
    agreementDlg->setModal(true);

    QPlainTextEdit *plainText = new QPlainTextEdit(agreementDlg);
    plainText->setReadOnly(true);
    plainText->setFont(QFont("SimHei", 10));

    QString agreementText = R"(
==================== 个人信息保护政策 ====================
本软件仅在您使用过程中，获取以下信息：
1. 您输入的航班查询条件（如航班号、日期）。
2. 本地设备的基础系统信息。
3. 不会私自将信息用于其他用途。

如您有疑问，可联系：yizheng719@qq.com
=====================================================
    )";
    plainText->setPlainText(agreementText);

    QPushButton *closeBtn = new QPushButton("关闭", agreementDlg);
    connect(closeBtn, &QPushButton::clicked, agreementDlg, &QDialog::close);

    QVBoxLayout *layout = new QVBoxLayout(agreementDlg);
    layout->addWidget(plainText);
    layout->addWidget(closeBtn, 0, Qt::AlignRight);
    layout->setContentsMargins(10, 10, 10, 10);

    agreementDlg->exec();
}