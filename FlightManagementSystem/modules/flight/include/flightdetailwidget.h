#ifndef FLIGHTDETAILWIDGET_H
#define FLIGHTDETAILWIDGET_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "flightinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FlightDetailWidget;
}
QT_END_NAMESPACE

class FlightDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FlightDetailWidget(const FlightInfo& flightInfo, QWidget *parent = nullptr);
    explicit FlightDetailWidget(const FlightInfo& flightInfo, int userId, QWidget *parent = nullptr);
    explicit FlightDetailWidget(const FlightInfo& flightInfo, int userId, const QDate& selectedDate, QWidget *parent = nullptr);
    ~FlightDetailWidget();

private slots:
    void onReserveClicked();

private:
    Ui::FlightDetailWidget *ui;
    FlightInfo m_flightInfo;
    int m_userId;
    QDate m_selectedDate; // 用户选择的出发日期

    void loadFlightDetail();
    void initStyle();
    void displayFlightInfoData(); // 显示FlightInfo数据的备用方法
    bool createOrder(); // 创建订单
    QString generateOrderId(); // 生成订单号
};

#endif // FLIGHTDETAILWIDGET_H