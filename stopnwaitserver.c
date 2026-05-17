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

        int server_socket,i,n;
        Frame frame;
        int exp_seq=0;
        server_socket=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY},caddr;
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        socklen_t caddrsize=sizeof(caddr);
        while(1)
        {
                //frame.seq_no=seq;
                //sprintf(frame.data,"Packet %d",i);
                //sendto(client_socket,&frame,sizeof(Frame),0,(struct sockaddr *)&>
                /*if(rand()%10<4){
                        printf("\n error occured,the packet is dropped\n");
                        continue;
                }*/
                recvfrom(server_socket,&frame,sizeof(Frame),0,(struct sockaddr *)&caddr,&caddrsize);
                printf("Recievedthe frame%d,with data %s\n",frame.seq_no,frame.data);
                if(frame.seq_no==exp_seq)
                {
                        printf("Accepted the frame,preparing ACK %d\n",frame.seq_no);
                        frame.ack_no=frame.seq_no;
                        exp_seq=1-exp_seq;
                }
                else{
                        printf("Duplicate frame sending acknowledgement %d\n",frame.seq_no);
                        frame.ack_no=frame.seq_no;
                }
                if(rand()%10<4){
                        printf("\n error occured,the packet is dropped\n");
                        continue;
                }
                sendto(server_socket,&frame,sizeof(Frame),0,(struct sockaddr *)&caddr,caddrsize);
                printf("ACK %d sent\n",frame.ack_no);



        }

}

