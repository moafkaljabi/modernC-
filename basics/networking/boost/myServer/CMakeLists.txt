cmake_minimum_required(VERSION 3.10)

project(MyServer)

set (CMAKE_CXX_STANDARD 11)

# Add your source file
add_executable(myServer myServer.cpp)

# Find and link Boost
find_package(Boost REQUIRED system)
target_link_libraries(myServer Boost::system)

# Link OpenSSL 
find_package(OpenSSL REQUIRED)
target_link_libraries(myServer OpenSSL::SSL OpenSSL::Crypto)

# Link pthread
target_link_libraries(myServer pthread)