qt_add_executable(FlightManagementSystem
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    viewmanager.cpp
    viewmanager.h
    flightsearchwidget.cpp
    flightsearchwidget.h
    flightsearchwidget.ui
    adminpanel.cpp
    adminpanel.h
    flightadminpanel.cpp
    flightadminpanel.h
)

# 添加 include 路径
target_include_directories(FlightManagementSystem
    PRIVATE
        ${CMAKE_SOURCE_DIR}/modules/flight/include
        ${CMAKE_SOURCE_DIR}/modules/user/include
        ${CMAKE_SOURCE_DIR}/modules/common/include
        ${CMAKE_SOURCE_DIR}/modules/authentication/include
        ${CMAKE_SOURCE_DIR}/modules/database/include
)

# Add resources
target_sources(FlightManagementSystem PRIVATE
    ${CMAKE_SOURCE_DIR}/resources/resources.qrc
    ${CMAKE_SOURCE_DIR}/new_resources.qrc
)

target_link_libraries(FlightManagementSystem
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
        Qt6::Network
        DatabaseModule
        CommonModule
        AuthenticationModule
        FlightModule
        UserModule
)

set_target_properties(FlightManagementSystem PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
