#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "flightitemwidget.h"
#include "flightmanage.h"
#include "FlightDetailWidget.h"
#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QDate>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

    int getValidPassengerCount();

    void updateCachedPassengerCount();

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

private:
    Ui::MainWindow *ui;

    QList<FlightInfo> getGoingFlights();
    QList<FlightInfo> getReturnFlights();
    QSqlDatabase db;
    QList<FlightInfo> queryFlights(int flightType,int type);

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
};

#endif // MAINWINDOW_H
