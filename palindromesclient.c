/* palindrome_client.c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int client_socket;
    char str[100], result[100];

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in caddr =
    {AF_INET, htons(5555), inet_addr("127.0.0.1")};

    socklen_t caddrsize = sizeof(caddr);

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    sendto(client_socket, str, sizeof(str), 0,
            (struct sockaddr *)&caddr, caddrsize);

    recvfrom(client_socket, result, sizeof(result), 0,
            (struct sockaddr *)&caddr, &caddrsize);

    printf("%s\n", result);

    close(client_socket);
}
