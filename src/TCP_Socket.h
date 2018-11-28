//
// Created by simon on 27.11.18.
//

#ifndef CPPSOCKETWRAPPER_TCP_SOCKET_H
#define CPPSOCKETWRAPPER_TCP_SOCKET_H

#include <string>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>

class TCP_Socket {
public:
    int _socket;
    sockaddr_in _address;
    socklen_t _addrlen;

public:
    TCP_Socket();
    TCP_Socket(int fd);
    TCP_Socket(std::string ip, int port);
    ~TCP_Socket();

    void send(std::string msg);
    std::string recv();
    void close();
};


#endif //CPPSOCKETWRAPPER_TCP_SOCKET_H
