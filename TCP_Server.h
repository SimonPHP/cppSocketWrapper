//
// Created by simon on 28.11.18.
//

#ifndef CPPSOCKETWRAPPER_TCP_SERVER_H
#define CPPSOCKETWRAPPER_TCP_SERVER_H

#include <string>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>

class TCP_Server {
private:
    sockaddr_in _address;
    int _socket;
    socklen_t _addrlen;

public:
    TCP_Server(int port, int queueSize);
    ~TCP_Server(void);

    int accept(void);
    void send(std::string msg);
    std::string recv(void);
};


#endif //CPPSOCKETWRAPPER_TCP_SERVER_H
