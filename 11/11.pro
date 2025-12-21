QT       += core gui widgets sql network
TARGET = LoginDemo
TEMPLATE = app


CONFIG += c++17


SOURCES += \
    changeticketwidget.cpp \
    flightitemwidget.cpp \
    flightmanage.cpp \
    form.cpp \
    formpwd.cpp \
    main.cpp \
    mainwindow.cpp \
    widget.cpp \
    ClickableLabel.cpp \
    flightdetailwidget.cpp


HEADERS += \
    changeticketwidget.h \
    flightitemwidget.h \
    flightmanage.h \
    form.h \
    formpwd.h \
    mainwindow.h \
    widget.h \
    ClickableLabel.h \
    flightdetailwidget.h

# UI 文件
FORMS += \
    changeticketwidget.ui \
    flightitemwidget.ui \
    form.ui \
    formpwd.ui \
    mainwindow.ui \
    widget.ui \
    flightdetailwidget.ui


LIBS += -lodbc32

 RESOURCES += new_resources.qrc
