//
// Created by simon on 28.11.18.
//

#ifndef CPPSOCKETWRAPPER_TCP_SERVER_H
#define CPPSOCKETWRAPPER_TCP_SERVER_H

#include <string>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>
#include "TCP_Socket.h"

class TCP_Server {
private:
    sockaddr_in _address;
    int _socket;
    socklen_t _addrlen;

public:
    TCP_Server(int port, int queueSize);
    ~TCP_Server();

    TCP_Socket accept();
    void close();
};


#endif //CPPSOCKETWRAPPER_TCP_SERVER_H
