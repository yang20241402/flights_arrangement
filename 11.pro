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
    ClickableLabel.cpp \
    flightdetailwidget.cpp

# 头文件（确保无重复、无拼写错误）
HEADERS += \
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
    flightitemwidget.ui \
    form.ui \
    formpwd.ui \
    mainwindow.ui \
    widget.ui \
    flightdetailwidget.ui

# ODBC 链接库（你的原有配置）
LIBS += -lodbc32

# 资源文件（用不到就注释）
 RESOURCES += new_resources.qrc

# ========== 新增：PassengerLib静态库依赖配置（适配Linux/Mac的libPassengerLib.a） ==========
# 1. 指定PassengerLib头文件路径（需手动创建include/PassengerLib目录存放passengerdialog.h）
INCLUDEPATH += $$PWD/include

# 2. 指定PassengerLib静态库存放路径（需手动创建lib目录，放入libPassengerLib.a）
LIBS += -L$$PWD/lib

# 3. 链接静态库（区分Windows和Linux/Mac，重点优化Linux/Mac适配）
win32 {
    # Windows系统（若后续不用Windows，可注释此段）
    LIBS += -lPassengerLib
} else:unix {
    # Linux/Mac系统：两种链接方式二选一（推荐方式2，更稳妥）
    # 方式1：通过-l指定库名（自动匹配lib前缀和.a后缀，需确保库名正确）
    #LIBS += -lPassengerLib
    # 方式2：直接指定静态库绝对路径（避免路径识别问题，优先推荐）
    LIBS += $$PWD/lib/libPassengerLib.a
}
