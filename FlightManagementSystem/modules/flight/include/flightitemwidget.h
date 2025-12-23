#ifndef FLIGHTITEMWIDGET_H
#define FLIGHTITEMWIDGET_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "flightinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FlightItemWidget;
}
QT_END_NAMESPACE

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

private slots:
    void showFlightDetail();

private:
    Ui::FlightItemWidget *ui;
    QString m_flightNo;
    FlightInfo m_flightInfo;
};

#endif // FLIGHTITEMWIDGET_H