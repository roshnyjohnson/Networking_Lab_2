/* palindrome_server.c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int server_socket;
    char str[100], rev[100];
    int i, len, flag = 0;

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in saddr = {AF_INET, htons(5555), INADDR_ANY};

    bind(server_socket, (struct sockaddr *)&saddr, sizeof(saddr));

    socklen_t saddrsize = sizeof(saddr);

    recvfrom(server_socket, str, sizeof(str), 0,
            (struct sockaddr *)&saddr, &saddrsize);

    len = strlen(str);

    if(str[len-1] == '\n')
    {
        str[len-1] = '\0';
        len--;
    }

    for(i = 0; i < len; i++)
    {
        rev[i] = str[len-1-i];
    }

    rev[i] = '\0';

    if(strcmp(str, rev) == 0)
        strcpy(rev, "Palindrome");
    else
        strcpy(rev, "Not Palindrome");

    sendto(server_socket, rev, sizeof(rev), 0,
            (struct sockaddr *)&saddr, saddrsize);

    close(server_socket);
}
