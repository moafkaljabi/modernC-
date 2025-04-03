cmake_minimum_required(VERSION 3.10)
project(eigen-matrix)

set(CMAKE_CXX_STANDARD 23)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(eigen-matrix src/main.cpp src/GenerateData.cpp)
target_link_libraries(eigen-matrix Eigen3::Eigen)
