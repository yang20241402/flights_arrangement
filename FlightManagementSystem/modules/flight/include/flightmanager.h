#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <QObject>
#include <QList>

class FlightManager : public QObject
{
    Q_OBJECT

public:
    explicit FlightManager(QObject *parent = nullptr);
    
    // 搜索航班
    void searchFlights(const QString &departure, const QString &arrival);
    
    // 预订航班
    bool bookFlight(int flightId);

signals:
    void flightsFound(const QList<int> &flightIds);
    void bookingSuccessful();
    void bookingFailed();

private:
    // TODO: 添加私有成员变量
};

#endif // FLIGHTMANAGER_H