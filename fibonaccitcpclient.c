#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int server_socket,client_socket;
        int i,j,end;
        int flag=0;
        int n;
        int a[100];
        server_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY};
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        listen(server_socket,5);
        client_socket=accept(server_socket,NULL,NULL);
        socklen_t saddrsize=sizeof(saddr);
        recv(client_socket,&n,sizeof(n),0);
        int x=0;
        a[0]=0;
        a[1]=1;
        int y=1;
        for(i=2;i<n;i++)
        {
                int z=x+y;
                x=y;
                y=z;
                a[i]=z;
        }

        send(client_socket,a,sizeof(a),0);



}
