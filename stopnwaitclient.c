#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/time.h>
#include<unistd.h>

typedef struct{
        int seq_no;
        int ack_no;
        char data[1024];

}Frame;
//struct timeval tv={2,0};
int main(){

        int client_socket,i,n;
        Frame frame;
        int seq=0;
        client_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in caddr={AF_INET,htons(5555),inet_addr("127.0.0.1")};
        socklen_t caddrsize=sizeof(caddr);
        struct timeval tv={2,0};
        setsockopt(client_socket,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv));
        i=0;
        while(i<6)
        {
                frame.seq_no=seq;
                sprintf(frame.data,"Packet %d",i);
                sendto(client_socket,&frame,sizeof(Frame),0,(struct sockaddr *)&caddr,caddrsize);
                n=recvfrom(client_socket,&frame,sizeof(Frame),0,(struct sockaddr *)&caddr,&caddrsize);
                if(frame.ack_no==seq)
                {
                        printf("Recieved ACK %d.Move to next packet\n",seq);
                        seq=1-seq;
                        i=i+1;
                }
                else if(n<0){
                        printf("\nLost|Retransmitting...\n");
                }
                sleep(1);
        }

}

