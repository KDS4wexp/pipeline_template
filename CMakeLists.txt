cmake_minimum_required(VERSION 3.27)
project(App)

set(CMAKE_CXX_STANDARD 23)

#set(conan "/usr/local/bin/conan") # set conan path
#set(conan_profile "default") # set host conan profile
#set(conan_testing OFF) # set host conan profile
#include(ConanExecPreset.cmake)

add_subdirectory(App)

add_subdirectory(Main)

set(BUILD_TESTING)
message(WARNING "BUILD_TESTING is ${BUILD_TESTING}")

if(NOT BUILD_TESTING STREQUAL OFF)
    add_subdirectory(Test)
endif ()