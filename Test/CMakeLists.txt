cmake_minimum_required(VERSION 3.27)


set(target test)

add_executable(${target}
        src/tests.cpp
)

target_include_directories(${target} PUBLIC
        include
)

find_package(GTest 1.15.0 REQUIRED)

target_link_libraries(${target} PUBLIC
        app

        gtest::gtest
)