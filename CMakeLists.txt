cmake_minimum_required(VERSION 3.15)
project(Grafo)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(Grafo grafo/main.cpp grafo/Vertice.cpp grafo/Vertice.h grafo/Arista.cpp grafo/Arista.h grafo/Grafo.cpp grafo/Grafo.h )
add_executable(Server SocketServer/Server.cpp grafo/Vertice.cpp grafo/Vertice.h grafo/Arista.cpp grafo/Arista.h grafo/Grafo.cpp grafo/Grafo.h)



set(Qt5_DIR "/home/haziel/Qt5.14.1/5.14.1/gcc_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
if(ANDROID)
    add_library(Interfaz SHARED
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
            )
else()
    add_executable(Interfaz
            Interfaz/main.cpp
            Interfaz/mainwindow.cpp
            Interfaz/mainwindow.h
            Interfaz/mainwindow.ui
            SocketServer/Client.cpp
            )
endif()



target_link_libraries(Interfaz Qt5::Core Qt5::Widgets)