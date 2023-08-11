cmake_minimum_required(VERSION 3.26)
project(Imitator)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_AUTOMATIC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(.)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_executable(Imitator
        src/main/main.cpp
        src/mainWindow/mainwindow.cpp
        src/mainWindow/mainwindow.h
        src/mainWindow/mainwindow.ui)

target_link_libraries(Imitator
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
)
