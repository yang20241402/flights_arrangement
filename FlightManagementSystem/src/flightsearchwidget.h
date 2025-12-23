#ifndef FLIGHTSEARCHWIDGET_H
#define FLIGHTSEARCHWIDGET_H

#include <QWidget>
#include "flightitemwidget.h"
#include "flightmanage.h"
#include "flightdetailwidget.h"
#include "databasemanager.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDate>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QCompleter>
#include <QStringListModel>

// 前置声明
class PersonCenterWindow;
class MyOrderDialog;

namespace Ui {
class FlightSearchWidget;
}

class FlightSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlightSearchWidget(QWidget *parent = nullptr);
    ~FlightSearchWidget();
    
    // 用户ID管理
    void setUserId(int userId);
    int getUserId() const;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    int getValidPassengerCount();
    void updateCachedPassengerCount();
    bool eventFilterForCityInput(QObject *watched, QEvent *event);

private slots:
    void updateTabWidget2PageCount(bool hasReturnFlight);
    void on_calendarWidget_clicked(const QDate &date);
    void on_calendarWidget_2_clicked(const QDate &date);
    void on_btnSearch_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_comboBox_3_currentIndexChanged(int index);
    void on_dijia_clicked();
    void on_ontime_clicked();
    void on_depart_clicked();
    void on_comboBox_4_currentIndexChanged(int index);
    void on_dijia_2_clicked();
    void on_ontime_2_clicked();
    void on_depart_2_clicked();
    void on_radioOneWay_clicked();
    void on_radioRoundTrip_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_btnSearch_2_clicked();
    void on_calendarWidget_3_clicked(const QDate &date);
    void on_radioButton_5_toggled(bool checked);
    void on_pushButton_3_clicked();
    void on_label_5_clicked();  // 个人中心点击
    void on_label_3_clicked();  // 我的订单点击

private:
    Ui::FlightSearchWidget *ui;
    int m_currentUserId;  // 当前登录用户ID

    QList<FlightInfo> getGoingFlights();
    QList<FlightInfo> getReturnFlights();
    QList<FlightInfo> queryFlights(int flightType, int type);
    
    // 城市选择相关
    QStringList loadCitiesFromDatabase();
    void setupCityCompleters();
    QCompleter* createCityCompleter(const QStringList& cities);
    QStringList m_cities;
    
    // 航空公司 logo 映射
    QString getAirlineLogo(const QString& airlineName);

    int m_cachedValidPassengerCount = 1;

    QString getDepartCity();
    QString getArriveCity();
    QString getDepartCity_2();
    QString getArriveCity_2();
    QString getflightNo();
    QDate getDepartDate();
    QDate getReturnDate();
    QDate getOtherDate();

    void addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights);

    QList<FlightInfo> allGoingFlights;
    QList<FlightInfo> allReturnFlights;
    FlightManage flightManager;
    void refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights);
    void showInitialMessage();
};

#endif // FLIGHTSEARCHWIDGET_H