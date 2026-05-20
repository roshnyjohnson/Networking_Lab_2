#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
        int server_socket=socket(AF_INET,SOCK_STREAM,0),client_socket;
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY},caddr;
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        socklen_t caddrsize=sizeof(caddr);
        listen(server_socket,5);
        client_socket=accept(server_socket,NULL,NULL);
        char fname[256],b[1024],content[2048];
        //printf("enter the name of the file");
        //fgets(fname,256,stdin);
        //send(client_socket,fname,strlen(fname),0);
        //bzero(b,1024);
        fork();{
        int n=recv(client_socket,fname,sizeof(fname)-1,0);fname[n]='\0';
        FILE *fp=fopen(fname,"r");
        if(fp!=NULL)
        {
                n=fread(content,1,2047,fp);content[n]='\0';
                snprintf(b,sizeof(b),"[procrss:%d]The file content of %s is %s",getpid(),fname,content);
                send(client_socket,b,strlen(b),0);
        }
        else
        {
                 snprintf(b,sizeof(b),"[procrss:%d]The file %d does not exist\n ",getpid());
                 send(client_socket,b,strlen(b),0);

        }
         printf("[PID :%d] Response sent\n",getpid());
        }
}
