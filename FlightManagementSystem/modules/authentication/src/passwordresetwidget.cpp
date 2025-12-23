#include "passwordresetwidget.h"
#include "ui_passwordresetwidget.h"
#include "databasemanager.h"
#include "utils.h"

PasswordResetWidget::PasswordResetWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PasswordResetWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    ui->pwdstackedWidget->setCurrentIndex(0);
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
        ui->getcodeLabel1->setText(QString("重新获取(%1s)").arg(count--));
        ui->getcodeLabel1->setEnabled(false);
        if (count < 0) {
            g_countdownTimer->stop();
            ui->getcodeLabel1->setText("获取验证码");
            ui->getcodeLabel1->setEnabled(true);
            count = 60;
        }
    });
}

PasswordResetWidget::~PasswordResetWidget()
{
    delete ui;
}

QString PasswordResetWidget::generateVerifyCode()
{
    QString code;
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX);
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10);
    }
    return code;
}

void PasswordResetWidget::on_pushButton_2_clicked()
{
    ui->tip1Label->setVisible(false);
    QString username=ui->usernameEdit->text().trimmed();
    if (username.isEmpty()) {
        ui->tip1Label->setVisible(true);
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QString sql = "SELECT username, phone FROM user WHERE username = :uname OR phone = :uname OR email = :uname LIMIT 1";

    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":uname", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", "数据库错误：" + query.lastError().text());
        return ;
    }

    if (query.next()) {
        QString phone = query.value("phone").toString();
        QString username1 = query.value("username").toString();
        qDebug() << "查询到的用户名：" << username1;
        qDebug() << "查询到的手机号：" << phone;
        ui->nameshow->setText(username1);
        ui->phoneshow->setText(phone);
        ui->pwdstackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::critical(this, "登录提示", "该账号不存在！");
        return ;
    }
}

void PasswordResetWidget::on_getcodeLabel1_clicked()
{
    m_verifyCode = generateVerifyCode();
    QMessageBox::information(this,"验证码",QString("您的验证码是：%1\n有效期60秒").arg(m_verifyCode));
    g_countdownTimer->start();
}

void PasswordResetWidget::on_pushButton_3_clicked()
{
    ui->tip2Label->setVisible(false);
    ui->tip3Label->setVisible(false);
    QString code=ui->codeEdit->text().trimmed();
    if(code.isEmpty()){
        ui->tip2Label->setVisible(true);
        return ;
    }

    if(code==m_verifyCode){
        ui->pwdstackedWidget->setCurrentIndex(2);
    }else{
        ui->tip3Label->setVisible(true);
        return ;
    }
}

void PasswordResetWidget::on_pushButton_4_clicked()
{
    ui->tip4Label->setVisible(false);
    ui->tip5Label->setVisible(false);
    QString pwd=ui->pwdEdit->text().trimmed();
    QRegularExpression pwdReg("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^a-zA-Z0-9])[^\\s].{8,20}$");
    QRegularExpressionMatch match = pwdReg.match(pwd);
    if (!match.hasMatch()) {
        ui->tip4Label->setVisible(true);
        ui->pwdEdit->setFocus();
        return;
    }

    QString pwd2=ui->pwdEdit_2->text().trimmed();

    if(pwd2==pwd){
        QString username=ui->usernameEdit->text().trimmed();
        
        // 获取数据库连接
        DatabaseManager* dbManager = DatabaseManager::instance();
        QSqlDatabase db = dbManager->getDatabase();
        
        if (!db.isValid()) {
            QMessageBox::critical(this, "数据库错误", "数据库连接无效");
            return;
        }

        QString sql = "UPDATE user "
                      "SET password = :newPwd "
                      "WHERE username = :uname OR phone = :uname OR email = :uname LIMIT 1";

        QSqlQuery query(db);
        query.prepare(sql);
        query.bindValue(":newPwd", pwd);
        query.bindValue(":uname", username);

        if (query.exec()) {
            if (query.numRowsAffected() > 0) {
                QMessageBox::information(this, "成功", "密码修改成功！请用新密码登录");
                ui->codeEdit->clear();
                ui->pwdEdit->clear();
                ui->pwdEdit_2->clear();
                emit passwordResetCompleted();
            } else {
                QMessageBox::warning(this, "提示", "未找到该用户，修改失败！");
            }
        }else {
            QMessageBox::critical(this, "修改失败", "数据库错误：" + query.lastError().text());
        }
    }else{
        ui->tip5Label->setVisible(true);
        ui->pwdEdit_2->clear();
        ui->pwdEdit_2->setFocus();
    }
}

void PasswordResetWidget::on_backLabel_clicked()
{
    ui->pwdstackedWidget->setCurrentIndex(1);
    ui->usernameEdit->clear();
    ui->codeEdit->clear();
    ui->pwdEdit->clear();
    ui->pwdEdit_2->clear();
}

void PasswordResetWidget::on_backLabel_2_clicked()
{
    ui->pwdstackedWidget->setCurrentIndex(0);
    ui->pwdEdit->clear();
    ui->pwdEdit_2->clear();
}

void PasswordResetWidget::on_backLabel_3_clicked()
{
    ui->usernameEdit->clear();
    ui->codeEdit->clear();
    ui->pwdEdit->clear();
    ui->pwdEdit_2->clear();
    emit backToLoginRequested();
}