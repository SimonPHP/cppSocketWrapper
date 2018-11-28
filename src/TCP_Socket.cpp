//
// Created by simon on 27.11.18.
//

#include "TCP_Socket.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <string>
#include <iostream>

TCP_Socket::TCP_Socket(){}

TCP_Socket::TCP_Socket(std::string ip, int port) {
    _socket = ::socket(PF_INET, SOCK_STREAM, 0);
    if (_socket == -1)
        // throw SocketException(string("socket(): ") + strerror(errno));
        throw std::string(strerror(errno));

    _address.sin_family = PF_INET;
    _address.sin_addr.s_addr = ::inet_addr(ip.c_str());
    _address.sin_port = ::htons(port);
    int len = sizeof(_address);

    int flag = ::connect(_socket, (struct sockaddr *)&_address, len);
    if (flag == -1)
        throw std::string ("server " + ip + ": " + strerror(errno));
}

void TCP_Socket::send(std::string msg) {  //ToDo remove the ']]]' end Tag
    msg += "]]]";
    ::write(_socket, msg.c_str(), msg.length());
    #ifdef DEBUG
        std::cout << "sent: " << msg << std::endl;
    #endif
}

std::string TCP_Socket::recv() { //ToDo remove the ']]]' end Tag
    char block[256];
    std::string res;
    int len;

    do {
        block[0] = '\0';
        len = ::read(_socket, block, 256);
        if (len != 0)
            res += block;
    } while (res.find("]]]") == std::string::npos);

    std::string::size_type pos = res.find("]]]");
    res = res.substr(0, pos);

    return res;
}

void TCP_Socket::close() {
    ::close(_socket);
}

TCP_Socket::~TCP_Socket() {
    ::close(_socket);
}
