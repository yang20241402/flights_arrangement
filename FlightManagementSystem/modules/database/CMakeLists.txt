qt_add_library(DatabaseModule STATIC
    # ===== cpp =====
    src/databasemanager.cpp

    # ===== header（必须写）=====
    include/databasemanager.h
)

target_include_directories(DatabaseModule PUBLIC include)

target_link_libraries(DatabaseModule
    PUBLIC
        Qt6::Core
        Qt6::Sql
    PRIVATE
        CommonModule
)

set_target_properties(DatabaseModule PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
)


