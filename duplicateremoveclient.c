#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int client_socket;
        char b[1024],a[1024];
        client_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        socklen_t caddrsize=sizeof(caddr);
        printf("Enter a word\n");
        fgets(b,sizeof(b),stdin);
        sendto(client_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,caddrsize);
        int j=recvfrom(client_socket,a,sizeof(a),0,(struct sockaddr *)&caddr,&ca>
        if(j>0)
        {
                printf("%d",j);
        }


        printf("%s\n",a);

        close(client_socket);


}


