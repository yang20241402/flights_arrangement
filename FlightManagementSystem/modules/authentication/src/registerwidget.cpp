#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "databasemanager.h"
#include "utils.h"

RegisterWidget::RegisterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

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

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

QString RegisterWidget::generateVerifyCode()
{
    QString code;
    srand(QDateTime::currentMSecsSinceEpoch() % UINT_MAX);
    for (int i = 0; i < 6; ++i) {
        code += QString::number(rand() % 10);
    }
    return code;
}

void RegisterWidget::on_getcodeLabel1_clicked()
{
    ui->tip3Label->setVisible(false);
    ui->tip5Label->setVisible(false);
    
    QString phone = ui->phoneEdit->text().trimmed();
    
    // 验证手机号格式
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch match = phoneReg.match(phone);

    if (!match.hasMatch()) {
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }

    // 生成验证码并记录时间
    m_verifyCode = generateVerifyCode();
    m_verifyCodeTime = QDateTime::currentDateTime();
    
    QMessageBox::information(this,"验证码",QString("您的验证码是：%1\n有效期60秒").arg(m_verifyCode));
    g_countdownTimer->start();
}

void RegisterWidget::on_pushButton_2_clicked()
{
    ui->tip3Label->setVisible(false);
    ui->tip4Label->setVisible(false);
    ui->tip5Label->setVisible(false);
    
    // 1. 检查是否同意协议
    if (!ui->radioButton->isChecked()) {
        ui->tip4Label->setVisible(true);
        return;
    }

    // 2. 验证手机号格式（二次验证，防止用户修改）
    QString phone = ui->phoneEdit->text().trimmed();
    if (phone.isEmpty()) {
        ui->tip3Label->setText("请输入手机号");
        ui->tip3Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }
    
    QRegularExpression phoneReg("^1[3-9]\\d{9}$");
    QRegularExpressionMatch phoneMatch = phoneReg.match(phone);
    if (!phoneMatch.hasMatch()) {
        ui->tip5Label->setVisible(true);
        ui->phoneEdit->setFocus();
        return;
    }

    // 3. 验证验证码是否为空
    QString code = ui->codeEdit->text().trimmed();
    if (code.isEmpty()) {
        ui->tip3Label->setText("请输入验证码");
        ui->tip3Label->setVisible(true);
        ui->codeEdit->setFocus();
        return;
    }

    // 4. 检查验证码是否过期（60秒）
    if (m_verifyCodeTime.isValid()) {
        qint64 elapsedSeconds = m_verifyCodeTime.secsTo(QDateTime::currentDateTime());
        if (elapsedSeconds > 60) {
            QMessageBox::warning(this, "验证码过期", "验证码已过期，请重新获取！");
            ui->codeEdit->clear();
            ui->codeEdit->setFocus();
            return;
        }
    }

    // 5. 验证验证码是否正确
    if (code == m_verifyCode) {
        ui->phoneshow->setText(phone);
        ui->registerstackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::warning(this, "注册提示", "验证码错误，请重新输入！");
        ui->codeEdit->clear();
        ui->codeEdit->setFocus();
    }
}

void RegisterWidget::on_pushButton_3_clicked()
{
    ui->tip6Label->setVisible(false);
    ui->tip7Label->setVisible(false);
    
    // 1. 验证密码是否为空
    QString pwd = ui->pwdEdit->text().trimmed();
    if (pwd.isEmpty()) {
        ui->tip6Label->setText("请输入密码");
        ui->tip6Label->setVisible(true);
        ui->pwdEdit->setFocus();
        return;
    }
    
    // 2. 验证密码格式（修复正则表达式：确保长度为8-20个字符）
    QRegularExpression pwdReg("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^a-zA-Z0-9])[^\\s]{8,20}$");
    QRegularExpressionMatch match = pwdReg.match(pwd);
    if (!match.hasMatch()) {
        ui->tip6Label->setText("密码必须包含大小写字母、数字、特殊字符，长度8-20位");
        ui->tip6Label->setVisible(true);
        ui->pwdEdit->setFocus();
        return;
    }

    // 3. 验证确认密码是否为空
    QString confirmPwd = ui->pwdEdit_2->text().trimmed();
    if (confirmPwd.isEmpty()) {
        ui->tip7Label->setText("请输入确认密码");
        ui->tip7Label->setVisible(true);
        ui->pwdEdit_2->setFocus();
        return;
    }

    // 4. 验证两次密码是否一致
    if (pwd != confirmPwd) {
        ui->tip7Label->setText("两次密码输入不一致");
        ui->tip7Label->setVisible(true);
        ui->pwdEdit_2->clear();
        ui->pwdEdit_2->setFocus();
        return;
    }

    // 5. 检查手机号是否已注册
    QString phone = ui->phoneEdit->text().trimmed();
    
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    // 检查手机号是否已存在（作为用户名）
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM user WHERE username = :username");
    checkQuery.bindValue(":username", phone);
    
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "数据库错误", "查询失败：" + checkQuery.lastError().text());
        return;
    }
    
    if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "注册失败", "该手机号已被注册，请直接登录或使用其他手机号！");
        ui->registerstackedWidget->setCurrentIndex(0);
        ui->phoneEdit->setFocus();
        return;
    }

    // 6. 插入新用户（注意：数据库只有 username 和 password 字段）
    QString sql = "INSERT INTO user (username, password) "
                  "VALUES (:username, :password)";
    QSqlQuery query(db);
    query.prepare(sql);

    // 使用手机号作为用户名
    query.bindValue(":username", phone);
    query.bindValue(":password", pwd);

    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "账号注册成功！可前往登录\n用户名为您的手机号");
        ui->phoneEdit->clear();
        ui->pwdEdit->clear();
        ui->codeEdit->clear();
        ui->pwdEdit_2->clear();
        ui->registerstackedWidget->setCurrentIndex(0);
        emit registrationCompleted();
    } else {
        QMessageBox::critical(this, "注册失败", "错误原因：" + query.lastError().text());
    }
}

void RegisterWidget::on_backLabel_clicked()
{
    ui->phoneEdit->clear();
    ui->pwdEdit->clear();
    ui->codeEdit->clear();
    ui->pwdEdit_2->clear();
    ui->registerstackedWidget->setCurrentIndex(0);
}

void RegisterWidget::on_backLabel_2_clicked()
{
    ui->phoneEdit->clear();
    ui->pwdEdit->clear();
    ui->pwdEdit_2->clear();
    ui->codeEdit->clear();
    emit backToLoginRequested();
}

void RegisterWidget::on_label_4_clicked()
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

void RegisterWidget::on_label_6_clicked()
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