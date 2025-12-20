#ifndef FLIGHTITEMWIDGET_H
#define FLIGHTITEMWIDGET_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class FlightItemWidget;
}

struct FlightInfo {
    QString logo;         // Logo资源路径（如":/images/xiamen.png"）
    QString airline;      // 航空公司（如"厦门航空"）
    QString flightNo;     // 航班号（如"MF8340"）
    QString planeType;    // 机型（如"空客321(中)"）
    QString departTime;   // 起飞时间（如"21:10"）
    QString arriveTime;   // 降落时间（如"00:10"）
    bool isNextDay;       // 是否+1天
    QString departAirport;// 起飞机场（如"白云国际机场T2"）
    QString arriveAirport;// 降飞机场（如"大兴国际机场"）
    QString price;        // 价格（如"1122"）
    int remain;       // 剩余票数（如"剩3张"，空则隐藏）
    bool hasTag;          // 是否显示小标签（如准点率图标）
    int duration;
    int onTimeRate;
    int price_int;
    int economyPrice;    // 经济舱价格
    int economyRemain;   // 经济舱余票
    int businessPrice;   // 公务舱价格
    int businessRemain;  // 公务舱余票
    int firstPrice;      // 头等舱价格
    int firstRemain;
};

class FlightItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlightItemWidget(QWidget *parent = nullptr);
    ~FlightItemWidget();

    void setFlightInfo(const FlightInfo& info);
    void updateCabinPrice(int cabinType);

signals:
    void clicked(const FlightInfo& info);


protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::FlightItemWidget *ui;
    QString m_flightNo;
    FlightInfo m_flightInfo;
};

#endif // FLIGHTITEMWIDGET_H
