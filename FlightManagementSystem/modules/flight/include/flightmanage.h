#ifndef FLIGHTMANAGE_H
#define FLIGHTMANAGE_H

#include "flightinfo.h"

#include <QList>
#include <QDateTime>
#include <QString>

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
