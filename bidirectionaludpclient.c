#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int client_socket;
        client_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),INADDR_ANY};
        socklen_t caddrsize=sizeof(caddr);
        char b[1024];
        while(1)
        {
                bzero(b,1024);
                printf("Enter message:");
                fgets(b,1024,stdin);
                sendto(client_socket,b,strlen(b),0,(struct sockaddr *)&caddr,caddrs>
                bzero(b,1024);

                recvfrom(client_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,&cad>
                printf("\nMessage from Server:%s",b);
        }
}
