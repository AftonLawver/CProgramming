#include <stdio.h>
#include <stdlib.h>

int main() {
    int numberOfNodes = 0;
    printf("How many nodes are in the network?\n");
    scanf("%d", &numberOfNodes);
    if (numberOfNodes == 0) {
        return 1;
    }
    else {
        printf("The number of nodes is %d\n\n", numberOfNodes);
        // Create the adjacency matrix so that each child process will have access to it.

        // Create a process for each node
        // Each process will hold an array of arrays for the routing table.

    }

    return 0;
}
