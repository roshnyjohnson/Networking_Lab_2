#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int server_socket,client_socket;
        int i;
        int flag=0;
        int k=0;
        char b[1024];
        char a[1024]="";
        server_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY};
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        socklen_t saddrsize=sizeof(saddr);
        //sendto(server_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,caddrsize);
        recvfrom(server_socket,b,sizeof(b),0,(struct sockaddr *)&saddr,&saddrsize);
        for(i=0;i<strlen(b);i++)
        {
                flag=0;
                for(k=0;k<strlen(a);k++)
                {
                        if(b[i]==a[k])
                        {
                                flag=1;
                        }
                }
                if(flag==0)
                {
                        a[strlen(a)]=b[i];
                }
        }
        a[strlen(a)+1]='\0';
        sendto(server_socket,a,strlen(a),0,(struct sockaddr *)&saddr,saddrsize);



}

