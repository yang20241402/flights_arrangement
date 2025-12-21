#include "flightitemwidget.h"
#include "ui_flightitemwidget.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QEnterEvent>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "flightdetailwidget.h"

FlightItemWidget::FlightItemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlightItemWidget)
{
    ui->setupUi(this);

    this->setStyleSheet(R"(
        FlightItemWidget {
            background-color: white;
            border: 1px solid #e0e0e0;
            border-radius: 8px;
            box-shadow: 0 1px 2px rgba(0,0,0,0.05);
            padding: 5px;
            transition: all 0.2s ease;
        }
        FlightItemWidget:hover {
            border-color: #b0b0b0;
            box-shadow: 0 6px 12px rgba(0,0,0,0.1);
            transform: translateY(-2px);
        }
    )");

    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setCursor(Qt::PointingHandCursor);

    ui->labelNextDay->setVisible(false);
    ui->labelPrice->setStyleSheet("color: #3a84ee;");
    ui->Airname->setStyleSheet("color: #4186ea;");
}

FlightItemWidget::~FlightItemWidget()
{
    delete ui;
}

void FlightItemWidget::setFlightInfo(const FlightInfo &info)
{
    ui->labelLogo->setPixmap(QPixmap(info.logo).scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelAirline->setText(QString("%1").arg(info.airline));
    ui->Airname->setText(QString("%1 %2").arg(info.flightNo).arg(info.planeType));

    ui->labelDepartTime->setText(info.departTime);
    ui->labelArriveTime->setText(info.arriveTime);
    ui->labelNextDay->setVisible(info.isNextDay);
    ui->labelDepartAirport->setText(QString("%1").arg(info.departAirport).arg(info.arriveAirport));
    ui->labelArriveAirport->setText(QString("%1").arg(info.arriveAirport));
    QString durationStr = QString::number(info.duration);
    durationStr=durationStr+"min";
    ui->duration->setText(durationStr);

    ui->labelPrice->setText(QString("¥%1起").arg(info.price));

    m_flightNo = info.flightNo;

    m_flightInfo = info;
    updateCabinPrice(0);
}

void FlightItemWidget::updateCabinPrice(int cabinType)
{
    QString priceText;
    QString remainText;

    switch (cabinType) {
    case 0:
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("总余票：%1").arg(m_flightInfo.remain);
        break;
    case 1:
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("余票：%1").arg(m_flightInfo.economyRemain);
        break;
    case 2:
        if (m_flightInfo.businessPrice <= 0) {
            priceText = "暂未开放";
            remainText = "无票";
        } else {
            priceText = QString("¥%1起").arg(m_flightInfo.businessPrice);
            remainText = QString("余票：%1").arg(m_flightInfo.businessRemain);
        }
        break;
    case 3:
        if (m_flightInfo.firstPrice <= 0) {
            priceText = "暂未开放";
            remainText = "无票";
        } else {
            priceText = QString("¥%1起").arg(m_flightInfo.firstPrice);
            remainText = QString("余票：%1").arg(m_flightInfo.firstRemain);
        }
        break;
    default:
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("总余票：%1").arg(m_flightInfo.remain);
        break;
    }

    ui->labelPrice->setText(priceText);
    ui->labelremain->setText(remainText);

    int remain = 0;
    if (cabinType == 0) remain = m_flightInfo.remain;
    else if (cabinType == 1) remain = m_flightInfo.economyRemain;
    else if (cabinType == 2) remain = m_flightInfo.businessRemain;
    else if (cabinType == 3) remain = m_flightInfo.firstRemain;

    if (remain <= 0) {
        ui->labelremain->setStyleSheet("color: #999999;");
    } else if (remain <= 5) {
        ui->labelremain->setStyleSheet("color: #ff4444;");
    } else {
        ui->labelremain->setStyleSheet("color: #333333;");
    }
}

void FlightItemWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        FlightDetailWidget* detailWidget = new FlightDetailWidget(m_flightInfo, this);
        detailWidget->show();
    }
    QWidget::mousePressEvent(event);
}
