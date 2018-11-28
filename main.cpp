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
    sock.send("Eine Nachricht vom Client");

    std::string rec = sock.recv();

    std::cout << rec << std::endl;

    sock.close();
    exit(1);
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

    TCP_Socket s = server.accept();

    std::cout << "Client angenommen" << std::endl;

    std::cout << s.recv() << std::endl;

    s.send("Nachricht vom server");

    s.close();

    t1.join(); //wait for thread to exit bevor exit main

    return 0;
}