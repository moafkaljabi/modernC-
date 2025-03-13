cmake_minimum_required(VERSION 3.16)

project(MySQLProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the location of the source files
set(SOURCES
    src/main.cpp
)

# Add the executable target
add_executable(myProject ${SOURCES})

# Set the path to MySQL Connector/C++ libraries
link_directories(/usr/lib/x86_64-linux-gnu)

# Include directories if needed
include_directories(/usr/include)

# Link the MySQL Connector/C++ library
target_link_libraries(myProject
    PRIVATE mysqlcppconn
)
