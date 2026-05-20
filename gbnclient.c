#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/select.h>
#include<time.h>

int main()
{
        int client_socket;
        client_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        struct timeval tv={2,0};
        connect(client_socket,(struct sockaddr *)&caddr,sizeof(caddr));
        int base=0;
        int next=0;
        int ack,i,j,k;
        while(base<5)
        {
                while(next<base+4&&next<5)
                {
                        printf("sending frame%d\n",next);
                        send(client_socket,&next,sizeof(next),0);
                        next++;
                }
                fd_set readfds;
                FD_ZERO(&readfds);
                FD_SET(client_socket,&readfds);

                int activity=select(client_socket+1,&readfds,NULL,NULL,&tv);
                if(activity>0)
                {
                        recv(client_socket,&ack,sizeof(ack),0);
                        printf("Recieved ack%d\n",ack);
                        base=ack+1;
                }
                else{
                        printf("Failed to recieve ACK.Resending frame %d\n",base);
                        next=base;
                }

        }
}
