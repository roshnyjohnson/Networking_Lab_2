#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/select.h>
#include<time.h>
int main()
{
        int server_socket,client_socket;
        server_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY},caddr;
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        listen(server_socket,5);
        client_socket=accept(server_socket,NULL,NULL);
        struct timeval tv={2,0};
        int base=0;
        int next=0;
        int ack;
        while(base<5)
        {
                while(next<base+4&&next<5)
                {
                        printf("Sending frame %d\n",next);
                        send(client_socket,&next,sizeof(next),0);
                        next++;
                }
                fd_set readfds;
                FD_ZERO(&readfds);
                FD_SET(client_socket,&readfds);

                int activity=select(client_socket+1,&readfds,NULL,NULL,&tv);

                if (activity>0)
                {
                        recv(client_socket,&ack,sizeof(ack),0);
                        printf("Recieved ACK %d\n",ack);
                        base=ack+1;
                }
                else{
                        printf("Failed to recieve ACK.Resending frame %d\n",base);
                        next=base;
                }
        }
}




