#include "adminpanel.h"
#include <QDebug>

AdminPanel::AdminPanel(QWidget *parent)
    : QWidget(parent)
    , m_tableWidget(nullptr)
{
    setupUI();
    loadUserData();
}

AdminPanel::~AdminPanel()
{
}

void AdminPanel::setupUI()
{
    this->setWindowTitle("管理员系统 - 用户管理");
    this->resize(1200, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 标题
    QLabel *titleLabel = new QLabel("用户信息管理", this);
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 搜索栏
    QHBoxLayout *searchLayout = new QHBoxLayout();
    QLabel *searchLabel = new QLabel("搜索用户：", this);
    m_searchEdit = new QLineEdit(this);
    m_searchEdit->setPlaceholderText("输入用户ID或用户名");
    m_searchEdit->setFixedWidth(250);
    m_searchBtn = new QPushButton("搜索", this);
    m_searchBtn->setFixedWidth(80);
    
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(m_searchEdit);
    searchLayout->addWidget(m_searchBtn);
    searchLayout->addStretch();
    mainLayout->addLayout(searchLayout);

    // 表格
    m_tableWidget = new QTableWidget(this);
    m_tableWidget->setColumnCount(5);
    m_tableWidget->setHorizontalHeaderLabels({"用户ID", "用户名", "密码", "手机号", "邮箱"});
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->setAlternatingRowColors(true);
    
    // 设置列宽
    m_tableWidget->setColumnWidth(0, 80);   // ID
    m_tableWidget->setColumnWidth(1, 150);  // 用户名
    m_tableWidget->setColumnWidth(2, 150);  // 密码
    m_tableWidget->setColumnWidth(3, 150);  // 手机号
    m_tableWidget->setColumnWidth(4, 200);  // 邮箱
    
    mainLayout->addWidget(m_tableWidget);

    // 按钮栏
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    m_refreshBtn = new QPushButton("刷新", this);
    m_addBtn = new QPushButton("添加用户", this);
    m_editBtn = new QPushButton("编辑用户", this);
    m_deleteBtn = new QPushButton("删除用户", this);
    QPushButton *switchToFlightBtn = new QPushButton(">>> 航班管理 >>>", this);
    
    m_refreshBtn->setFixedWidth(100);
    m_addBtn->setFixedWidth(100);
    m_editBtn->setFixedWidth(100);
    m_deleteBtn->setFixedWidth(100);
    switchToFlightBtn->setFixedWidth(150);
    switchToFlightBtn->setFixedHeight(40);
    
    // 设置按钮样式
    QString btnStyle = "QPushButton { padding: 8px; font-size: 12px; }";
    m_refreshBtn->setStyleSheet(btnStyle);
    m_addBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #4CAF50; color: white; }");
    m_editBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #2196F3; color: white; }");
    m_deleteBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #f44336; color: white; }");
    switchToFlightBtn->setStyleSheet("QPushButton { padding: 10px; font-size: 14px; font-weight: bold; background-color: #FF9800; color: white; border-radius: 5px; } QPushButton:hover { background-color: #F57C00; }");
    
    buttonLayout->addWidget(m_refreshBtn);
    buttonLayout->addWidget(m_addBtn);
    buttonLayout->addWidget(m_editBtn);
    buttonLayout->addWidget(m_deleteBtn);
    buttonLayout->addStretch();
    buttonLayout->addWidget(switchToFlightBtn);
    mainLayout->addLayout(buttonLayout);

    // 连接信号
    connect(m_refreshBtn, &QPushButton::clicked, this, &AdminPanel::onRefreshClicked);
    connect(m_addBtn, &QPushButton::clicked, this, &AdminPanel::onAddUserClicked);
    connect(m_editBtn, &QPushButton::clicked, this, &AdminPanel::onEditUserClicked);
    connect(m_deleteBtn, &QPushButton::clicked, this, &AdminPanel::onDeleteUserClicked);
    connect(m_searchBtn, &QPushButton::clicked, this, &AdminPanel::onSearchClicked);
    connect(m_tableWidget, &QTableWidget::cellDoubleClicked, this, &AdminPanel::onTableCellDoubleClicked);
    connect(switchToFlightBtn, &QPushButton::clicked, this, [this]() {
        qDebug() << "切换到航班管理按钮被点击";
        emit switchToFlightManagement();
    });
    
    qDebug() << "AdminPanel UI 设置完成，包含航班管理切换按钮";
}

void AdminPanel::loadUserData(const QString& searchText)
{
    m_tableWidget->setRowCount(0);

    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QString sql = "SELECT id, username, password, phone, email FROM user";
    
    if (!searchText.isEmpty()) {
        sql += QString(" WHERE id = '%1' OR username LIKE '%%2%'")
                   .arg(searchText).arg(searchText);
    }
    
    sql += " ORDER BY id";

    QSqlQuery query(db);
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "查询失败", "错误：" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        m_tableWidget->insertRow(row);
        
        QTableWidgetItem *idItem = new QTableWidgetItem(query.value("id").toString());
        QTableWidgetItem *usernameItem = new QTableWidgetItem(query.value("username").toString());
        QTableWidgetItem *passwordItem = new QTableWidgetItem(query.value("password").toString());
        QTableWidgetItem *phoneItem = new QTableWidgetItem(query.value("phone").toString());
        QTableWidgetItem *emailItem = new QTableWidgetItem(query.value("email").toString());
        
        idItem->setTextAlignment(Qt::AlignCenter);
        usernameItem->setTextAlignment(Qt::AlignCenter);
        passwordItem->setTextAlignment(Qt::AlignCenter);
        phoneItem->setTextAlignment(Qt::AlignCenter);
        emailItem->setTextAlignment(Qt::AlignCenter);
        
        m_tableWidget->setItem(row, 0, idItem);
        m_tableWidget->setItem(row, 1, usernameItem);
        m_tableWidget->setItem(row, 2, passwordItem);
        m_tableWidget->setItem(row, 3, phoneItem);
        m_tableWidget->setItem(row, 4, emailItem);
        
        row++;
    }
    
    qDebug() << "加载了" << row << "条用户数据";
}

