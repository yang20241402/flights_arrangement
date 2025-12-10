#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "flightitemwidget.h"
#include "flightmanage.h"
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

private:
    Ui::MainWindow *ui;

    // 模拟从数据库获取去程/返程数据（实际项目中替换为数据库查询）
    QList<FlightInfo> getGoingFlights();
    QList<FlightInfo> getReturnFlights();
    QSqlDatabase db;
    QList<FlightInfo> queryFlights(int flightType);

    QString getDepartCity();

    QString getArriveCity();

    QDate getDepartDate();

    QDate getReturnDate();

    void addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights);

    QList<FlightInfo> allGoingFlights; // 去程航班数据（排序用）
    QList<FlightInfo> allReturnFlights;// 返程航班数据（排序用）
    FlightManage flightManager;
    void refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights);
};

#endif // MAINWINDOW_H
