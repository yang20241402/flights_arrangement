#ifndef FLIGHTITEMWIDGET_H
#define FLIGHTITEMWIDGET_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class FlightItemWidget;
}

struct FlightInfo {
    QString logo;
    QString airline;
    QString flightNo;
    QString planeType;
    QString departTime;
    QString arriveTime;
    bool isNextDay;
    QString departAirport;
    QString arriveAirport;
    QString price;
    int remain;
    int duration;
    int onTimeRate;
    int price_int;
    int economyPrice;
    int economyRemain;
    int businessPrice;
    int businessRemain;
    int firstPrice;
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
