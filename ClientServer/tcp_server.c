#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>

#include <netinet/in.h>
#include <unistd.h>

#define MAX 500
#define PORT 12587

void func(int connfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;

        // and send that buffer to client
        write(connfd, buff, sizeof(buff));

        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main() {

    struct sockaddr_in server_address;
    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&server_address, sizeof(server_address));
    // define the server address

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to our specified IP and port #
    int bind_socket = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_socket != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("socket successfully binded..\n");

    // listen for connections, and make it be able to have 5 clients connected
    int server_listening = listen(server_socket, 5);
    if (server_listening != 0 ) {
        printf("Server listening failed..\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    int client_socket;
    printf("Waiting for a connection on port %d\n", PORT);
    client_socket = accept(server_socket, NULL, NULL);
    if (client_socket < 0) {
        printf("server accept failed..\n");
        exit(0);
    }
    else
        printf("server accepted the client...\n");

    func(client_socket);

    close(server_socket);


    // parameters: socket that we are accepting connections on


    // close the socket
    return 0;
}