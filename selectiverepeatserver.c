#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()

{
        int server_socket,client_socket;
        server_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr={AF_INET,htons(5555),INADDR_ANY},caddr;
        bind(server_socket,(struct sockaddr *)&saddr,sizeof(saddr));
        listen(server_socket,5);
        client_socket=accept(server_socket,NULL,NULL);
        struct timeval tv={2,0};
        setsockopt(client_socket,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv));
        int tot=0;
        char buff[1024];
        int win=3;
        int i,j,n,nack_no;
        int k=0;
        while(tot<8)
        {
                for(j=tot;j<(tot+win)&&(j<8);j++)
                {
                        sprintf(buff,"Packet %d",j);
                        write(client_socket,buff,sizeof(buff));
                }
                for(k=0;k<win&&tot<8;k++)
                {
                        n=read(client_socket,buff,sizeof(buff));
                        if(n<=0)
                        {
                                printf("\n TIMEOUT.Retransmiting...\n");
                                sprintf(buff,"packet %d",tot);
                                k--;
                                write(client_socket,buff,sizeof(buff));


                        }
                        else if(buff[0]=='n'||buff[0]== 'N')
                        {
                                printf("Recieved negative acknowledgemnt %s\n",buff);
                                nack_no=buff[strlen(buff)-1]-'0';
                                sprintf(buff,"packet %d",nack_no);
                                k--;
                                write(client_socket,buff,sizeof(buff));

                        }
                        else{
                                printf("\nSuccessfully recieved acknowledgemnt %s\n",buff);
                                tot++;
                        }
                }
        }
}

