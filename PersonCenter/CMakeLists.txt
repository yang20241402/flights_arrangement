cmake_minimum_required(VERSION 3.19)
project(PersonCenter LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_library(PassengerLib STATIC
    passengerdialog.h
    passengerdialog.cpp
    passengerdialog.ui
)

target_link_libraries(PassengerLib
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)
set_target_properties(PassengerLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib  # 静态库输出到build/lib
    AUTOUIC ON  # 确保ui文件正常编译
    AUTOMOC ON  # 确保moc编译（Qt信号槽必需）
    AUTORCC ON
)


qt_add_executable(PersonCenter
    WIN32 MACOSX_BUNDLE
    main.cpp
    PersonCenterWindow.cpp
    PersonCenterWindow.h
    PersonCenterWindow.ui
    myorderdialog.h myorderdialog.cpp myorderdialog.ui
    passengerdialog.h passengerdialog.cpp passengerdialog.ui
    pointsdialog.h pointsdialog.cpp pointsdialog.ui
    mymsgdialog.h mymsgdialog.cpp mymsgdialog.ui
    profileeditwidget.h profileeditwidget.cpp profileeditwidget.ui

)

target_link_libraries(PersonCenter
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
        PassengerLib
)

include(GNUInstallDirs)

install(TARGETS PersonCenter
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(TARGETS PassengerLib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # 静态库安装路径
)

qt_generate_deploy_app_script(
    TARGET PersonCenter
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
