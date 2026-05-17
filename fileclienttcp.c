#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int client_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        connect(client_socket,(struct sockaddr *)&caddr,sizeof(caddr));
        char fname[256],b[1024];
        printf("enter the name of the file");
        scanf("%s",fname);
        send(client_socket,fname,strlen(fname),0);
        bzero(b,1024);
        int n=recv(client_socket,b,sizeof(b)-1,0);b[n]='\0';
        printf("%s",b);
}
