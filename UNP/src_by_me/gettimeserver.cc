#include "unp.h"
#include <iostream>


int main(int argc, char *argv[])
{
    int servfd;
    int cliefd;
    struct sockaddr_in server_addr;
    struct sockaddr_in clinet_addr;
    char buff[] = "liqi is a handsome boy";

    if( servfd = socket(PF_INET,SOCK_STREAM,0) < 0 ){
        std::cout<< "create socket error" <<std::endl;
    }
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if( bind(servfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1 ){
        std::cout << "bind error" <<std::endl;
    }

    if( listen(servfd,5) == -1 ){
        std::cout << "listen error" << std::endl;
    }

//clent response
    socklen_t client_addr_size;
    client_addr_size = sizeof(clinet_addr);
    if((cliefd = accept(servfd,(struct sockaddr*)&clinet_addr,&client_addr_size)) == -1){
        std::cout << "accept error" <<std::endl;
    }
    write(cliefd,buff,sizeof(buff));
    close(servfd);
    close(cliefd);
    return 0;

}