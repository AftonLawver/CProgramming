#include <stdio.h>

struct node {
    int dist[20];
    int from[20];
} route[10];

//void bellman_ford(int source) {
//    // initialize distances to all vertices as infinity except the source vertex
//    for (int i = 0; i < num_vertices; i++) {
//        if (i == source) {
//            dist[i] = 0;
//        } else {
//            dist[i] = INT_MAX;
//        }
//    }
//
//    // relax edges repeatedly
//    for (int i = 0; i < num_vertices - 1; i++) {
//        for (int j = 0; j < num_edges; j++) {
//            int u = edges[j].source;
//            int v = edges[j].dest;
//            int w = edges[j].weight;
//            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//            }
//        }
//    }
//}

int main()
{
    int nodes;
    printf("Enter number of nodes:\n");
    scanf("%d", &nodes);
    int nodeTracker[nodes][nodes];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &nodeTracker[i][j]);
            /*  Set distance from i to i as 0 */
            nodeTracker[i][i] = 0;
            route[i].dist[j] = nodeTracker[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do {
        flag = 0;
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                for (int k = 0; k < nodes; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < nodes; i++) {
        printf("Router info for router: %d\n", i+1);
        printf("Dest\tNext Hop\tDist\n");
        for (int j = 0; j < nodes; j++)
            printf("%d\t\t\t%d\t\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
    }
    return 0;
}