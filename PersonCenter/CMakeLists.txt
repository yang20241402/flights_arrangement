cmake_minimum_required(VERSION 3.19)
project(PersonCenter LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

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
)

include(GNUInstallDirs)

install(TARGETS PersonCenter
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PersonCenter
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
