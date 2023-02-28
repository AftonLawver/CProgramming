// Afton Lawver
// 851463587

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>

#include <netinet/in.h>
#include <unistd.h>

#define MAX 50
#define PORT 12587

void func(int connfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        FILE *pipe;
        int len;
        char c = 0;
        // clear the contents the in buffer object
        bzero(buff, MAX);
        // read the message from client and copy it into the buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s", buff);

//        if (system(buff) != 0) {
//            write(connfd, "system command does not exist", sizeof(buff));
//        }
//
//        else {
////            write(connfd, "system command does exist!", sizeof(buff));
//            write(connfd, buff, sizeof(buff));
//            pipe = popen(buff, "r");
//            bzero(buff, MAX);
//            printf(buff);
//            fgets(buff, MAX, pipe);
//            len = strlen(buff);
//            buff[len-1] = '\0';
//            write(connfd, buff, sizeof(buff));
//            pclose(pipe);
//        }

//
//        else {
//            printf("system command does exist.");
//            fgets(buff, sizeof(buff), pipe);
//            len = strlen(buff);
//            buff[len-1] = '\0';
//            write(connfd, buff, sizeof(buff));
//            pclose(pipe);
//        };

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