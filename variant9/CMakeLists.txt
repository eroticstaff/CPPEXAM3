cmake_minimum_required(VERSION 3.24)
project(variant9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(variant9 main.cpp mainwindow.cpp mainwindow.h facultymodel.cpp facultymodel.h)
target_link_libraries(variant9
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

