#include "FlightDetailWidget.h"
#include "ui_FlightDetailWidget.h"
#include "databasemanager.h"
#include <QFont>
#include <QColor>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QSpacerItem>

FlightDetailWidget::FlightDetailWidget(int flightId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightDetailWidget)
    , m_flightId(flightId)
{
    ui->setupUi(this);
    this->setWindowTitle("航班详情");
    this->setFixedSize(850, 700);
    initStyle();
    loadFlightDetail();
}

FlightDetailWidget::~FlightDetailWidget()
{
    delete ui;
}

void FlightDetailWidget::initStyle()
{
    // 全局样式
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f8f9fa;
        }
        /* 标题栏样式 */
        QLabel#titleLabel {
            font-size: 20px;
            font-weight: bold;
            color: #2c3e50;
            margin-bottom: 10px;
        }
        /* 卡片容器样式 */
        QWidget#cardWidget {
            background-color: white;
            border-radius: 12px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.08);
            padding: 20px;
            margin-bottom: 15px;
        }
        /* 分组标题样式 */
        QLabel#groupTitle {
            font-size: 16px;
            font-weight: bold;
            color: #34495e;
            padding-bottom: 10px;
            border-bottom: 2px solid #e6f7ff;
            margin-bottom: 15px;
        }
        /* 标签样式 */
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
        /* 剩余座位警告样式 */
        QLabel#warnLabel {
            font-size: 14px;
            color: #e74c3c;
            font-weight: bold;
        }
        /* 分割线 */
        QFrame#line {
            background-color: #ecf0f1;
            height: 1px;
            margin: 10px 0;
        }
    )");
}

void FlightDetailWidget::loadFlightDetail()
{
    DatabaseManager* dbManager = DatabaseManager::instance();
    if (!dbManager->isDatabaseConnected(DatabaseManager::FlightDB)) {
        QMessageBox::critical(this, "错误", "航班数据库未连接");
        return;
    }

    QSqlQuery query = dbManager->createQuery(DatabaseManager::FlightDB);
    QString sql = R"(
        SELECT id, 航段序号, 航空公司代码, 航空公司, 飞行时长, 航班号,
               出发城市, 出发机场, 出发航站楼, 起飞时间, 到达城市, 到达机场,
               到达航站楼, 到达时间, 机型, 机型代码, 实际承运, 成人价格,
               儿童价格, 数据来源, 总座位数, 剩余座位数, 创建时间
        FROM flights WHERE id = ?
    )";

    query.prepare(sql);
    query.addBindValue(m_flightId);

    if (!query.exec()) {
        QMessageBox::warning(this, "查询错误", "航班详情查询失败：" + query.lastError().text());
        return;
    }

    if (query.next()) {
        // 1. 基础信息
        ui->lbFlightId->setText(QString::number(query.value("id").toInt()));
        ui->lbFlightNo->setText(query.value("航班号").toString());
        ui->lbAirline->setText(query.value("航空公司").toString());
        ui->lbSegmentNo->setText(QString::number(query.value("航段序号").toInt()));
        ui->lbPlaneType->setText(query.value("机型").toString());
        ui->lbFlightTime->setText(QString::number(query.value("飞行时长").toInt()) + " 分钟");

        // 2. 起降信息
        ui->lbDepartCity->setText(query.value("出发城市").toString());
        ui->lbDepartAirport->setText(query.value("出发机场").toString());
        ui->lbDepartTime->setText(query.value("起飞时间").toDateTime().toString("yyyy-MM-dd HH:mm:ss"));

        ui->lbArriveCity->setText(query.value("到达城市").toString());
        ui->lbArriveAirport->setText(query.value("到达机场").toString());
        ui->lbArriveTime->setText(query.value("到达时间").toDateTime().toString("yyyy-MM-dd HH:mm:ss"));

        // 3. 价格/座位信息
        ui->lbAdultPrice->setText(QString::number(query.value("成人价格").toDouble(), 'f', 2) + " 元");
        ui->lbChildPrice->setText(QString::number(query.value("儿童价格").toDouble(), 'f', 2) + " 元");
        ui->lbTotalSeats->setText(QString::number(query.value("总座位数").toInt()));

        // 剩余座位（少于50高亮警告）
        int remainSeats = query.value("剩余座位数").toInt();
        if (remainSeats < 50) {
            ui->lbRemainSeats->setObjectName("warnLabel");
            ui->lbRemainSeats->setText(QString::number(remainSeats) + " （座位紧张）");
        } else {
            ui->lbRemainSeats->setText(QString::number(remainSeats));
        }

    } else {
        QMessageBox::information(this, "提示", "未找到ID为" + QString::number(m_flightId) + "的航班数据");
    }
}
