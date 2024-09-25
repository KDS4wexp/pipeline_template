//
// Created by Dmitrii on 01.09.2024.
//

#include <spdlog/spdlog.h>
#include "HelloHttpServer.h"

int main(){

    spdlog::info("get env variables");

    spdlog::debug("get env \"SERVER_HOST\"");
    auto host = std::getenv("SERVER_HOST");

    spdlog::debug("get env \"SERVER_PORT\"");
    auto port = std::stoi(std::getenv("SERVER_PORT"));

    spdlog::debug("initialize application");
    HelloHttpServer server(host, port);

    spdlog::info("start application");
    server.startWorkLoop();

    return 0;
}