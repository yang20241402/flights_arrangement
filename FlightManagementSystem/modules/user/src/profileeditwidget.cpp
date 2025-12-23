#include "profileeditwidget.h"
#include "ui_profileeditwidget.h"
#include "databasemanager.h"
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
    m_userId = userId;
    
    // 设置窗口属性
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    resize(500, 400);
    setMinimumSize(500, 400);

    // 设置验证器
    QRegularExpression phoneRegex("^1[3-9]\\d{9}$");
    ui->lePhone->setValidator(new QRegularExpressionValidator(phoneRegex, this));
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    ui->leEmail->setValidator(new QRegularExpressionValidator(emailRegex, this));
    
    // 重新布局
    initLayout();
    
    // 加载用户资料
    loadUserProfile();
}

ProfileEditWidget::~ProfileEditWidget()
{
    delete ui;
}

void ProfileEditWidget::initLayout()
{
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 30, 30, 30);
    mainLayout->setSpacing(20);

    // 创建表单布局
    QGridLayout *formLayout = new QGridLayout();
    formLayout->setHorizontalSpacing(15);
    formLayout->setVerticalSpacing(15);
    
    // 设置标签和输入框的最小宽度
    ui->labUsername->setMinimumWidth(60);
    ui->labNickname->setMinimumWidth(60);
    ui->labPhone->setMinimumWidth(60);
    ui->labEmail->setMinimumWidth(60);
    
    ui->leUsername->setMinimumWidth(250);
    ui->leNickname->setMinimumWidth(250);
    ui->lePhone->setMinimumWidth(250);
    ui->leEmail->setMinimumWidth(250);
    
    ui->leUsername->setMinimumHeight(30);
    ui->leNickname->setMinimumHeight(30);
    ui->lePhone->setMinimumHeight(30);
    ui->leEmail->setMinimumHeight(30);
    
    // 添加到表单布局
    formLayout->addWidget(ui->labUsername, 0, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leUsername, 0, 1);
    formLayout->addWidget(ui->labNickname, 1, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leNickname, 1, 1);
    formLayout->addWidget(ui->labPhone, 2, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->lePhone, 2, 1);
    formLayout->addWidget(ui->labEmail, 3, 0, Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addWidget(ui->leEmail, 3, 1);
    
    // 设置列拉伸因子
    formLayout->setColumnStretch(1, 1);

    // 创建按钮布局
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    
    ui->btnSave->setMinimumSize(80, 35);
    ui->btnCancel->setMinimumSize(80, 35);
    
    btnLayout->addWidget(ui->btnSave);
    btnLayout->addSpacing(15);
    btnLayout->addWidget(ui->btnCancel);
    btnLayout->addStretch();

    // 添加到主布局
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(btnLayout);
    
    // 设置样式
    setStyleSheet(R"(
        QLabel {
            font-size: 14px;
            color: #333333;
        }
        QLineEdit {
            font-size: 14px;
            padding: 5px;
            border: 1px solid #cccccc;
            border-radius: 3px;
        }
        QLineEdit:focus {
            border: 1px solid #007fff;
        }
        QPushButton {
            font-size: 14px;
            background-color: #007fff;
            color: white;
            border: none;
            border-radius: 3px;
        }
        QPushButton:hover {
            background-color: #0066cc;
        }
        QPushButton:pressed {
            background-color: #0055aa;
        }
        QPushButton#btnCancel {
            background-color: #999999;
        }
        QPushButton#btnCancel:hover {
            background-color: #777777;
        }
    )");
}

void ProfileEditWidget::loadUserProfile()
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
    query.addBindValue(m_userId);

    if (query.exec() && query.next()) {
        QString usernameHex = query.value("username_hex").toString();
        QByteArray usernameBytes = QByteArray::fromHex(usernameHex.toUtf8());
        QString username = QString::fromUtf8(usernameBytes);

        QString nicknameHex = query.value("nickname_hex").toString();
        QByteArray nicknameBytes = QByteArray::fromHex(nicknameHex.toUtf8());
        QString nickname = QString::fromUtf8(nicknameBytes);

        QString phoneHex = query.value("phone_hex").toString();
        QByteArray phoneBytes = QByteArray::fromHex(phoneHex.toUtf8());
        QString phone = QString::fromUtf8(phoneBytes);

        QString emailHex = query.value("email_hex").toString();
        QByteArray emailBytes = QByteArray::fromHex(emailHex.toUtf8());
        QString email = QString::fromUtf8(emailBytes);

        ui->leUsername->setText(username);
        ui->leNickname->setText(nickname);
        ui->lePhone->setText(phone);
        ui->leEmail->setText(email);
    } else {
        QMessageBox::warning(this, "加载失败", "SQL错误：" + query.lastError().text());
    }
}

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

bool ProfileEditWidget::updateUserProfile()
{
    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return false;
    }

    QSqlQuery query(db);
    QString sql = "UPDATE user SET "
                  "username=UNHEX(?), "
                  "nickname=UNHEX(?), "
                  "phone=UNHEX(?), "
                  "email=UNHEX(?) "
                  "WHERE id=?";
    query.prepare(sql);

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

void ProfileEditWidget::on_btnCancel_clicked()
{
    this->close();
}