# modules/flight/CMakeLists.txt
qt_add_library(FlightModule STATIC
    # Source files
    src/flightmanager.cpp
    src/flightitemwidget.cpp
    src/flightdetailwidget.cpp
    src/flightmanage.cpp
    src/changeticketwidget.cpp

    # Header files
    include/flightmanager.h
    include/flightitemwidget.h
    include/flightdetailwidget.h
    include/flightmanage.h
    include/changeticketwidget.h

    # UI files
    ui/flightitemwidget.ui
    ui/flightdetailwidget.ui
    ui/changeticketwidget.ui
)

# 头文件目录
target_include_directories(FlightModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 链接依赖库
target_link_libraries(FlightModule
    PUBLIC Qt6::Core Qt6::Widgets
    PRIVATE CommonModule DatabaseModule
)

# Qt 自动处理属性
set_target_properties(FlightModule PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)


