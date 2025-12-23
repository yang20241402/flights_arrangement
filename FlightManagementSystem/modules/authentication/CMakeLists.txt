qt_add_library(AuthenticationModule STATIC
    src/authmanager.cpp
    src/loginwidget.cpp
    src/registerwidget.cpp
    src/passwordresetwidget.cpp

    include/authmanager.h
    include/loginwidget.h
    include/registerwidget.h
    include/passwordresetwidget.h

    ui/loginwidget.ui
    ui/registerwidget.ui
    ui/passwordresetwidget.ui
)

target_include_directories(AuthenticationModule PUBLIC include)

target_link_libraries(AuthenticationModule
    PUBLIC Qt6::Core Qt6::Widgets
    PRIVATE CommonModule DatabaseModule
)

set_target_properties(AuthenticationModule PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)
