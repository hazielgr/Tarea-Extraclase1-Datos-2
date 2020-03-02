cmake_minimum_required(VERSION 3.15)
project(Grafo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Grafo grafo/main.cpp grafo/Vertice.cpp grafo/Vertice.h grafo/Arista.cpp grafo/Arista.h grafo/Grafo.cpp grafo/Grafo.h )
add_executable(Server SocketServer/Server.cpp grafo/Vertice.cpp grafo/Vertice.h grafo/Arista.cpp grafo/Arista.h grafo/Grafo.cpp grafo/Grafo.h)
add_executable(Client SocketServer/Client.cpp )
