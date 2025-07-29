cmake_minimum_required(VERSION 3.15)
project(openWindow)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(openWindow
        main.cpp
        ./src/ui/img.cpp
        ./src/ui/label.cpp
       ./src/ui/UIElement.cpp
        ./external/aLogger/src/aLogger.cpp
)

target_include_directories(openWindow PRIVATE
        external/aLogger/include
        include
)

target_link_libraries(openWindow PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)
