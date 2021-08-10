#include "unp.h"
#include <iostream>

class Socket_server
{
public:
    int Socket(int domain,int types,int protocol);
    void Bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
    void Listen(int sockfd,int logback);
    int Accept(int sockfd,struct sockaddr *addr, socklen_t *addrlen);
};

class Socket_client
{
public:
    int Socket(int domain,int types,int protocol);
    void Connect(int sockfd,struct sockaddr *addr,socklen_t addrlen);
};

class Socket_interactive
{
public:
    void Read(int fd,void *buf, size_t count);

};