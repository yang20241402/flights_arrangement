#ifndef FLIGHTQUERYWIDGET_H
#define FLIGHTQUERYWIDGET_H

#include <QDialog>
#include <QSqlDatabase>
#include "FlightDetailWidget.h"  // 引入详情窗口头文件

QT_BEGIN_NAMESPACE
namespace Ui { class FlightQueryWidget; }
QT_END_NAMESPACE

class FlightQueryWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FlightQueryWidget(int userId, QWidget *parent = nullptr);
    ~FlightQueryWidget() override;

private slots:
    void on_btn_queryFlight_clicked();
    void on_btn_showAllFlights_clicked();

private:
    Ui::FlightQueryWidget *ui;
    int m_userId;

    void initDB();
    void loadFlightData(const QString &depart, const QString &dest, const QDate &date);
    void loadAllFlights();
    void on_flightTable_cellDoubleClicked(int row, int column);

};

#endif // FLIGHTQUERYWIDGET_H