void AdminPanel::onRefreshClicked()
{
    m_searchEdit->clear();
    loadUserData();
    QMessageBox::information(this, "提示", "数据已刷新");
}

void AdminPanel::onAddUserClicked()
{
    showEditDialog(-1);
}

void AdminPanel::onEditUserClicked()
{
    int currentRow = m_tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选择要编辑的用户");
        return;
    }
    
    int userId = m_tableWidget->item(currentRow, 0)->text().toInt();
    showEditDialog(userId);
}

void AdminPanel::onDeleteUserClicked()
{
    int currentRow = m_tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选择要删除的用户");
        return;
    }
    
    int userId = m_tableWidget->item(currentRow, 0)->text().toInt();
    QString username = m_tableWidget->item(currentRow, 1)->text();
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认删除",
        QString("确定要删除用户 %1 (ID: %2) 吗？").arg(username).arg(userId),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        DatabaseManager* dbManager = DatabaseManager::instance();
        QSqlDatabase db = dbManager->getDatabase();
        
        QSqlQuery query(db);
        QString sql = QString("DELETE FROM user WHERE id = %1").arg(userId);
        
        if (query.exec(sql)) {
            QMessageBox::information(this, "成功", "用户已删除");
            loadUserData();
        } else {
            QMessageBox::critical(this, "删除失败", "错误：" + query.lastError().text());
        }
    }
}

void AdminPanel::onSearchClicked()
{
    QString searchText = m_searchEdit->text().trimmed();
    loadUserData(searchText);
}

void AdminPanel::onTableCellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    int userId = m_tableWidget->item(row, 0)->text().toInt();
    showEditDialog(userId);
}

void AdminPanel::showEditDialog(int userId)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(userId == -1 ? "添加用户" : "编辑用户");
    dialog->setFixedSize(400, 200);
    
    QFormLayout *formLayout = new QFormLayout(dialog);
    
    QLineEdit *usernameEdit = new QLineEdit(dialog);
    QLineEdit *passwordEdit = new QLineEdit(dialog);
    
    formLayout->addRow("用户名：", usernameEdit);
    formLayout->addRow("密码：", passwordEdit);
    
    // 如果是编辑模式，加载现有数据
    if (userId != -1) {
        DatabaseManager* dbManager = DatabaseManager::instance();
        QSqlDatabase db = dbManager->getDatabase();
        
        QSqlQuery query(db);
        QString sql = QString("SELECT username, password FROM user WHERE id = %1").arg(userId);
        
        if (query.exec(sql) && query.next()) {
            usernameEdit->setText(query.value("username").toString());
            passwordEdit->setText(query.value("password").toString());
        }
    }
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *saveBtn = new QPushButton("保存", dialog);
    QPushButton *cancelBtn = new QPushButton("取消", dialog);
    
    buttonLayout->addWidget(saveBtn);
    buttonLayout->addWidget(cancelBtn);
    formLayout->addRow(buttonLayout);
    
    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);
    connect(saveBtn, &QPushButton::clicked, [=]() {
        QString username = usernameEdit->text().trimmed();
        QString password = passwordEdit->text().trimmed();
        
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(dialog, "提示", "用户名和密码不能为空");
            return;
        }
        
        DatabaseManager* dbManager = DatabaseManager::instance();
        QSqlDatabase db = dbManager->getDatabase();
        QSqlQuery query(db);
        
        QString sql;
        if (userId == -1) {
            // 添加新用户
            sql = QString("INSERT INTO user (username, password) VALUES ('%1', '%2')")
                      .arg(username.replace("'", "''"))
                      .arg(password.replace("'", "''"));
        } else {
            // 更新用户
            sql = QString("UPDATE user SET username = '%1', password = '%2' WHERE id = %3")
                      .arg(username.replace("'", "''"))
                      .arg(password.replace("'", "''"))
                      .arg(userId);
        }
        
        if (query.exec(sql)) {
            QMessageBox::information(dialog, "成功", userId == -1 ? "用户已添加" : "用户已更新");
            dialog->accept();
            loadUserData();
        } else {
            QMessageBox::critical(dialog, "失败", "错误：" + query.lastError().text());
        }
    });
    
    dialog->exec();
    delete dialog;
}
