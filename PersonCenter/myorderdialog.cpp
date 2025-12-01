#include "myorderdialog.h"
#include "ui_myorderdialog.h"
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>

MyOrderDialog::MyOrderDialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOrderDialog)
{
    ui->setupUi(this);
    setWindowTitle("我的订单");
    resize(800, 500);
    m_userId = userId;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
    db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");

    if (!db.open()) {
        QMessageBox::warning(this, "Error", "ODBC connect failed: " + db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");

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
    QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
    btnLayout->setSpacing(10);
    btnLayout->addWidget(ui->allOrderBtn);
    btnLayout->addWidget(ui->upcomingOrderBtn);
    btnLayout->addWidget(ui->finishedOrderBtn);
    btnLayout->addWidget(ui->cancelledOrderBtn);
    mainLayout->addWidget(btnWidget);

    ui->orderTable->setStyleSheet(R"(
        QTableWidget {
            background: white;
            border: 1px solid #e0e0e0;
            border-radius: 8px;
            padding: 5px;
            gridline-color: #f0f0f0;
        }
        QHeaderView::section {
            background: #f8f9fa;
            font-weight: bold;
            color: #333;
            padding: 8px;
            border: none;
            border-bottom: 1px solid #e0e0e0;
        }
        QTableWidget::item:even { background: #fcfcfc; }
        QTableWidget::item:odd { background: #f9f9f9; }
        QTableWidget::item:hover { background: #e6f7ff; }
        QTableWidget::item { padding: 6px; color: #333; }
    )");
    mainLayout->addWidget(ui->orderTable);
    mainLayout->setStretchFactor(ui->orderTable, 1);

    ui->orderTable->setWordWrap(true);
    ui->orderTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->orderTable->setColumnWidth(0, 120);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->orderTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->orderTable->setColumnWidth(5, 120);
}

void MyOrderDialog::updateBtnStyle(QPushButton *selectedBtn)
{
    QString defaultStyle = "background:transparent;color:#333;border:none;padding:4px 12px;";
    ui->allOrderBtn->setStyleSheet(defaultStyle);
    ui->upcomingOrderBtn->setStyleSheet(defaultStyle);
    ui->finishedOrderBtn->setStyleSheet(defaultStyle);
    ui->cancelledOrderBtn->setStyleSheet(defaultStyle);

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

    QSqlQuery query;
    QString sql = "SELECT order_id, flight_num, depart_time, HEX(destination) AS dest_hex, HEX(status) AS status_hex FROM `order` WHERE user_id=?";

    if (status != "全部订单") {
        sql += " AND status=UNHEX(?)";
        query.prepare(sql);
        query.addBindValue(m_userId);
        query.addBindValue(status.toUtf8().toHex());
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

        QString destHex = query.value("dest_hex").toString();
        QByteArray destBytes = QByteArray::fromHex(destHex.toUtf8());
        QString destination = QString::fromUtf8(destBytes);

        QString statusHex = query.value("status_hex").toString();
        QByteArray statusBytes = QByteArray::fromHex(statusHex.toUtf8());
        QString orderStatus = QString::fromUtf8(statusBytes);

        ui->orderTable->setItem(row, 0, new QTableWidgetItem(orderId));
        ui->orderTable->setItem(row, 1, new QTableWidgetItem(flightNum));
        ui->orderTable->setItem(row, 2, new QTableWidgetItem(departTime));
        ui->orderTable->setItem(row, 3, new QTableWidgetItem(destination));

        QTableWidgetItem *statusItem = new QTableWidgetItem(orderStatus);
        if (orderStatus == "待出行") statusItem->setForeground(QColor("#FF6700"));
        else if (orderStatus == "已完成") statusItem->setForeground(QColor("#32CD32"));
        else if (orderStatus == "已取消") statusItem->setForeground(QColor("#888888"));
        ui->orderTable->setItem(row, 4, statusItem);

        if (orderStatus == "待出行") {
            QPushButton *cancelBtn = new QPushButton("取消订单");
            cancelBtn->setStyleSheet("background:#FF4444;color:white;border:none;border-radius:4px;padding:4px;");
            cancelBtn->setObjectName("cancel_" + orderId);

            QWidget *btnWidget = new QWidget();
            QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
            btnLayout->addWidget(cancelBtn);
            btnLayout->setContentsMargins(5, 2, 5, 2);
            ui->orderTable->setCellWidget(row, 5, btnWidget);

            connect(cancelBtn, &QPushButton::clicked, this, &MyOrderDialog::onCancelOrderClicked);
        } else {
            ui->orderTable->setItem(row, 5, new QTableWidgetItem(""));
        }

        row++;
    }
}

void MyOrderDialog::onCancelOrderClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString orderId = btn->objectName().split("_").last();

    if (QMessageBox::question(this, "Confirm", "Cancel order " + orderId + "?") != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    QString newStatus = "已取消";
    QByteArray statusUtf8 = newStatus.toUtf8();

    query.prepare("UPDATE `order` SET status=? WHERE order_id=? AND user_id=?");
    query.addBindValue(statusUtf8);
    query.addBindValue(orderId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Order cancelled successfully!");
        if (ui->allOrderBtn->styleSheet().contains("background:#FF6700")) {
            loadOrderData("全部订单");
        } else if (ui->upcomingOrderBtn->styleSheet().contains("background:#FF6700")) {
            loadOrderData("待出行");
        } else if (ui->finishedOrderBtn->styleSheet().contains("background:#FF6700")) {
            loadOrderData("已完成");
        } else if (ui->cancelledOrderBtn->styleSheet().contains("background:#FF6700")) {
            loadOrderData("已取消");
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to cancel order: " + query.lastError().text());
    }
}
