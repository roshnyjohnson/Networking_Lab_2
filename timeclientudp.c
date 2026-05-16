#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
        int client_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        socklen_t caddrsize=sizeof(caddr);
        char b[1024];
        char * timestr;
        while(1)
        {
                printf("Enter TIME if you want time else end");
                fgets(b,1024,stdin);
                if(strncmp(b,"end",3)==0)
                {
                        close(client_socket);
                        break;
                }
                sendto(client_socket,b,strlen(b),0,(struct sockaddr *)&caddr,caddrs>
                bzero(b,1024);
                recvfrom(client_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,&cad>
                printf("The time is %s\n",b);
        }
}
