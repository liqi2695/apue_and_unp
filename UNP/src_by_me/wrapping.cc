#include "wrapping.h"
#include "error.h"
int Socket_server::Socket(int domain,int types,int protocol)
{
    int n;
    if((n = socket(domain,types,protocol)) < 0){
        error_puts("create socket error");
    }
    
    return n;
}

void Socket_server::Bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    if(bind(sockfd,addr,addrlen) < 0){
        error_puts("bind error");
    }
}

void Socket_server::Listen(int sockfd,int logback){
    if(listen(sockfd,logback) < 0){
        error_puts("listen errror");
    }
}

int Socket_server::Accept(int sockfd,struct sockaddr *addr, socklen_t *addrlen){
    int n;
    if((n = accept(sockfd,addr,addrlen)) < 0){
        error_puts("accept error");
    }
    return n;

}

int Socket_client::Socket(int domain,int types,int protocol){
    int n;
    if( (n = socket(domain,types,protocol)) < 0 ){
        error_puts("create socket error");
    }
    return n;
}

void Socket_client::Connect(int sockfd,struct sockaddr *addr,socklen_t addrlen){
    if(connect(sockfd,addr,addrlen) < 0){
        error_puts("connect error");
    }
}





