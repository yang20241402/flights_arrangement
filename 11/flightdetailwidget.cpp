#include "FlightDetailWidget.h"
#include "ui_FlightDetailWidget.h"
#include <QFont>
#include <QColor>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QSpacerItem>

FlightDetailWidget::FlightDetailWidget(const FlightInfo& flightInfo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightDetailWidget)
    , m_flightInfo(flightInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("航班详情");
    this->setFixedSize(850, 700);

    // 初始化操作
    initDB();
    initStyle();
    loadFlightDetail();
}

FlightDetailWidget::~FlightDetailWidget()
{
    delete ui; // 不再手动关闭数据库连接（全局连接由创建者管理）
}

void FlightDetailWidget::initDB()
{
    m_db = QSqlDatabase::database("plane_db_conn");

    // 检查连接状态
    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "数据库错误",
                              "连接失败：" + m_db.lastError().text());
        return;
    }

    // 设置字符编码
    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4");
}

void FlightDetailWidget::initStyle()
{
    // 保持与FlightItemWidget一致的样式表
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f8f9fa;
        }
        QLabel#titleLabel {
            font-size: 20px;
            font-weight: bold;
            color: #2c3e50;
            margin-bottom: 10px;
        }
        QWidget#cardWidget {
            background-color: white;
            border-radius: 12px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.08);
            padding: 20px;
            margin-bottom: 15px;
        }
        QLabel#groupTitle {
            font-size: 16px;
            font-weight: bold;
            color: #34495e;
            padding-bottom: 10px;
            border-bottom: 2px solid #e6f7ff;
            margin-bottom: 15px;
        }
        QLabel#labelKey {
            font-size: 14px;
            color: #7f8c8d;
            min-width: 120px;
        }
        QLabel#labelValue {
            font-size: 14px;
            color: #2c3e50;
            font-weight: 500;
        }
        QLabel#warnLabel {
            font-size: 14px;
            color: #e74c3c;
            font-weight: bold;
        }
        QFrame#line {
            background-color: #ecf0f1;
            height: 1px;
            margin: 10px 0;
        }
    )");
}

void FlightDetailWidget::loadFlightDetail()
{
    if (!m_db.isOpen()) {
        return;
    }

    // 使用航班号查询详情（替代原flightID方式）
    QSqlQuery query(m_db);
    QString sql = R"(
    SELECT id, flight_no, airline, plane_type, depart_city, arrive_city,
           depart_airport, arrive_airport, depart_time, arrive_time,
           is_next_day, price, price_int, duration, economy_price, business_price, first_price,
           economy_remain, business_remain, first_remain, remain_tickets, on_time_rate, flight_date
    FROM flight_info WHERE flight_no = ?
)";

    query.prepare(sql);
    query.addBindValue(m_flightInfo.flightNo); // 使用航班号作为查询条件

    if (!query.exec()) {
        QMessageBox::warning(this, "查询错误",
                             "航班详情查询失败：" + query.lastError().text());
        return;
    }

    if (query.next()) {
        // 1. 基础信息
        ui->lbFlightId->setText(QString::number(query.value("id").toInt()));
        ui->lbFlightNo->setText(query.value("flight_no").toString());
        ui->lbAirline->setText(query.value("airline").toString());
        ui->lbPlaneType->setText(query.value("plane_type").toString());

        // 航班类型转换（0=国内，1=国际等，根据实际业务调整）
        int flightType = query.value("flight_type").toInt();
        ui->lbFlightType->setText(flightType == 0 ? "国内航班" : "国际航班");


        // 2. 起降信息
        ui->lbDepartCity->setText(query.value("depart_city").toString());
        ui->lbArriveCity->setText(query.value("arrive_city").toString());
        ui->lbDepartAirport->setText(query.value("depart_airport").toString());
        ui->lbArriveAirport->setText(query.value("arrive_airport").toString());
        ui->lbDepartTime->setText(query.value("depart_time").toString());
        ui->lbArriveTime->setText(query.value("arrive_time").toString());
        ui->lbIsNextDay->setText(query.value("is_next_day").toInt() == 1 ? "+1日" : "");
        ui->lbFlightDate->setText(query.value("flight_date").toDate().toString("yyyy-MM-dd"));
        ui->lbDuration->setText(QString::number(query.value("duration").toInt()) + " 分钟");

        // 4. 价格信息
        ui->lbPrice->setText(QString::number(query.value("price").toDouble(), 'f', 2) + " 元");
        ui->lbPriceInt->setText(QString::number(query.value("price_int").toInt()) + " 元");
        ui->lbEconomyPrice->setText(QString::number(query.value("economy_price").toInt()) + " 元");
        ui->lbBusinessPrice->setText(QString::number(query.value("business_price").toInt()) + " 元");
        ui->lbFirstPrice->setText(QString::number(query.value("first_price").toInt()) + " 元");

        // 5. 余票信息
        ui->lbEconomyRemain->setText(QString::number(query.value("economy_remain").toInt()));
        ui->lbBusinessRemain->setText(QString::number(query.value("business_remain").toInt()));
        ui->lbFirstRemain->setText(QString::number(query.value("first_remain").toInt()));
        ui->lbRemainTickets->setText(query.value("remain_tickets").toString());

        // 余票警告处理
        int economyRemain = query.value("economy_remain").toInt();
        if (economyRemain <= 5) {
            ui->lbEconomyRemain->setObjectName("warnLabel");
            ui->lbEconomyRemain->setText(QString::number(economyRemain) + " （余票紧张）");
        }

    } else {
        QMessageBox::information(this, "提示",
                                 "未找到航班号为" + m_flightInfo.flightNo + "的航班数据");
    }
}
