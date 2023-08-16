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
        src/main/Main.cpp
        src/mainWindow/MainWindow.cpp
        src/mainWindow/MainWindow.h
        src/mainWindow/MainWindow.ui
        src/travelAirplane/TravelAirplane.cpp
        src/travelAirplane/TravelAirplane.h)

target_link_libraries(Imitator
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
)
