cmake_minimum_required(VERSION 3.19)
project(FlightManagementSystem VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql Network)

# Qt标准项目设置
qt_standard_project_setup()

# 全局Qt属性设置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加模块子目录（按依赖顺序）
add_subdirectory(modules/common)
add_subdirectory(modules/database)
add_subdirectory(modules/authentication)
add_subdirectory(modules/flight)
add_subdirectory(modules/user)

# 添加资源文件
qt_add_resources(RESOURCES new_resources.qrc)

# 添加主应用程序
add_subdirectory(src)

