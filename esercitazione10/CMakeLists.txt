cmake_minimum_required(VERSION 3.20)
project(Esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror=vla")

# Trova la libreria Eigen3
find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(Esercitazione10 main.cpp)

# Collega Eigen3 all'eseguibile
target_link_libraries(Esercitazione10 Eigen3::Eigen)