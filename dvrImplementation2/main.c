#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTERS 10
#define INFINITY 9999

int num_routers;
int delay[MAX_ROUTERS][MAX_ROUTERS];
int next_hop[MAX_ROUTERS][MAX_ROUTERS];

void initialize_tables() {
    int i, j;

    // Initialize delay and next_hop tables
    for (i = 0; i < num_routers; i++) {
        for (j = 0; j < num_routers; j++) {
            if (i == j) {
                delay[i][j] = 0;
                next_hop[i][j] = i;
            } else {
                delay[i][j] = INFINITY;
                next_hop[i][j] = -1;
            }
        }
    }
}

void update_tables() {
    int i, j, k;
    int temp_delay;

    // Update delay and next_hop tables
    for (i = 0; i < num_routers; i++) {
        for (j = 0; j < num_routers; j++) {
            if (i == j) {
                continue;
            }

            temp_delay = delay[i][j];

            for (k = 0; k < num_routers; k++) {
                if (k == i) {
                    continue;
                }

                if (temp_delay > delay[i][k] + delay[k][j]) {
                    temp_delay = delay[i][k] + delay[k][j];
                    next_hop[i][j] = k;
                }
            }

            delay[i][j] = temp_delay;
        }
    }
}

void print_tables() {
    int i, j;

    // Print delay and next_hop tables
    printf("\nRouting Tables:\n");
    printf("Router\tDest.\tDelay\tNext Hop\n");

    for (i = 0; i < num_routers; i++) {
        for (j = 0; j < num_routers; j++) {
            if (delay[i][j] != INFINITY) {
                printf("%c\t%c\t%d\t%c\n", i + 'A', j + 'A', delay[i][j], next_hop[i][j] + 'A');
            }
        }
    }
}

int main() {
    int i, j;
    int node1, node2, temp_delay;

    // Read number of routers and their connections and delays
    printf("Enter the number of routers: ");
    scanf("%d", &num_routers);

    initialize_tables();

    printf("Enter the connections and delays (node1 node2 delay):\n");

    while (scanf("%d %d %d", &node1, &node2, &temp_delay) == 3) {
        delay[node1][node2] = temp_delay;
        delay[node2][node1] = temp_delay;
    }

    // Run Distance Vector Algorithm
    for (i = 0; i < num_routers; i++) {
        update_tables();
        print_tables();
    }

    return 0;
}