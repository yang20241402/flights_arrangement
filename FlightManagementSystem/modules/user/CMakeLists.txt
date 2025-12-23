# modules/user/CMakeLists.txt
qt_add_library(UserModule STATIC
    # Source files
    src/usermanager.cpp
    src/personcenterwindow.cpp
    src/profileeditwidget.cpp
    src/myorderdialog.cpp
    src/passengerdialog.cpp
    src/pointsdialog.cpp
    src/mymsgdialog.cpp

    # Header files
    include/usermanager.h
    include/personcenterwindow.h
    include/profileeditwidget.h
    include/myorderdialog.h
    include/passengerdialog.h
    include/pointsdialog.h
    include/mymsgdialog.h

    # UI files
    ui/personcenterwindow.ui
    ui/profileeditwidget.ui
    ui/myorderdialog.ui
    ui/passengerdialog.ui
    ui/pointsdialog.ui
    ui/mymsgdialog.ui
)

# 头文件目录
target_include_directories(UserModule PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/modules/flight/include
)

# 链接依赖库
target_link_libraries(UserModule
    PUBLIC Qt6::Core Qt6::Widgets Qt6::Sql
    PRIVATE CommonModule DatabaseModule FlightModule
)

# Qt 自动处理属性
set_target_properties(UserModule PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)
