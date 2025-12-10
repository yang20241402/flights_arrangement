#include "form.h"
#include "qregularexpression.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    db = QSqlDatabase::database("plane_db_conn"); // 传入之前定义的连接名

    // 检查连接是否有效（可选，避免连接意外断开）
    if (!db.isOpen()) {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，正在尝试重新连接……");
        if (!db.open()) { // 尝试重新打开
            QMessageBox::critical(this, "连接失败", "重连数据库失败：" + db.lastError().text());
            return;
        }
    }

    ui->registerstackedWidget->setCurrentIndex(0);
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);
    ui->tip5Label->setVisible(false);
    ui->tip6Label->setVisible(false);
    ui->tip7Label->setVisible(false);


    g_countdownTimer = new QTimer(this);
    g_countdownTimer->setInterval(1000); // 1秒触发一次
    g_countdownTimer->setSingleShot(false);
    connect(g_countdownTimer, &QTimer::timeout, this, [=](){
        static int count = 60;
        ui->getcodeLabel1->setText(QString("重新获取(%1s)").arg(count--));
        ui->getcodeLabel1->setEnabled(false); // 倒计时期间禁用按钮
        if (count < 0) {
            g_countdownTimer->stop();
            ui->getcodeLabel1->setText("获取验证码");
            ui->getcodeLabel1->setEnabled(true);
            count = 60; // 重置倒计时
        }
    });

    // 手机号输入框格式验证（可选，限制11位数字）
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    ui->phoneEdit->setValidator(new QRegularExpressionValidator(phoneReg, this));
}

Form::~Form()
{
    delete ui;
}

QString Form::generateVerifyCode()
{
    QString code;
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX);
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10);
    }
    return code;
}


void Form::on_getcodeLabel1_clicked()
{
    ui->tip3Label->setVisible(false);
    ui->tip5Label->setVisible(false);
    QString phone = ui->phoneEdit->text().trimmed();
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch match = phoneReg.match(phone); // 执行匹配


    if (!match.hasMatch()) {
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }

    m_verifyCode = generateVerifyCode();
    QMessageBox::information(this,"验证码",QString("您的验证码是：%1\n有效期60秒").arg(m_verifyCode));
    g_countdownTimer->start();
}


void Form::on_pushButton_2_clicked()
{
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);
    if (!ui->radioButton->isChecked()) {
        ui->tip4Label->setVisible(true);
        return;
    }

    QString phone = ui->phoneEdit->text().trimmed();
    if (phone.isEmpty()) {
        ui->tip3Label->setVisible(true);
        ui->codeEdit->clear();
        return;
    }
    QString code=ui->codeEdit->text().trimmed();

    if(code==m_verifyCode){
        ui->phoneshow->setText(phone);
        ui->registerstackedWidget->setCurrentIndex(1);
    }else{
        QMessageBox::warning(this, "注册提示", "注册失败，验证码错误！");
    }
}


void Form::on_pushButton_3_clicked()
{
    ui->tip6Label->setVisible(false);
    ui->tip7Label->setVisible(false);
    QString pwd=ui->pwdEdit->text().trimmed();
    QRegularExpression pwdReg("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^a-zA-Z0-9])[^\\s].{8,20}$");
    QRegularExpressionMatch match = pwdReg.match(pwd);
    if (!match.hasMatch()) {
        ui->tip6Label->setVisible(true);
        ui->pwdEdit->setFocus();
        return;
    }

    if(ui->pwdEdit_2->text().trimmed()==ui->pwdEdit->text().trimmed()){
        QString phone = ui->phoneEdit->text().trimmed();
        QString sql = "INSERT INTO uesr_info1 (username,userpwd, phone) "
                      "VALUES (:username, :userpwd, :phone)";
        QSqlQuery query(db);
        query.prepare(sql);

        query.bindValue(":username", phone);
        query.bindValue(":userpwd", pwd);
        query.bindValue(":phone", phone);

        if (query.exec()) {
            QMessageBox::information(this, "注册成功", "账号注册成功！可前往登录");
            ui->phoneEdit->clear();
            ui->pwdEdit->clear();
            ui->pwdEdit_2->clear();
        } else {
            QMessageBox::critical(this, "注册失败", "错误原因：" + query.lastError().text());
        }

    }else{
        ui->tip7Label->setVisible(true);
        ui->pwdEdit_2->clear();
        ui->pwdEdit_2->setFocus();
        return ;
    }
}



void Form::on_backLabel_clicked()
{
    ui->phoneEdit->clear();
    ui->pwdEdit->clear();
    ui->codeEdit->clear();
    ui->pwdEdit_2->clear();
    ui->registerstackedWidget->setCurrentIndex(0);
}


void Form::on_backLabel_2_clicked()
{
    ui->phoneEdit->clear();
    ui->pwdEdit->clear();
    ui->pwdEdit_2->clear();
    ui->codeEdit->clear();
    this->close();
}

