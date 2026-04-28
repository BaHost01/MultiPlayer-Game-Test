cmake_minimum_required(VERSION 3.22)
project(MyEngine CXX)

set(CMAKE_CXX_STANDARD 20)

# Sources
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(MyEngine ${SOURCES})

# Includes
target_include_directories(MyEngine PRIVATE include)

# libcurl
find_package(CURL REQUIRED)
target_link_libraries(MyEngine PRIVATE CURL::libcurl)

# nlohmann/json (header-only, assuming it's in include/nlohmann/ or just include/)
# If it's header only and in include/nlohmann/json.hpp, it should be fine.

# Android-specific
if(ANDROID)
    add_library(MyEngine SHARED ${SOURCES})
    target_link_libraries(MyEngine PRIVATE log android)
endif()
