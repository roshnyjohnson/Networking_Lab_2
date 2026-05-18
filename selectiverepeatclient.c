#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()

{
        int client_socket;
        client_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        connect(client_socket,(struct sockaddr *)&caddr,sizeof(caddr));
        int tot=0;
        srand(time(0));
        //timeval tv={2,0};
        //setsockopt(client_socket,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv);
        char buff[1024];
        int i,j,k,n,nack_no;
        while(tot<8)
        {
                if(read(client_socket,buff,sizeof(buff))>0)
                {
                        //printf("Recieved %s",buff);
                        char id=buff[strlen(buff)-1];
                        if(rand()%4<2)
                        {
                                printf("Packet dropped.sending NACK%c\n",id);
                                sprintf(buff,"nack %c",id);
                                write(client_socket,buff,sizeof(buff));
                        }
                        else{
                                printf("Packet recieved.Sending ACK%c\n",id);
                                sprintf(buff,"ack %c",id);
                                write(client_socket,buff,sizeof(buff));
                                tot++;

                        }
                }
        }
}
