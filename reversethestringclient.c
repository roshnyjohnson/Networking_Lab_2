#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int client_socket;
        char b[1024],a[1024];
        client_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        connect(client_socket,(struct sockaddr *)&caddr,sizeof(caddr));
        socklen_t caddrsize=sizeof(caddr);
        printf("Enter a sentence\n");
        fgets(b,sizeof(b),stdin);
        send(client_socket,b,strlen(b),0);
        int j=recv(client_socket,a,sizeof(a),0);
        if(j>0)
        {
                printf("done");
        }


        printf("%s\n",a);

        close(client_socket);


}

