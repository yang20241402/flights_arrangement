#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <QString>

struct FlightInfo {
    QString logo;
    QString airline;
    QString flightNo;
    QString planeType;
    QString departTime;
    QString arriveTime;
    bool isNextDay;
    QString departAirport;
    QString arriveAirport;
    QString price;
    int remain;
    int duration;
    int onTimeRate;
    int price_int;
    int economyPrice;
    int economyRemain;
    int businessPrice;
    int businessRemain;
    int firstPrice;
    int firstRemain;
};

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

#endif // FLIGHTINFO_H