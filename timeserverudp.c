#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>

int main()
{
        int server_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),{INADDR_ANY}},caddr;
        socklen_t caddrsize=sizeof(caddr);
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        char b[1024];
        while(1)
        {
                //printf("Enter TIME if you want time else end");
                //fgets(b,1024,stdin);
                bzero(b,1024);
                recvfrom(server_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,&cad>
                if (strncmp(b,"TIME",4)==0)
                {
                        printf("REcieved TIME request");
                        time_t now=time(NULL);
                        char * timestr=ctime(&now);
                        int timelen=strlen(timestr);
                        sendto(server_socket,timestr,timelen,0,(struct sockaddr *)&>

                }
                else if(strncmp(b,"end",3)==0)
                {
                        close(server_socket);
                        break;
                }
                //sendto(server_socket,timestr,timelen,0,(struct sockaddr *)&caddr,>
                //bzero(b,1024);
                //recvfrom(client_socket,timestr,sizeof(timestr),0,(struct sockaddr>
                //printf("The time is %s",timestr);
                close(server_socket);
        }
}


