//
// Created by Dmitrii on 01.09.2024.
//
#include <HelloHttpServer.h>
#include <format>
#include <utility>

void HelloHttpServer::startWorkLoop() {

    server_.listen(host_, port_);

    server_.is_running();
    server_.is_valid();
}

HelloHttpServer::HelloHttpServer(std::string host, int port)
    : host_(std::move(host)), port_(port) {

    server_.Get("/hello", [=, this](const httplib::Request &, httplib::Response &res) {
        res.set_content(
                std::format("Hello World, number of requests:{}", numOfRequests_++),
                "text/plain");
    });

}

void HelloHttpServer::stopWorkLoop() {

    server_.stop();

}

bool HelloHttpServer::isStarted() {
    return server_.is_running();
}

