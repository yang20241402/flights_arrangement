#include "flightitemwidget.h"
#include "ui_flightitemwidget.h"
#include <QPixmap>
#include <QMouseEvent>       // 必须包含，用于QMouseEvent
#include <QEnterEvent>       // 若使用enterEvent/leaveEvent，需包含
#include <QTimer>            // 若使用QTimer实现点击反馈，需包含
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
            border: 1px solid #e0e0e0; /* 默认灰色边框（浅灰，不显眼） */
            border-radius: 8px; /* 圆角让边框更柔和 */
            box-shadow: 0 1px 2px rgba(0,0,0,0.05); /* 轻微阴影，增强层次感 */
            padding: 5px; /* 内边距，避免内容贴边框 */
            transition: all 0.2s ease; /* 动画过渡 */
        }
        FlightItemWidget:hover {
            border-color: #b0b0b0; /* 悬浮时边框加深一点 */
            box-shadow: 0 6px 12px rgba(0,0,0,0.1); /* 悬浮阴影凸起 */
            transform: translateY(-2px); /* 上移凸起 */
        }
    )");

    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setCursor(Qt::PointingHandCursor);

    ui->labelNextDay->setVisible(false);      // 默认隐藏+1天标签
    ui->labelPrice->setStyleSheet("color: #3a84ee;");
    ui->Airname->setStyleSheet("color: #4186ea;");
    ui->btnSelect->setStyleSheet("background-color: #FF6600; color: white; border-radius: 4px; height: 30px; font-weight: bold;");
}

FlightItemWidget::~FlightItemWidget()
{
    delete ui;
}

void FlightItemWidget::setFlightInfo(const FlightInfo &info)
{
    // 1. 左侧信息
    ui->labelLogo->setPixmap(QPixmap(info.logo).scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelAirline->setText(QString("%1").arg(info.airline));
    ui->Airname->setText(QString("%1 %2").arg(info.flightNo).arg(info.planeType));

    // 2. 中间时间和机场
    ui->labelDepartTime->setText(info.departTime);
    ui->labelArriveTime->setText(info.arriveTime);
    ui->labelNextDay->setVisible(info.isNextDay);
    ui->labelDepartAirport->setText(QString("%1").arg(info.departAirport).arg(info.arriveAirport));
    ui->labelArriveAirport->setText(QString("%1").arg(info.arriveAirport));
    QString durationStr = QString::number(info.duration);
    durationStr=durationStr+"min";
    ui->duration->setText(durationStr);

    // 3. 右侧价格和按钮
    ui->labelPrice->setText(QString("¥%1起").arg(info.price));
    /*if (!info.remain.isEmpty()) {
        ui->labelRemain->setText(info.remain);
        ui->labelRemain->setVisible(true);
    }
    */
    // 存储航班号（用于信号传递）
    m_flightNo = info.flightNo;

    m_flightInfo = info;
    updateCabinPrice(0);
}

void FlightItemWidget::updateCabinPrice(int cabinType)
{
    QString priceText;
    QString remainText;

    // 适配规则：0=不限(默认经济舱)，1=经济舱，2=公务舱，3=头等舱
    switch (cabinType) {
    case 0: // 不限 → 显示经济舱（默认）
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("总余票：%1").arg(m_flightInfo.remain); // 可选：显示总余票更贴合“不限”
        // 若想显示经济舱余票，替换为：remainText = QString("余票：%1").arg(m_flightInfo.economyRemain);
        break;
    case 1: // 经济舱
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("余票：%1").arg(m_flightInfo.economyRemain);
        break;
    case 2: // 公务舱
        // 防护：无公务舱时显示“暂未开放”
        if (m_flightInfo.businessPrice <= 0) {
            priceText = "暂未开放";
            remainText = "无票";
        } else {
            priceText = QString("¥%1起").arg(m_flightInfo.businessPrice);
            remainText = QString("余票：%1").arg(m_flightInfo.businessRemain);
        }
        break;
    case 3: // 头等舱
        // 防护：无头等舱时显示“暂未开放”
        if (m_flightInfo.firstPrice <= 0) {
            priceText = "暂未开放";
            remainText = "无票";
        } else {
            priceText = QString("¥%1起").arg(m_flightInfo.firstPrice);
            remainText = QString("余票：%1").arg(m_flightInfo.firstRemain);
        }
        break;
    default: // 兜底 → 经济舱
        priceText = QString("¥%1起").arg(m_flightInfo.economyPrice);
        remainText = QString("总余票：%1").arg(m_flightInfo.remain);
        break;
    }

    // 更新UI
    ui->labelPrice->setText(priceText);
    ui->labelremain->setText(remainText);

    // 优化：余票状态标色
    int remain = 0;
    if (cabinType == 0) remain = m_flightInfo.remain; // 不限→总余票
    else if (cabinType == 1) remain = m_flightInfo.economyRemain;
    else if (cabinType == 2) remain = m_flightInfo.businessRemain;
    else if (cabinType == 3) remain = m_flightInfo.firstRemain;

    if (remain <= 0) {
        ui->labelremain->setStyleSheet("color: #999999;"); // 售罄/无票（灰色）
    } else if (remain <= 5) {
        ui->labelremain->setStyleSheet("color: #ff4444;"); // 余票紧张（红色）
    } else {
        ui->labelremain->setStyleSheet("color: #333333;"); // 余票充足（黑色）
    }
}

void FlightItemWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) { // 仅响应左键

        FlightDetailWidget* detailWidget = new FlightDetailWidget(m_flightInfo, this);
        detailWidget->show(); // 打开详情页（非模态）
    }
    QWidget::mousePressEvent(event); // 保留父类事件处理
}
