cmake_minimum_required(VERSION 3.26)
project(Indicator)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_AUTOMATIC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(.)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_executable(Indicator
        main/Main.cpp
        mainWindow/MainWindow.cpp
        mainWindow/MainWindow.h
        mainWindow/MainWindow.ui
        scene/MyScene.cpp
        scene/MyScene.h
        view/MyView.cpp
        view/MyView.h
        View.cpp
        View.h
        itemEllipse/ItemEllipse.cpp
        itemEllipse/ItemEllipse.h)

target_link_libraries(Indicator
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
)
