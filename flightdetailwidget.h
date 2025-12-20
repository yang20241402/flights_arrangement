#ifndef FLIGHTDETAILWIDGET_H
#define FLIGHTDETAILWIDGET_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "flightitemwidget.h"
#include "PassengerLib/passengerdialog.h"

namespace Ui {
class FlightDetailWidget;
}

class FlightDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FlightDetailWidget(const FlightInfo& flightInfo, QWidget *parent = nullptr);
    ~FlightDetailWidget();

private:
    Ui::FlightDetailWidget *ui;
    FlightInfo m_flightInfo;
    QSqlDatabase m_db;

    void initDB();
    void loadFlightDetail();
    void initStyle();
private slots:
    void on_reserveBtn_clicked();
};

#endif // FLIGHTDETAILWIDGET_H
