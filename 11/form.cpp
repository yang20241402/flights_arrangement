#include "form.h"
#include "qregularexpression.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    db = QSqlDatabase::database("plane_db_conn");

    if (!db.isOpen()) {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，正在尝试重新连接……");
        if (!db.open()) {
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
    QRegularExpressionMatch match = phoneReg.match(phone);

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
            ui->codeEdit->clear();
            ui->pwdEdit_2->clear();
            this->close();
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

void Form::on_label_4_clicked()
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

void Form::on_label_6_clicked()
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
