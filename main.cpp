#include <iostream>

#include "src/TCP_Socket.h"
#include "src/TCP_Server.h"

#include <thread>


void client()
{
    std::cout << "Client Thread Started" << std::endl;

    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 500000;

    clock_nanosleep(CLOCK_MONOTONIC, NULL, &sleepTime, NULL);

    TCP_Socket sock("127.0.0.1", 8080);
}

int main() {
    std::cout << "Socket Wrapper Test" << std::endl;

    #ifdef DEBUG
        std::cout << "DEBUG MODE" << std::endl;
    #endif

    std::cout << "Init Client Thread" << std::endl;

    std::thread t1(client);

    std::cout << "Init Server" << std::endl;

    TCP_Server server = TCP_Server(8080, 10);

    if(server.accept()) {
        std::cout << "heeyy" << std::endl;
    }

    return 0;
}