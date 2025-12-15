#ifndef FLIGHTDETAILWIDGET_H
#define FLIGHTDETAILWIDGET_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class FlightDetailWidget;
}

class FlightDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FlightDetailWidget(int flightId, QWidget *parent = nullptr);
    ~FlightDetailWidget();

private:
    Ui::FlightDetailWidget *ui;
    int m_flightId;

    void loadFlightDetail();
    void initStyle();
};

#endif // FLIGHTDETAILWIDGET_H
