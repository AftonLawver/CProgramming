#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>

#include <netinet/in.h>
#include <unistd.h>
#define MAX 500
#define PORT 12587

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the command : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        int command_status = system(buff);
        if (command_status != 0) {
            write(sockfd, "System command does not exist", sizeof(buff));
            continue;
        }
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    char *ip_address = argv[1];
    // create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // receive data from the server
   func(network_socket);

    // close the socket
    close(network_socket);
    return 0;
}
