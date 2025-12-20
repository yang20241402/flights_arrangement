#include "flightmanage.h"
#include <algorithm>

FlightManage::FlightManage() {

}

void FlightManage::setFlightList(const QList<FlightInfo>& list) {
    flightList = list; // 把外部传入的航班数据复制到内部
}

QList<FlightInfo> FlightManage::sortFlights(SortType type) {
    QList<FlightInfo> sortedList = flightList;

    std::sort(sortedList.begin(), sortedList.end(),
              [type](const FlightInfo& a, const FlightInfo& b) {
                  switch (type) {
                  case PriceAsc:        // 价格升序
                      return a.price_int < b.price_int;
                  case PriceDesc:       // 价格降序
                      return a.price_int > b.price_int;
                  case DepartTimeAsc:   // 起飞时间升序
                      return a.departTime < b.departTime;
                  case DepartTimeDesc:  // 起飞时间降序
                      return a.departTime > b.departTime;
                  case ArriveTimeAsc:   // 到达时间升序
                      return a.arriveTime < b.arriveTime;
                  case ArriveTimeDesc:  // 到达时间降序
                      return a.arriveTime > b.arriveTime;
                  case DurationAsc:     // 耗时升序
                      return a.duration < b.duration;
                  case DurationDesc:    // 耗时降序
                      return a.duration > b.duration;
                  case OnTimeRateDesc:  // 准点率降序
                      return a.onTimeRate > b.onTimeRate;
                  default:
                      return false;
                  }
              });

    return sortedList;
}
