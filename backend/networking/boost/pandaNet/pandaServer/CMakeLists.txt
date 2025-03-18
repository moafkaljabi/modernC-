cmake_minimum_required(VERSION 3.15)

project(pandaServer)

set(CMAKE_CXX_STANDARD 11)

# Add your source file
add_executable(pandaServer main.cpp)

# Find and link Boost
find_package(Boost REQUIRED system)
target_link_libraries(pandaServer Boost::system)

# Link OpenSSL
find_package(OpenSSL REQUIRED)
target_link_libraries(pandaServer OpenSSL::SSL OpenSSL::Crypto)

# Link pthread
target_link_libraries(pandaServer pthread)
