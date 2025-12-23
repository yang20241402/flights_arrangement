#ifndef CHANGETICKETWIDGET_H
#define CHANGETICKETWIDGET_H

#include <QWidget>
#include <QDate>
#include <QSqlQuery>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include "flightitemwidget.h"
#include "flightmanage.h"
#include "databasemanager.h"

struct FlightInfo;

namespace Ui {
class ChangeTicketWidget;
}

class ChangeTicketWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeTicketWidget(const QString& departCity,
                                const QString& arriveCity,
                                const QString& oldFlightNo,
                                const QDate& oldFlightDate,
                                QWidget *parent = nullptr);
    ~ChangeTicketWidget();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    
signals:
    void changeTicketSuccess(const QString& newFlightNo);
    void changeTicketCanceled();

private slots:
    void on_btnSearch_clicked();
    void on_dateNewFlight_dateChanged(const QDate &date);
    void on_comboBox_3_currentIndexChanged(int index);
    void on_dijia_clicked();
    void on_ontime_clicked();
    void on_depart_clicked();
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::ChangeTicketWidget *ui;

    QString m_departCity;
    QString m_arriveCity;
    QString m_oldFlightNo;
    QDate m_oldFlightDate;
    QDate m_selectedDate; // 用户选择的新航班日期

    QDate getDepartDate();
    QList<FlightInfo> m_newFlights;

    QList<FlightInfo> queryFlights(int flightType, int type);
    void addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights);
    void refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights);
    int getValidPassengerCount();
    QString getAirlineLogo(const QString& airlineName);

    QList<FlightInfo> allGoingFlights;
    FlightManage flightManager;
};

#endif // CHANGETICKETWIDGET_H