cmake_minimum_required(VERSION 3.10)
project(Esercitazione2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(es_memoria es2.cpp)
add_executable(es_statistiche algoritmi.cpp)