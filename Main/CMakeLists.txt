cmake_minimum_required(VERSION 3.24)


set(target main)

add_executable(${target}
        src/main.cpp
)

target_include_directories(${target} PUBLIC
        include
)

target_link_libraries(${target} PUBLIC
        app
)