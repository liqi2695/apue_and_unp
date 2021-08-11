#include "unp.h"
#include <iostream>


int main(int argc,char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char buff[30];
    int str_len;

    if((sock = socket(PF_INET,SOCK_STREAM,0)) < 0){
        std::cout << "create socket error" << std::endl;
    }

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0){
        std::cout << "connect error" << std::endl;
    }

    str_len = read(sock,buff,sizeof(buff) - 1);
    if(str_len == -1){
        std::cout << "read error" << std::endl;
    }
    std::cout <<  "message form server:" << buff << std::endl;
    close(sock);
    return 0;
}