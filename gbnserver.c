#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main()
{
        int server_socket,client_socket;
        server_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY};
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        listen(server_socket,5);
        int frame,ack;
        int expected=0;
        client_socket=accept(server_socket,NULL,NULL);
        while(1)
        {
                recv(client_socket,&frame,sizeof(frame),0);
                printf("Recieved frame%d\n",frame);

                if(expected==frame)
                {
                        if(rand()%3<1)
                        {
                                printf("Frame %d lost\n",frame);
                        }
                        else{
                                ack=expected;
                                send(client_socket,&ack,sizeof(ack),0);
                                printf("Sending ACK%d\n",ack);
                                expected++;
                        }
                }
                else{
                        ack=expected-1;
                        send(client_socket,&ack,sizeof(ack),0);
                        printf("Sending last NACK%d\n",ack);

                }


        }
}
