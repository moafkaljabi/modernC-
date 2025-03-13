cmake_minimum_required(VERSION 3.16)

# Project name and version
project(MySQL_DB VERSION 0.1 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MySQL Connector/C++ library
find_package(MySQLConnectorCpp REQUIRED)

# Specify the location of the source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    MySQLHandler/*.cpp
    MySQLHandler/connectToDatabase/*.cpp
    addRecord/*.cpp
    deleteRecord/*.cpp
    updateRecord/*.cpp
    readRecords/*.cpp
)

# Add the executable target
add_executable(appMySQL_DB ${SOURCES})

# Include directories for the MySQL Connector/C++
target_include_directories(appMySQL_DB PRIVATE ${MYSQLCPPCONN_INCLUDE_DIRS})

# Link the MySQL Connector/C++ library
target_link_libraries(appMySQL_DB
    PRIVATE ${MYSQLCPPCONN_LIBRARIES}
)

# Install rules (optional)
include(GNUInstallDirs)
install(TARGETS appMySQL_DB
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
