QT       += core gui widgets sql network
TARGET = LoginDemo
TEMPLATE = app

# 支持 C++17（根据你的 Qt 版本调整，若不支持则改为 C++11）
CONFIG += c++17

# 源文件（确保无重复、无拼写错误）
SOURCES += \
    flightitemwidget.cpp \
    flightmanage.cpp \
    form.cpp \
    formpwd.cpp \
    main.cpp \
    mainwindow.cpp \
    widget.cpp \
    ClickableLabel.cpp

# 头文件（确保无重复、无拼写错误）
HEADERS += \
    flightitemwidget.h \
    flightmanage.h \
    form.h \
    formpwd.h \
    mainwindow.h \
    widget.h \
    ClickableLabel.h

# UI 文件
FORMS += \
    flightitemwidget.ui \
    form.ui \
    formpwd.ui \
    mainwindow.ui \
    widget.ui

# ODBC 链接库（你的原有配置）
LIBS += -lodbc32

# 资源文件（用不到就注释）
 RESOURCES += new_resources.qrc
