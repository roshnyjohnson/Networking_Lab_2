#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int server_socket;
        server_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY},caddr;
        socklen_t caddrsize=sizeof(caddr);
        char b[1024];
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        while(1)
        {
                bzero(b,1024);
                recvfrom(server_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,&cad>
                printf("\nMessage from Client:%s",b);
                bzero(b,1024);
                printf("Enter message:");
                fgets(b,1024,stdin);
                sendto(server_socket,b,strlen(b),0,(struct sockaddr *)&caddr,caddrs>
        }
}
