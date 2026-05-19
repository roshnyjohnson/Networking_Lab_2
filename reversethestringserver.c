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
        int k=0;
        char b[1024];
        char a[1024]="";
        server_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY};
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        listen(server_socket,5);
        client_socket=accept(server_socket,NULL,NULL);
        socklen_t saddrsize=sizeof(saddr);
        int start=0;
        //sendto(server_socket,b,sizeof(b),0,(struct sockaddr *)&caddr,caddrsize);
        recv(client_socket,b,sizeof(b),0);
        for(i=0;i<strlen(b);i++)
        {
                if(b[i]==' '||b[i]=='\n')
                {
                        end=i-1;
                        for(j=end;j>=start;j--)
                        {
                                a[k]=b[j];
                                k++;
                        }
                        a[k]=' ';
                        k++;
                        start=i+1;
                }
        }
        a[strlen(a)]='\0';
        printf("%s",a);

        send(client_socket,a,strlen(a),0);



}
