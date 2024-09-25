//
// Created by Dmitrii on 01.09.2024.
//

#pragma once

#include <format>
#include "HelloHttpServer.h"

TEST(SIMPLE_TEST, TEST_SUCCESS_REQUEST) {

    auto host = "127.0.0.1";
    auto port = 8081;

    HelloHttpServer server(host, port);

    auto task = std::jthread([&](){
        server.startWorkLoop();
    });

    while(not server.isStarted());

    httplib::Client cli(
            std::format("http://{}:{}", host, port)
            );

    auto res = cli.Get("/hello");

    server.stopWorkLoop();
    task.join();

    EXPECT_TRUE(res->status == 200);

}

TEST(SIMPLE_TEST, TEST_UNSUCCESS_REQUEST) {

    auto host = "127.0.0.1";
    auto port = 8081;

    HelloHttpServer server(host, port);

    auto task = std::jthread([&](){
        server.startWorkLoop();
    });

    while(not server.isStarted());

    httplib::Client cli(
            std::format("http://{}:{}", host, port)
    );

    auto res = cli.Get("/hello1");

    server.stopWorkLoop();
    task.join();

    EXPECT_TRUE(res->status != 200);

}