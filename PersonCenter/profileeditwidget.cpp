#include "profileeditwidget.h"
#include "ui_profileeditwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QRegularExpressionValidator>
#include <QDebug>
#include <QSqlError>

ProfileEditWidget::ProfileEditWidget(int userId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileEditWidget)
{
    ui->setupUi(this);
    setWindowTitle("编辑个人资料");
    resize(500, 300);
    m_userId = userId;

    // 1. 初始化数据库
    initDatabase();
    // 2. 初始化布局
    initLayout();
    // 3. 设置表单验证
    QRegularExpression phoneRegex("^1[3-9]\\d{9}$");
    ui->lePhone->setValidator(new QRegularExpressionValidator(phoneRegex, this));
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    ui->leEmail->setValidator(new QRegularExpressionValidator(emailRegex, this));
    // 4. 加载用户资料（复用消息功能的HEX解码方案）
    loadUserProfile();
}

ProfileEditWidget::~ProfileEditWidget()
{
    if (m_db.isOpen()) m_db.close();
    delete ui;
}

// 初始化数据库连接（复用消息功能的配置）
void ProfileEditWidget::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QODBC", "ProfileEditConnection");
    m_db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
    m_db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");

    if (!m_db.open()) {
        QMessageBox::critical(this, "数据库错误", "连接失败：" + m_db.lastError().text());
        return;
    }

    // 强制设置数据库编码（和消息功能保持一致）
    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");
}

// 布局调整
void ProfileEditWidget::initLayout()
{
    if (this->layout()) delete this->layout();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 表单区域
    QWidget *formWidget = new QWidget();
    QGridLayout *formLayout = new QGridLayout(formWidget);
    formLayout->setSpacing(10);
    formLayout->addWidget(ui->labUsername, 0, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leUsername, 0, 1);
    formLayout->addWidget(ui->labNickname, 1, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leNickname, 1, 1);
    formLayout->addWidget(ui->labPhone, 2, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->lePhone, 2, 1);
    formLayout->addWidget(ui->labEmail, 3, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leEmail, 3, 1);

    // 按钮区域
    QWidget *btnWidget = new QWidget();
    QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
    btnLayout->addStretch();
    btnLayout->addWidget(ui->btnSave);
    btnLayout->addSpacing(10);
    btnLayout->addWidget(ui->btnCancel);

    mainLayout->addWidget(formWidget);
    mainLayout->addWidget(btnWidget);
}

// 加载用户资料（完全复用消息功能的HEX解码方案）
void ProfileEditWidget::loadUserProfile()
{
    if (!m_db.isOpen()) {
        QMessageBox::warning(this, "错误", "数据库未连接！");
        return;
    }

    QSqlQuery query(m_db);
    // 关键：用HEX()函数将中文字段转为十六进制字符串（避免编码转换错误）
    QString sql = "SELECT "
                  "HEX(username) AS username_hex, "
                  "HEX(nickname) AS nickname_hex, "
                  "HEX(phone) AS phone_hex, "
                  "HEX(email) AS email_hex "
                  "FROM user WHERE id=?";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (query.exec() && query.next()) {
        // 1. HEX解码用户名
        QString usernameHex = query.value("username_hex").toString();
        QByteArray usernameBytes = QByteArray::fromHex(usernameHex.toUtf8());
        QString username = QString::fromUtf8(usernameBytes);

        // 2. HEX解码昵称（中文核心处理）
        QString nicknameHex = query.value("nickname_hex").toString();
        QByteArray nicknameBytes = QByteArray::fromHex(nicknameHex.toUtf8());
        QString nickname = QString::fromUtf8(nicknameBytes);

        // 3. HEX解码手机号
        QString phoneHex = query.value("phone_hex").toString();
        QByteArray phoneBytes = QByteArray::fromHex(phoneHex.toUtf8());
        QString phone = QString::fromUtf8(phoneBytes);

        // 4. HEX解码邮箱
        QString emailHex = query.value("email_hex").toString();
        QByteArray emailBytes = QByteArray::fromHex(emailHex.toUtf8());
        QString email = QString::fromUtf8(emailBytes);

        // 显示到控件
        ui->leUsername->setText(username);
        ui->leNickname->setText(nickname);
        ui->lePhone->setText(phone);
        ui->leEmail->setText(email);
    } else {
        QMessageBox::warning(this, "加载失败", "SQL错误：" + query.lastError().text());
    }
}

// 表单验证
bool ProfileEditWidget::validateForm()
{
    if (ui->leUsername->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "验证失败", "用户名不能为空！");
        ui->leUsername->setFocus();
        return false;
    }

    QString phone = ui->lePhone->text().trimmed();
    if (!phone.isEmpty() && phone.length() != 11) {
        QMessageBox::warning(this, "验证失败", "手机号格式错误（需11位数字）！");
        ui->lePhone->setFocus();
        return false;
    }

    QString email = ui->leEmail->text().trimmed();
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!email.isEmpty() && !emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "验证失败", "邮箱格式错误！");
        ui->leEmail->setFocus();
        return false;
    }

    return true;
}

// 更新用户资料（复用消息功能的UNHEX保存方案）
bool ProfileEditWidget::updateUserProfile()
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    // 关键：用UNHEX()函数将UTF-8字节转为数据库存储的字符串
    QString sql = "UPDATE user SET "
                  "username=UNHEX(?), "
                  "nickname=UNHEX(?), "
                  "phone=UNHEX(?), "
                  "email=UNHEX(?) "
                  "WHERE id=?";
    query.prepare(sql);

    // 转为十六进制字符串后绑定参数（和消息功能保持一致）
    query.addBindValue(ui->leUsername->text().toUtf8().toHex());
    query.addBindValue(ui->leNickname->text().toUtf8().toHex()); // 中文核心处理
    query.addBindValue(ui->lePhone->text().toUtf8().toHex());
    query.addBindValue(ui->leEmail->text().toUtf8().toHex());
    query.addBindValue(m_userId);

    if (!query.exec()) {
        QMessageBox::warning(this, "保存失败", "更新失败：" + query.lastError().text());
        return false;
    }
    return true;
}

// 保存修改
void ProfileEditWidget::on_btnSave_clicked()
{
    if (!validateForm()) return;

    if (QMessageBox::question(this, "确认保存", "是否保存修改？",
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    if (updateUserProfile()) {
        QMessageBox::information(this, "成功", "资料修改成功！");
        emit profileUpdated();
        this->close();
    }
}

// 取消操作
void ProfileEditWidget::on_btnCancel_clicked()
{
    this->close();
}
