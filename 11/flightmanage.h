#ifndef FLIGHTMANAGE_H
#define FLIGHTMANAGE_H

#include "flightitemwidget.h"
#include <QList>
#include <QDateTime>
#include <QString>

enum SortType {
    DurationAsc,
    DurationDesc,
    PriceDesc,
    ArriveTimeAsc,
    ArriveTimeDesc,
    DepartTimeDesc,
    OnTimeRateDesc,
    PriceAsc,
    DepartTimeAsc,
};

class FlightManage
{

private:
    QList<FlightInfo> flightList;
public:
    FlightManage();
    void setFlightList(const QList<FlightInfo>& list);
    QList<FlightInfo> sortFlights(SortType type);
};

#endif // FLIGHTMANAGE_H
