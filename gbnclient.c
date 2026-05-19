#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/select.h>
#include<time.h>
int main()
{
        int client_socket;
        client_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        connect(client_socket,(struct sockaddr *)&caddr,sizeof(caddr));
        struct timeval tv={2,0};
        int base=0;
        int next=0;
        int expected=0;
        int ack,frame;
        while(1)
        {
                recv(client_socket,&frame,sizeof(frame),0);
                printf("Recieved frame %d\n",frame);
                if(frame==expected)
                {
                        if(rand()%3<1)
                        {
                                printf("Lost Frame %d.\n",frame);
                        }
                        else{
                                ack=frame;
                                printf("Sending ACK %d\n",ack);
                                send(client_socket,&ack,sizeof(ack),0);
                                expected++;
                        }
                }
                else{
                        ack=expected-1;
                        printf("Out of order.Sending (last ) nack %d\n",ack);
                        send(client_socket,&ack,sizeof(ack),0);

                }
        }
}


