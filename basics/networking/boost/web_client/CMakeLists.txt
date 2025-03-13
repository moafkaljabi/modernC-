cmake_minimum_required(VERSION 3.10)

project(WebClient)

set(CMAKE_CXX_STANDARD 11)

# Add your source file
add_executable(web_client web_client.cpp)

# Find and link Boost
find_package(Boost REQUIRED system)
target_link_libraries(web_client Boost::system)

# Link OpenSSL
find_package(OpenSSL REQUIRED)
target_link_libraries(web_client OpenSSL::SSL OpenSSL::Crypto)

# Link pthread
target_link_libraries(web_client pthread)
