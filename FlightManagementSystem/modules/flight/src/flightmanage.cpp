#include "flightmanage.h"
#include <algorithm>

FlightManage::FlightManage() {

}

void FlightManage::setFlightList(const QList<FlightInfo>& list) {
    flightList = list;
}

QList<FlightInfo> FlightManage::sortFlights(SortType type) {
    QList<FlightInfo> sortedList = flightList;

    std::sort(sortedList.begin(), sortedList.end(),
              [type](const FlightInfo& a, const FlightInfo& b) {
                  switch (type) {
                  case PriceAsc:
                      return a.price_int < b.price_int;
                  case PriceDesc:
                      return a.price_int > b.price_int;
                  case DepartTimeAsc:
                      return a.departTime < b.departTime;
                  case DepartTimeDesc:
                      return a.departTime > b.departTime;
                  case ArriveTimeAsc:
                      return a.arriveTime < b.arriveTime;
                  case ArriveTimeDesc:
                      return a.arriveTime > b.arriveTime;
                  case DurationAsc:
                      return a.duration < b.duration;
                  case DurationDesc:
                      return a.duration > b.duration;
                  case OnTimeRateDesc:
                      return a.onTimeRate > b.onTimeRate;
                  default:
                      return false;
                  }
              });

    return sortedList;
}