#include "flightmanager.h"

FlightManager::FlightManager(QObject *parent)
    : QObject(parent)
{
}

void FlightManager::searchFlights(const QString &departure, const QString &arrival)
{
    Q_UNUSED(departure)
    Q_UNUSED(arrival)
    
    // TODO: 实现航班搜索逻辑
    QList<int> mockFlights = {1, 2, 3};
    emit flightsFound(mockFlights);
}

bool FlightManager::bookFlight(int flightId)
{
    Q_UNUSED(flightId)
    
    // TODO: 实现航班预订逻辑
    emit bookingSuccessful();
    return true;
}