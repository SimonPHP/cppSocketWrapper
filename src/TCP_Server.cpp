//
// Created by simon on 28.11.18.
//

#include "TCP_Server.h"
#include "TCP_Socket.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>

TCP_Server::TCP_Server(int port, int queueSize) {
    // create a server-socket

    sock._socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sock._socket == -1)
        throw std::string("cannot open socket ") + strerror(errno);

    // Fehler "cannot bind socket: Address already in use" abfangen
    int i = 1;
    ::setsockopt(sock._socket, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));

    // bind server port
    sock._address.sin_family = AF_INET;
    sock._address.sin_addr.s_addr = INADDR_ANY;
    sock._address.sin_port = ::htons(port);

    int r = ::bind(sock._socket, (struct sockaddr *)&sock._address, sizeof(sock._address));
    if (r == -1)
        throw std::string("cannot bind socket ") + strerror(errno);

    // listen for incoming requests, set size of queue to backlog
    ::listen(sock._socket, queueSize);
    sock._addrlen = sizeof(struct sockaddr_in);
}


TCP_Server::~TCP_Server() {
    ::close(sock._socket);
}

void TCP_Server::close() {
    ::close(sock._socket);
}

int TCP_Server::accept() {
    // waiting for incoming requests
    #ifdef DEBUG
        std::cout << "waiting for incoming requests ..." << std::endl;
    #endif

    int conn = ::accept(sock._socket, (struct sockaddr *)&sock._address, &sock._addrlen);

    if (conn == -1)
        throw std::string("server: ") + strerror(errno);

    #ifdef DEBUG
        std::cout << "got request ---> new socket: " << conn << std::endl;
    #endif

    return conn;
}