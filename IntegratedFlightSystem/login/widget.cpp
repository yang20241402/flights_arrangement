#include "widget.h"
#include "ui_widget.h"
#include "form.h"
#include "formpwd.h"
#include "mainwindow.h"
#include "databasemanager.h"
#include "personcenterwindow.h"
#include"flightquerywidget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用统一的数据库管理器
    DatabaseManager* dbManager = DatabaseManager::instance();
    
    // 检查用户数据库连接
    if(dbManager->isDatabaseConnected(DatabaseManager::PlaneDB)){
        qDebug() << "用户数据库连接成功";
    }else{
        QMessageBox::warning(this,"连接提示","用户数据库连接失败");
    }

    ui->tip1Label->setVisible(false);
    ui->tip2Label->setVisible(false);
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);
    ui->tip5Label->setVisible(false);

    g_countdownTimer = new QTimer(this);
    g_countdownTimer->setInterval(1000); // 1秒触发一次
    g_countdownTimer->setSingleShot(false);
    connect(g_countdownTimer, &QTimer::timeout, this, [=](){
        static int count = 60;
        ui->getCode->setText(QString("重新获取(%1s)").arg(count--));
        ui->getCode->setEnabled(false); // 倒计时期间禁用按钮
        if (count < 0) {
            g_countdownTimer->stop();
            ui->getCode->setText("获取验证码");
            ui->getCode->setEnabled(true);
            count = 60; // 重置倒计时
        }
    });

    // 手机号输入框格式验证（可选，限制11位数字）
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
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX); // 设置随机数种子
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10); // 生成 0-9 的随机数
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

    QString sql = "SELECT userpwd FROM uesr_info1 WHERE username = :uname OR phone = :uname OR email = :uname OR card = :uname LIMIT 1";

    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlQuery query = dbManager->createQuery(DatabaseManager::PlaneDB);
    query.prepare(sql);
    // 2. 绑定命名占位符（所有条件都绑定同一个 username）
    query.bindValue(":uname", username);  // 只绑定一次即可，因为所有占位符都是 :uname

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        QSqlDatabase::database().close();
        return ;
    }

    if (query.next()) {  // 找到匹配的记录（4 个字段中任意一个存在该值）
        QString dbPwd = query.value("userpwd").toString();  // 数据库中的密码

        if (password == dbPwd) {
            QMessageBox::information(this,"登录提示","登录成功");
            return ;  // 密码正确，登录成功
        } else {
            QMessageBox::critical(this, "登录提示", "登录失败，用户名或密码错误！");
            return ;
        }
    } else {
        QMessageBox::critical(this, "登录提示", "登录失败，该账号不存在！");
        return ;
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
        QMessageBox::information(this,"登录提示","登录成功");
    }else{
        QMessageBox::warning(this, "登录提示", "登录失败，验证码错误！");
    }
}





void Widget::on_getCode_clicked()
{
    ui->tip5Label->setVisible(false);
    QString phone = ui->phoneEdit->text().trimmed();
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch match = phoneReg.match(phone); // 执行匹配

    // 2. 根据匹配结果判断
    if (!match.hasMatch()) { // 不符合规则
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus(); // 光标聚焦到输入框，方便用户修改
        return; // 阻止后续操作（不生成验证码）
    }

    QString sql = "SELECT userpwd FROM uesr_info1 WHERE phone = :phone LIMIT 1";
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlQuery query = dbManager->createQuery(DatabaseManager::PlaneDB);
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
    Form *form = new Form; // 新建第二面窗口
    this->hide();
    connect(form, &QWidget::destroyed, this, &Widget::show);
    form->show();
}


void Widget::on_label_9_clicked()
{
    Formpwd *formpwd = new Formpwd; // 新建第二面窗口
    this->hide();
    connect(formpwd, &QWidget::destroyed, this, &Widget::show);
    formpwd->show();
}


void Widget::on_label_2_clicked()
{
    MainWindow *mainwindow = new MainWindow(this); // 新建第二面窗口
    this->hide();
    connect(mainwindow, &QWidget::destroyed, this, &Widget::show);
    mainwindow->show();
}


void Widget::on_pushButton_3_clicked()
{
    PersonCenterWindow *w = new PersonCenterWindow(this);
    w->show();

    this->hide();
}



void Widget::on_pushButton_4_clicked()
{
    FlightQueryWidget dialog(1,this);
    dialog.exec();


}

