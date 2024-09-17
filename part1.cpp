// This code is written by Nitin Atwal
#include <stdio.h>

#define MAX_NODES 4  // Max number of nodes (routers)

// Function to perform flooding
void flood(int network[MAX_NODES][MAX_NODES], int source) {
    printf("Flooding from router %d\n", source);
    for (int i = 0; i < MAX_NODES; i++) {
        if (network[source][i] == 1) {  // If there is a link, flood the adjacent router
            printf("Flooding to router %d\n", i);
        }
    }
}

int main() {
    // Manually defined 4x4 adjacency matrix
    int network[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };

    int sourceRouter;
    printf("Enter the source router (0 to 3): ");
    scanf("%d", &sourceRouter);

    // Perform flooding starting from the source router
    flood(network, sourceRouter);

    return 0;
}

