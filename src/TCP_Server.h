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
    TCP_Socket sock;

public:
TCP_Server(int port, int queueSize);
~TCP_Server();

int accept();
void close();
};


#endif //CPPSOCKETWRAPPER_TCP_SERVER_H
