#include "wrapping.h"
#include "error.h"
int main(int argc,char **argv)
{
    int listenfd,connfd;
    struct sockaddr_in servaddr,cliaddr;
    socklen_t len;
    char buff[MAXLINE];
    time_t ticks;

    Socket_server sock_server;
    sock_server.Socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9999);

    sock_server.Bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    sock_server.Listen(listenfd,1024);

    for( ; ; ){
        len = sizeof(cliaddr);
        connfd = sock_server.Accept(listenfd, (struct sockaddr*)&cliaddr, &len);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        
        if(write(connfd, buff, strlen(buff)) < 0){
            error_puts("write error");
        }
        close(connfd);
    }
    

}