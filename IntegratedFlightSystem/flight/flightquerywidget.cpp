#include "FlightQueryWidget.h"
#include "ui_FlightQueryWidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QHeaderView>
#include <QFont>
#include <QColor>

FlightQueryWidget::FlightQueryWidget(int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightQueryWidget)
    , m_userId(userId)
{
    ui->setupUi(this);
    initDB();
    loadAllFlights();
    this->setFixedSize(1050,519);
    connect(ui->flightTable, &QTableWidget::cellDoubleClicked,
            this, &FlightQueryWidget::on_flightTable_cellDoubleClicked);
}

FlightQueryWidget::~FlightQueryWidget()
{
    QSqlDatabase db = QSqlDatabase::database("flight_query_connection");
    if (db.isOpen()) {
        db.close();
    }
    QString connName = db.connectionName();
    QSqlDatabase::removeDatabase(connName);
    delete ui;
}

void FlightQueryWidget::initDB()
{
    if (QSqlDatabase::contains("flight_query_connection")) {
        QSqlDatabase::removeDatabase("flight_query_connection");
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "flight_query_connection");
    db.setHostName("localhost");
    db.setDatabaseName("flight_db");
    db.setUserName("root");
    db.setPassword("WSYF2598174725");
    db.setPort(3306);

}

void FlightQueryWidget::loadFlightData(const QString &depart, const QString &dest, const QDate &date)
{
    ui->flightTable->setRowCount(0);

    QSqlDatabase db = QSqlDatabase::database("flight_query_connection");
    if (!db.isOpen()) {
        initDB();
        if (!db.isOpen()) return;
    }

    QSqlQuery query(db);
    QString sql = "SELECT id, 航班号, 航空公司, 出发城市, 出发机场, "
                  "起飞时间, 到达城市, 到达机场, 到达时间, "
                  "机型, 飞行时长, 总座位数, 剩余座位数 "
                  "FROM flights WHERE 1=1 ";

    if (!depart.isEmpty()) {
        sql += "AND 出发城市 LIKE ? ";
    }
    if (!dest.isEmpty()) {
        sql += "AND 到达城市 LIKE ? ";
    }
    if (date.isValid()) {
        sql += "AND DATE(起飞时间) = ? ";
    }
    sql += "ORDER BY id";

    query.prepare(sql);
    int paramIdx = 0;
    if (!depart.isEmpty()) {
        query.addBindValue("%" + depart + "%");
        paramIdx++;
    }
    if (!dest.isEmpty()) {
        query.addBindValue("%" + dest + "%");
        paramIdx++;
    }
    if (date.isValid()) {
        query.addBindValue(date.toString("yyyy-MM-dd"));
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "错误", "航班查询失败：" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->flightTable->insertRow(row);

        QString flightId = QString::number(query.value("id").toInt());
        QString flightNum = query.value("航班号").toString();
        QString airline = query.value("航空公司").toString();
        QString departCity = query.value("出发城市").toString();
        QString departAirport = query.value("出发机场").toString();
        QString departTime = query.value("起飞时间").toDateTime().toString("yyyy-MM-dd HH:mm");
        QString arriveCity = query.value("到达城市").toString();
        QString arriveAirport = query.value("到达机场").toString();
        QString arriveTime = query.value("到达时间").toDateTime().toString("yyyy-MM-dd HH:mm");
        QString planeType = query.value("机型").toString();
        QString flightTime = QString::number(query.value("飞行时长").toInt());
        QString totalSeats = QString::number(query.value("总座位数").toInt());
        QString remainSeats = QString::number(query.value("剩余座位数").toInt());

        ui->flightTable->setItem(row, 0, new QTableWidgetItem(flightId));
        ui->flightTable->setItem(row, 1, new QTableWidgetItem(flightNum));
        ui->flightTable->setItem(row, 2, new QTableWidgetItem(airline));
        ui->flightTable->setItem(row, 3, new QTableWidgetItem(departCity));
        ui->flightTable->setItem(row, 4, new QTableWidgetItem(departAirport));
        ui->flightTable->setItem(row, 5, new QTableWidgetItem(departTime));
        ui->flightTable->setItem(row, 6, new QTableWidgetItem(arriveCity));
        ui->flightTable->setItem(row, 7, new QTableWidgetItem(arriveAirport));
        ui->flightTable->setItem(row, 8, new QTableWidgetItem(arriveTime));
        ui->flightTable->setItem(row, 9, new QTableWidgetItem(planeType));
        ui->flightTable->setItem(row, 10, new QTableWidgetItem(flightTime));
        ui->flightTable->setItem(row, 11, new QTableWidgetItem(totalSeats));
        ui->flightTable->setItem(row, 12, new QTableWidgetItem(remainSeats));

        if (query.value("剩余座位数").toInt() < 50) {
            ui->flightTable->item(row, 12)->setForeground(QColor("#FF4444"));
            ui->flightTable->item(row, 12)->setFont(QFont("微软雅黑", 10, QFont::Bold));
        }

        row++;
    }

    ui->flightTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->flightTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void FlightQueryWidget::loadAllFlights()
{
    loadFlightData("", "", QDate());
    ui->edit_depart->clear();
    ui->edit_dest->clear();

}

void FlightQueryWidget::on_btn_queryFlight_clicked()
{
    QString depart = ui->edit_depart->text().trimmed();
    QString dest = ui->edit_dest->text().trimmed();
    QDate date = ui->dateEdit->date();
    loadFlightData(depart, dest, date);
}

void FlightQueryWidget::on_btn_showAllFlights_clicked()
{
    loadAllFlights();
    QMessageBox::information(this, "提示", "已显示所有航班");
}
void FlightQueryWidget::on_flightTable_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem* idItem = ui->flightTable->item(row, 0);
    if (!idItem || idItem->text().isEmpty()) {
        QMessageBox::warning(this, "提示", "未获取到有效航班ID！");
        return;
    }
    int flightId = idItem->text().toInt();

    FlightDetailWidget* detailWidget = new FlightDetailWidget(flightId, this);
    detailWidget->exec();
}
