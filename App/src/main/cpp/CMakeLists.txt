cmake_minimum_required(VERSION 3.22)
project(MyEngine)

# Core sources
set(CORE_DIR "../../../../Core")
file(GLOB_RECURSE CORE_SOURCES "${CORE_DIR}/src/*.cpp")

# Filter out main.cpp from CORE_SOURCES if it exists, as JNI is our entry
list(FILTER CORE_SOURCES EXCLUDE REGEX "main\\.cpp$")

add_library(MyEngine SHARED
            native-lib.cpp
            ${CORE_SOURCES})

target_include_directories(MyEngine PRIVATE
                           ${CORE_DIR}/include)

# Link libraries
find_library(log-lib log)
find_library(android-lib android)

# Note: libcurl needs to be provided for Android. 
# Usually you'd use a prebuilt or a port. 
# For now, we assume it's available or handled by the system/build environment.
# find_package(CURL REQUIRED)

target_link_libraries(MyEngine
                      ${log-lib}
                      ${android-lib}
                      # CURL::libcurl
                      )
