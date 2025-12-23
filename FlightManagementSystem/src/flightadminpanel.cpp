#include "flightadminpanel.h"
#include <QDebug>
#include <QScrollArea>

FlightAdminPanel::FlightAdminPanel(QWidget *parent)
    : QWidget(parent)
    , m_tableWidget(nullptr)
{
    setupUI();
    loadFlightData();
}

FlightAdminPanel::~FlightAdminPanel()
{
}

void FlightAdminPanel::setupUI()
{
    this->setWindowTitle("管理员系统 - 航班信息管理");
    this->resize(1400, 800);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 标题
    QLabel *titleLabel = new QLabel("航班信息管理", this);
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 搜索栏
    QHBoxLayout *searchLayout = new QHBoxLayout();
    
    QLabel *departLabel = new QLabel("出发城市：", this);
    m_departCityEdit = new QLineEdit(this);
    m_departCityEdit->setPlaceholderText("如：北京");
    m_departCityEdit->setFixedWidth(150);
    
    QLabel *arriveLabel = new QLabel("到达城市：", this);
    m_arriveCityEdit = new QLineEdit(this);
    m_arriveCityEdit->setPlaceholderText("如：上海");
    m_arriveCityEdit->setFixedWidth(150);
    
    m_searchBtn = new QPushButton("搜索", this);
    m_searchBtn->setFixedWidth(80);
    
    searchLayout->addWidget(departLabel);
    searchLayout->addWidget(m_departCityEdit);
    searchLayout->addWidget(arriveLabel);
    searchLayout->addWidget(m_arriveCityEdit);
    searchLayout->addWidget(m_searchBtn);
    searchLayout->addStretch();
    mainLayout->addLayout(searchLayout);

    // 表格
    m_tableWidget = new QTableWidget(this);
    m_tableWidget->setColumnCount(10);
    m_tableWidget->setHorizontalHeaderLabels({
        "ID", "航班号", "航空公司", "出发城市", "到达城市", 
        "起飞时间", "到达时间", "成人价格", "飞行时长", "机型"
    });
    
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->setAlternatingRowColors(true);
    
    // 设置列宽
    m_tableWidget->setColumnWidth(0, 50);   // ID
    m_tableWidget->setColumnWidth(1, 80);   // 航班号
    m_tableWidget->setColumnWidth(2, 120);  // 航空公司
    m_tableWidget->setColumnWidth(3, 80);   // 出发城市
    m_tableWidget->setColumnWidth(4, 80);   // 到达城市
    m_tableWidget->setColumnWidth(5, 80);   // 起飞时间
    m_tableWidget->setColumnWidth(6, 80);   // 到达时间
    m_tableWidget->setColumnWidth(7, 80);   // 成人价格
    m_tableWidget->setColumnWidth(8, 100);  // 飞行时长
    
    mainLayout->addWidget(m_tableWidget);

    // 按钮栏
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    m_refreshBtn = new QPushButton("刷新", this);
    m_addBtn = new QPushButton("添加航班", this);
    m_editBtn = new QPushButton("编辑航班", this);
    m_deleteBtn = new QPushButton("删除航班", this);
    QPushButton *switchToUserBtn = new QPushButton("切换到用户管理", this);
    
    m_refreshBtn->setFixedWidth(100);
    m_addBtn->setFixedWidth(100);
    m_editBtn->setFixedWidth(100);
    m_deleteBtn->setFixedWidth(100);
    switchToUserBtn->setFixedWidth(120);
    
    // 设置按钮样式
    QString btnStyle = "QPushButton { padding: 8px; font-size: 12px; }";
    m_refreshBtn->setStyleSheet(btnStyle);
    m_addBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #4CAF50; color: white; }");
    m_editBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #2196F3; color: white; }");
    m_deleteBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #f44336; color: white; }");
    switchToUserBtn->setStyleSheet(btnStyle + "QPushButton { background-color: #FF9800; color: white; }");
    
    buttonLayout->addWidget(m_refreshBtn);
    buttonLayout->addWidget(m_addBtn);
    buttonLayout->addWidget(m_editBtn);
    buttonLayout->addWidget(m_deleteBtn);
    buttonLayout->addWidget(switchToUserBtn);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // 连接信号
    connect(m_searchBtn, &QPushButton::clicked, this, &FlightAdminPanel::onSearchClicked);
    connect(m_refreshBtn, &QPushButton::clicked, this, &FlightAdminPanel::onRefreshClicked);
    connect(m_addBtn, &QPushButton::clicked, this, &FlightAdminPanel::onAddFlightClicked);
    connect(m_editBtn, &QPushButton::clicked, this, &FlightAdminPanel::onEditFlightClicked);
    connect(m_deleteBtn, &QPushButton::clicked, this, &FlightAdminPanel::onDeleteFlightClicked);
    connect(m_tableWidget, &QTableWidget::cellDoubleClicked, this, &FlightAdminPanel::onTableCellDoubleClicked);
    connect(switchToUserBtn, &QPushButton::clicked, this, [this]() {
        emit switchToUserManagement();
    });
}


