//
// Created by Dmitrii on 01.09.2024.
//

#pragma once

//#define CPPHTTPLIB_OPENSSL_SUPPORT

//#include <httplib.h>
#include <httplib/httplib.h>

class HelloHttpServer {
private:
    httplib::Server server_;

    std::string host_;
    int port_;

    long numOfRequests_{};

public:
    HelloHttpServer(std::string host, int port);

    HelloHttpServer(const HelloHttpServer &) = delete;
    HelloHttpServer &operator=(const HelloHttpServer &) = delete;

    bool isStarted();

    void startWorkLoop();
    void stopWorkLoop();

    virtual ~HelloHttpServer() = default;
};