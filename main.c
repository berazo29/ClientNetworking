// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 5052

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "REG|12|Who is there|";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("Ping the server \n");
    send(sock , "Ping server" , strlen("Ping server") , 0 );

    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    memset(buffer,0,strlen(buffer));

    send(sock , "REG|12|Who are you?|" , strlen("REG|12|Who are you?|") , 0 );
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    memset(buffer,0,strlen(buffer));

    send(sock , "REG|13|Dijkstra who?|" , strlen("REG|13|Dijkstra who?|") , 0 );
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    memset(buffer,0,strlen(buffer));

    send(sock , "REG|3|Ahh|" , strlen("REG|3|Ahh|") , 0 );

    close(sock);

    return 0;
}
