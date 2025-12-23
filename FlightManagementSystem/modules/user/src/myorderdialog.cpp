#include "myorderdialog.h"
#include "ui_myorderdialog.h"
#include "databasemanager.h"
#include "changeticketwidget.h"
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

MyOrderDialog::MyOrderDialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOrderDialog)
{
    ui->setupUi(this);
    setWindowTitle("我的订单");
    resize(800, 500);
    m_userId = userId;

    initLayout();
    on_allOrderBtn_clicked();
}

MyOrderDialog::~MyOrderDialog()
{
    delete ui;
}

void MyOrderDialog::initLayout()
{
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());
    if (!mainLayout) {
        mainLayout = new QVBoxLayout(this);
        setLayout(mainLayout);
    }

    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(15);

    QWidget *btnWidget = new QWidget();
    btnWidget->setStyleSheet("background: #f8f9fa; border-radius: 8px 8px 0 0;");
    QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
    btnLayout->setContentsMargins(10, 0, 10, 0);
    btnLayout->setSpacing(0);

    QString tabBtnStyle = R"(
        QPushButton {
            background: transparent;
            color: #666;
            border: none;
            padding: 10px 20px;
            font-size: 14px;
            border-radius: 4px 4px 0 0;
        }
        QPushButton:hover {
            color: #FF6700;
        }
    )";
    QString selectedStyle = R"(
        QPushButton {
            background: white;
            color: #FF6700;
            font-weight: bold;
            border: 1px solid #e0e0e0;
            border-bottom: none;
            padding: 10px 20px;
            border-radius: 4px 4px 0 0;
        }
    )";

    ui->allOrderBtn->setStyleSheet(tabBtnStyle);
    ui->upcomingOrderBtn->setStyleSheet(tabBtnStyle);
    ui->finishedOrderBtn->setStyleSheet(tabBtnStyle);
    ui->cancelledOrderBtn->setStyleSheet(tabBtnStyle);
    if (ui->unpaidOrderBtn) {
        ui->unpaidOrderBtn->setStyleSheet(tabBtnStyle);
    }

    btnLayout->addWidget(ui->allOrderBtn);
    if (ui->unpaidOrderBtn) {
        btnLayout->addWidget(ui->unpaidOrderBtn);
    }
    btnLayout->addWidget(ui->upcomingOrderBtn);
    btnLayout->addWidget(ui->finishedOrderBtn);
    btnLayout->addWidget(ui->cancelledOrderBtn);
    mainLayout->addWidget(btnWidget);

    ui->orderTable->setStyleSheet(R"(
        QTableWidget {
            background: white;
            border: 1px solid #e0e0e0;
            border-radius: 0 0 8px 8px;
            padding: 5px;
            gridline-color: #f0f0f0;
        }
        QHeaderView::section {
            background: white;
            font-weight: bold;
            color: #333;
            padding: 10px;
            border: none;
            border-bottom: 1px solid #f0f0f0;
        }
        QTableWidget::item:even { background: #fcfcfc; }
        QTableWidget::item:odd { background: #f9f9f9; }
        QTableWidget::item:hover { background: #e6f7ff; }
        QTableWidget::item {
            padding: 10px;
            color: #333;
            border: none;
        }
        QTableWidget::item:selected {
            background: #fff5e6;
            color: #FF6700;
        }
    )");
    mainLayout->addWidget(ui->orderTable);
    mainLayout->setStretchFactor(ui->orderTable, 1);

    ui->orderTable->setWordWrap(true);
    ui->orderTable->verticalHeader()->setVisible(false); // 隐藏行号
    ui->orderTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 行高自适应

    ui->orderTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->orderTable->setColumnWidth(0, 100);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->orderTable->setColumnWidth(4, 80);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->orderTable->setColumnWidth(5, 180);
}

void MyOrderDialog::updateBtnStyle(QPushButton *selectedBtn)
{
    QString defaultStyle = "background:transparent;color:#333;border:none;padding:4px 12px;";
    ui->allOrderBtn->setStyleSheet(defaultStyle);
    ui->upcomingOrderBtn->setStyleSheet(defaultStyle);
    ui->finishedOrderBtn->setStyleSheet(defaultStyle);
    ui->cancelledOrderBtn->setStyleSheet(defaultStyle);
    ui->unpaidOrderBtn->setStyleSheet(defaultStyle); // 新增：未支付按钮样式重置

    QString selectedStyle = "background:#FF6700;color:white;border-radius:4px;padding:4px 12px;";
    selectedBtn->setStyleSheet(selectedStyle);
}

void MyOrderDialog::on_allOrderBtn_clicked()
{
    updateBtnStyle(ui->allOrderBtn);
    loadOrderData("全部订单");
}

void MyOrderDialog::on_upcomingOrderBtn_clicked()
{
    updateBtnStyle(ui->upcomingOrderBtn);
    loadOrderData("待出行");
}

void MyOrderDialog::on_finishedOrderBtn_clicked()
{
    updateBtnStyle(ui->finishedOrderBtn);
    loadOrderData("已完成");
}

void MyOrderDialog::on_cancelledOrderBtn_clicked()
{
    updateBtnStyle(ui->cancelledOrderBtn);
    loadOrderData("已取消");
}

void MyOrderDialog::loadOrderData(const QString &status)
{
    ui->orderTable->setRowCount(0);

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    QString sql = "SELECT order_id, flight_num, depart_time, destination, status FROM `order` WHERE user_id=?";

    if (status != "全部订单") {
        sql += " AND status=?";
        query.prepare(sql);
        query.addBindValue(m_userId);
        query.addBindValue(status);
    } else {
        query.prepare(sql);
        query.addBindValue(m_userId);
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Order query failed: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->orderTable->insertRow(row);

        QString orderId = query.value("order_id").toString();
        QString flightNum = query.value("flight_num").toString();
        QString departTime = query.value("depart_time").toDateTime().toString("yyyy-MM-dd HH:mm");

        QString destination = query.value("destination").toString();
        QString orderStatus = query.value("status").toString();

        ui->orderTable->setItem(row, 0, new QTableWidgetItem(orderId));
        ui->orderTable->setItem(row, 1, new QTableWidgetItem(flightNum));
        ui->orderTable->setItem(row, 2, new QTableWidgetItem(departTime));
        ui->orderTable->setItem(row, 3, new QTableWidgetItem(destination));

        QTableWidgetItem *statusItem = new QTableWidgetItem(orderStatus);
        if (orderStatus == "待出行") {
            statusItem->setForeground(QColor("#FF6700"));
        } else if (orderStatus == "已完成") {
            statusItem->setForeground(QColor("#32CD32"));
        } else if (orderStatus == "已取消") {
            statusItem->setForeground(QColor("#888888"));
        } else if (orderStatus == "未支付") {
            statusItem->setForeground(QColor("#FF4444"));
        }
        ui->orderTable->setItem(row, 4, statusItem);

        QWidget *btnWidget = new QWidget();
        QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
        btnLayout->setContentsMargins(5, 2, 5, 2);
        btnLayout->setSpacing(5);

        if (orderStatus == "未支付") {
            QPushButton *payBtn = new QPushButton("支付订单");
            payBtn->setStyleSheet("background:#409EFF;color:white;border:none;border-radius:4px;padding:4px 8px;");
            payBtn->setObjectName("pay_" + orderId);
            connect(payBtn, &QPushButton::clicked, this, &MyOrderDialog::onPayOrderClicked);

            QPushButton *cancelBtn = new QPushButton("取消订单");
            cancelBtn->setStyleSheet("background:#FF4444;color:white;border:none;border-radius:4px;padding:4px 8px;");
            cancelBtn->setObjectName("cancel_" + orderId);
            connect(cancelBtn, &QPushButton::clicked, this, &MyOrderDialog::onCancelOrderClicked);

            btnLayout->addWidget(payBtn);
            btnLayout->addWidget(cancelBtn);
        } else if (orderStatus == "待出行") {
            QPushButton *changeBtn = new QPushButton("改签");
            changeBtn->setStyleSheet("background:#13C2C2;color:white;border:none;border-radius:4px;padding:4px 8px;");
            changeBtn->setObjectName("change_" + orderId);
            connect(changeBtn, &QPushButton::clicked, this, &MyOrderDialog::onChangeOrderClicked);

            QPushButton *cancelBtn = new QPushButton("取消订单");
            cancelBtn->setStyleSheet("background:#FF4444;color:white;border:none;border-radius:4px;padding:4px;");
            cancelBtn->setObjectName("cancel_" + orderId);
            connect(cancelBtn, &QPushButton::clicked, this, &MyOrderDialog::onCancelOrderClicked);

            btnLayout->addWidget(changeBtn);
            btnLayout->addWidget(cancelBtn);
        }

        ui->orderTable->setCellWidget(row, 5, btnWidget);
        row++;
    }

    if (ui->orderTable->rowCount() == 0) {
        ui->orderTable->insertRow(0);
        QTableWidgetItem *emptyItem = new QTableWidgetItem("暂无" + status + "订单");
        emptyItem->setForeground(QColor("#888888"));
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->orderTable->setSpan(0, 0, 1, 6);
        ui->orderTable->setItem(0, 0, emptyItem);
    }
}

void MyOrderDialog::on_unpaidOrderBtn_clicked()
{
    updateBtnStyle(ui->unpaidOrderBtn);
    loadOrderData("未支付");
}

void MyOrderDialog::onPayOrderClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString orderId = btn->objectName().split("_").last();

    if (QMessageBox::question(this, "Confirm", "是否确认支付订单 " + orderId + "？",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    QString newStatus = "待出行";
    QByteArray statusUtf8 = newStatus.toUtf8();

    query.prepare("UPDATE `order` SET status=? WHERE order_id=? AND user_id=?");
    query.addBindValue(statusUtf8);
    query.addBindValue(orderId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "订单支付成功！状态已更新为待出行");
        if (ui->allOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("全部订单");
        else if (ui->upcomingOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("待出行");
        else if (ui->cancelledOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("已取消");
        else if (ui->finishedOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("已完成");
    } else {
        QMessageBox::warning(this, "Error", "支付订单失败: " + query.lastError().text());
    }
}

void MyOrderDialog::onCancelOrderClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString orderId = btn->objectName().split("_").last();

    if (QMessageBox::question(this, "Confirm", "是否确认取消订单 " + orderId + "？",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    QString newStatus = "已取消";
    QByteArray statusUtf8 = newStatus.toUtf8();

    query.prepare("UPDATE `order` SET status=? WHERE order_id=? AND user_id=?");
    query.addBindValue(statusUtf8);
    query.addBindValue(orderId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "订单取消成功！");
        if (ui->allOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("全部订单");
        else if (ui->upcomingOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("待出行");
        else if (ui->cancelledOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("已取消");
        else if (ui->finishedOrderBtn->styleSheet().contains("background:#FF6700")) loadOrderData("已完成");
    } else {
        QMessageBox::warning(this, "Error", "取消订单失败: " + query.lastError().text());
    }
}

void MyOrderDialog::onChangeOrderClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString orderId = btn->objectName().split("_").last();
    
    qDebug() << "=== 点击改签按钮 ===";
    qDebug() << "订单号：" << orderId;
    
    // 从数据库查询订单信息
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }
    
    QSqlQuery query(db);
    query.prepare("SELECT flight_num, depart_time, destination FROM `order` WHERE order_id=? AND user_id=?");
    query.addBindValue(orderId);
    query.addBindValue(m_userId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法获取订单信息");
        return;
    }
    
    QString flightNum = query.value("flight_num").toString();
    QDateTime departTime = query.value("depart_time").toDateTime();
    QString destination = query.value("destination").toString();
    
    qDebug() << "订单信息：";
    qDebug() << "  航班号：" << flightNum;
    qDebug() << "  出发时间：" << departTime;
    qDebug() << "  目的地：" << destination;
    
    // 从数据库查询航班的出发城市和到达城市
    QString departCity = "";
    QString arriveCity = destination; // 目的地字段现在存储的是到达城市
    
    // 查询航班批次表获取出发城市
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        QSqlQuery flightQuery(db);
        QString sql = QString("SELECT 出发城市, 到达城市 FROM %1 WHERE 航班号 = ?").arg(tableName);
        
        if (flightQuery.prepare(sql)) {
            flightQuery.addBindValue(flightNum);
            if (flightQuery.exec() && flightQuery.next()) {
                departCity = flightQuery.value("出发城市").toString();
                arriveCity = flightQuery.value("到达城市").toString();
                qDebug() << "从" << tableName << "查询到城市信息：";
                qDebug() << "  出发城市：" << departCity;
                qDebug() << "  到达城市：" << arriveCity;
                break;
            }
        }
    }
    
    if (departCity.isEmpty() || arriveCity.isEmpty()) {
        QMessageBox::warning(this, "错误", "无法获取航班城市信息");
        qDebug() << "错误：无法获取航班城市信息";
        return;
    }
    
    qDebug() << "准备打开改签页面：";
    qDebug() << "  出发城市：" << departCity;
    qDebug() << "  到达城市：" << arriveCity;
    qDebug() << "  航班号：" << flightNum;
    qDebug() << "  日期：" << departTime.date();
    
    // 创建改签窗口，使用独立窗口标志
    ChangeTicketWidget* changeticketwidget = new ChangeTicketWidget(departCity, arriveCity, flightNum, departTime.date(), nullptr);
    changeticketwidget->setAttribute(Qt::WA_DeleteOnClose, true);
    // 使用更强的窗口标志组合，确保窗口在最前面
    changeticketwidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    changeticketwidget->setWindowModality(Qt::ApplicationModal); // 使用应用程序模态，强制置顶
    changeticketwidget->setWindowTitle("航班改签");
    changeticketwidget->resize(1000, 700);
    changeticketwidget->show();
    changeticketwidget->raise();
    changeticketwidget->activateWindow();
}