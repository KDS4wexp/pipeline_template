cmake_minimum_required(VERSION 3.27)


set(target app)

add_library(${target} STATIC
        src/HelloHttpServer.cpp
)

target_include_directories(${target} PUBLIC
        include
)

find_package(spdlog 1.14.0 REQUIRED)
find_package(httplib 0.16.3 REQUIRED)

target_link_libraries(${target} PUBLIC
        spdlog::spdlog

        httplib::httplib
)