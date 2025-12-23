qt_add_library(CommonModule STATIC
    # ===== cpp =====
    src/constants.cpp
    src/clickablelabel.cpp
    src/flightinfo.cpp
    src/utils.cpp

    # ===== header（必须写）=====
    include/constants.h
    include/clickablelabel.h
    include/flightinfo.h
    include/utils.h
)

target_include_directories(CommonModule PUBLIC include)

target_link_libraries(CommonModule
    PUBLIC
        Qt6::Core
        Qt6::Widgets
)

set_target_properties(CommonModule PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
)
