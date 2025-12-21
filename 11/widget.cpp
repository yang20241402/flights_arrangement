#include "widget.h"
#include "ui_widget.h"
#include "form.h"
#include "formpwd.h"
#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QODBC","plane_db_conn");

    QString connStr = QString(
        "DRIVER={MySQL ODBC 8.0 Unicode Driver};"
        "SERVER=127.0.0.1;"
        "PORT=3306;"
        "DATABASE=plane;"
        "UID=root;"
        "PWD=20051014;"
        "CHARSET=utf8mb4;"
        "OPTION=3;"
        );
    db.setDatabaseName(connStr);

    if(db.open()){
        QMessageBox::information(this,"连接提示","连接成功");

    }else{
        QMessageBox::warning(this,"连接提示","连接失败");
    }

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

Widget::~Widget()
{
    delete ui;
}

QString Widget::generateVerifyCode()
{
    QString code;
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX);
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10);
    }
    return code;
}

void Widget::on_pushButton_clicked()
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

    if(ui->checkBox->isChecked()){
        QString sql = "SELECT password FROM admin_info WHERE username = :uname LIMIT 1";

        QSqlQuery query(db);
        query.prepare(sql);
        query.bindValue(":uname", username);

        if (!query.exec()) {
            QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
            QSqlDatabase::database().close();
            return ;
        }

        if (query.next()) {
            QString dbPwd = query.value("password").toString();

            if (password == dbPwd) {
                QMessageBox::information(this,"登录提示","管理员登录成功");
                return ;
            } else {
                QMessageBox::critical(this, "登录提示", "管理员密码错误！");
                return ;
            }
        } else {
            QMessageBox::critical(this, "登录提示", "管理员账号不存在！");
            return ;
        }
    }else{
        QString sql = "SELECT userpwd FROM uesr_info1 WHERE username = :uname OR phone = :uname OR email = :uname OR card = :uname LIMIT 1";

        QSqlQuery query(db);
        query.prepare(sql);
        query.bindValue(":uname", username);

        if (!query.exec()) {
            QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
            QSqlDatabase::database().close();
            return ;
        }

        if (query.next()) {
            QString dbPwd = query.value("userpwd").toString();

            if (password == dbPwd) {
                MainWindow *mainwindow = new MainWindow(this);
                this->hide();
                connect(mainwindow, &QWidget::destroyed, this, &Widget::show);
                mainwindow->show();
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
}

void Widget::on_switchLabel_clicked()
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

void Widget::on_pushButton_2_clicked()
{
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
        MainWindow *mainwindow = new MainWindow(this);
        this->hide();
        connect(mainwindow, &QWidget::destroyed, this, &Widget::show);
        mainwindow->show();
    }else{
        QMessageBox::warning(this, "登录提示", "登录失败，验证码错误！");
    }
}

void Widget::on_getCode_clicked()
{
    ui->tip5Label->setVisible(false);
    QString phone = ui->phoneEdit->text().trimmed();
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch match = phoneReg.match(phone);

    if (!match.hasMatch()) {
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }

    QString sql = "SELECT userpwd FROM uesr_info1 WHERE phone = :phone LIMIT 1";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":phone", phone);

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        QSqlDatabase::database().close();
        return ;
    }

    if (!query.next()){
        QMessageBox::warning(this, "提示", "该手机号未注册");
        return;
    }
    m_verifyCode = generateVerifyCode();
    QMessageBox::information(this,"验证码",QString("您的验证码是：%1\n有效期60秒").arg(m_verifyCode));
    g_countdownTimer->start();
}

void Widget::on_registerLabel_clicked()
{
    Form *form = new Form;
    this->hide();
    connect(form, &QWidget::destroyed, this, &Widget::show);
    form->show();
}

void Widget::on_label_9_clicked()
{
    Formpwd *formpwd = new Formpwd;
    this->hide();
    connect(formpwd, &QWidget::destroyed, this, &Widget::show);
    formpwd->show();
}

void Widget::on_label_2_clicked()
{
    MainWindow *mainwindow = new MainWindow(this);
    this->hide();
    connect(mainwindow, &QWidget::destroyed, this, &Widget::show);
    mainwindow->show();
}

void Widget::on_label_4_clicked()
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

void Widget::on_label_6_clicked()
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
