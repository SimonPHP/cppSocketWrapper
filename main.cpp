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

    TCP_Socket sock("127.0.0.1", 8080); //verbindungsaufbau

    sock.send("Eine Nachricht vom Client"); //client sendet als erstes eine nachricht an den server

    std::string rec = sock.recv(); //der server antwortet dann
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

    TCP_Server server = TCP_Server(8080, 4);
    int sd = server.accept(); //hier wird auf den anderen thread gewaretet.

    TCP_Socket sock = TCP_Socket(sd);

    std::cout << "Client angenommen" << std::endl;
    std::cout << sock.recv() << std::endl;


    sock.send("Nachricht vom server");


    sock.close();
    t1.join(); //wait for thread to exit bevor exit main

    return 0;
}