cmake_minimum_required(VERSION 3.24)
project(variant12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(variant12 main.cpp mainwindow.cpp mainwindow.h)
target_link_libraries(variant12
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

