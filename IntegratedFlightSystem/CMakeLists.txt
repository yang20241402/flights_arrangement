cmake_minimum_required(VERSION 3.19)
project(IntegratedFlightSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt6或Qt5
find_package(Qt6 COMPONENTS Core Widgets Sql Network QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Core Widgets Sql Network)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置UI文件搜索路径
set(CMAKE_AUTOUIC_SEARCH_PATHS 
    ${CMAKE_CURRENT_SOURCE_DIR}/login
    ${CMAKE_CURRENT_SOURCE_DIR}/flight
    ${CMAKE_CURRENT_SOURCE_DIR}/person
)

# 源文件
set(PROJECT_SOURCES
    main.cpp
    # 数据库管理模块
    database/databasemanager.cpp
    database/databasemanager.h
    # 登录模块
    login/widget.cpp
    login/widget.h
    login/widget.ui
    login/mainwindow.cpp
    login/mainwindow.h
    login/mainwindow.ui
    login/form.cpp
    login/form.h
    login/form.ui
    login/formpwd.cpp
    login/formpwd.h
    login/formpwd.ui
    login/ClickableLabel.cpp
    login/ClickableLabel.h
    # 航班查询模块
    flight/flightquerywidget.cpp
    flight/flightquerywidget.h
    flight/flightquerywidget.ui
    flight/flightdetailwidget.cpp
    flight/flightdetailwidget.h
    flight/flightdetailwidget.ui
    # 个人中心模块
    person/personcenterwindow.cpp
    person/personcenterwindow.h
    person/personcenterwindow.ui
    person/myorderdialog.cpp
    person/myorderdialog.h
    person/myorderdialog.ui
    person/passengerdialog.cpp
    person/passengerdialog.h
    person/passengerdialog.ui
    person/pointsdialog.cpp
    person/pointsdialog.h
    person/pointsdialog.ui
    # 资源文件
    resources/resources.qrc
)

# 创建可执行文件
if(Qt6_FOUND)
    qt_add_executable(IntegratedFlightSystem
        WIN32 MACOSX_BUNDLE
        ${PROJECT_SOURCES}
    )
    target_link_libraries(IntegratedFlightSystem PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
        Qt::Network
    )
else()
    add_executable(IntegratedFlightSystem
        WIN32
        ${PROJECT_SOURCES}
    )
    target_link_libraries(IntegratedFlightSystem PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
    )
endif()

# Windows平台添加ODBC库
if(WIN32)
    target_link_libraries(IntegratedFlightSystem PRIVATE odbc32)
endif()

# 包含目录
target_include_directories(IntegratedFlightSystem PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/database
    ${CMAKE_CURRENT_SOURCE_DIR}/login
    ${CMAKE_CURRENT_SOURCE_DIR}/flight
    ${CMAKE_CURRENT_SOURCE_DIR}/person
)

# 安装配置
include(GNUInstallDirs)
install(TARGETS IntegratedFlightSystem
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Qt部署脚本
if(Qt6_FOUND)
    qt_generate_deploy_app_script(
        TARGET IntegratedFlightSystem
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
    )
    install(SCRIPT ${deploy_script})
endif()