void FlightAdminPanel::loadFlightData(const QString& departCity, const QString& arriveCity)
{
    m_tableWidget->setRowCount(0);

    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    // 构建 UNION 查询，从所有 flights_batch 表中查询
    QString sql = "";
    for (int i = 1; i <= 9; i++) {
        if (i > 1) sql += " UNION ALL ";
        
        QString tableName = QString("flights_batch_%1").arg(i, 3, 10, QChar('0'));
        sql += QString("SELECT id, `航班号`, `航空公司`, `出发城市`, `到达城市`, "
                      "DATE_FORMAT(`起飞时间`, '%%H:%%i') as depart_time, "
                      "DATE_FORMAT(`到达时间`, '%%H:%%i') as arrive_time, "
                      "`成人价格`, `飞行时长`, `机型`, `出发机场`, `到达机场` "
                      "FROM %1 WHERE 1=1").arg(tableName);
        
        if (!departCity.isEmpty()) {
            QString safeDepartCity = departCity;
            safeDepartCity.replace("'", "''");
            sql += QString(" AND `出发城市` LIKE '%%1%'").arg(safeDepartCity);
        }
        
        if (!arriveCity.isEmpty()) {
            QString safeArriveCity = arriveCity;
            safeArriveCity.replace("'", "''");
            sql += QString(" AND `到达城市` LIKE '%%1%'").arg(safeArriveCity);
        }
    }
    
    sql += " LIMIT 500";

    QSqlQuery query(db);
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "查询失败", "错误：" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        m_tableWidget->insertRow(row);
        
        for (int col = 0; col < 10; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setTextAlignment(Qt::AlignCenter);
            m_tableWidget->setItem(row, col, item);
        }
        
        row++;
    }
    
    qDebug() << "加载了" << row << "条航班数据";
}

void FlightAdminPanel::onSearchClicked()
{
    QString departCity = m_departCityEdit->text().trimmed();
    QString arriveCity = m_arriveCityEdit->text().trimmed();
    
    loadFlightData(departCity, arriveCity);
}

void FlightAdminPanel::onRefreshClicked()
{
    m_departCityEdit->clear();
    m_arriveCityEdit->clear();
    loadFlightData();
    QMessageBox::information(this, "提示", "数据已刷新");
}

void FlightAdminPanel::onAddFlightClicked()
{
    QMessageBox::information(this, "提示", "当前数据库使用批次表，暂不支持添加功能");
}

void FlightAdminPanel::onEditFlightClicked()
{
    QMessageBox::information(this, "提示", "当前数据库使用批次表，暂不支持编辑功能");
}

void FlightAdminPanel::onDeleteFlightClicked()
{
    QMessageBox::information(this, "提示", "当前数据库使用批次表，暂不支持删除功能");
}

void FlightAdminPanel::onTableCellDoubleClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    QMessageBox::information(this, "提示", "当前数据库使用批次表，暂不支持编辑功能");
}
