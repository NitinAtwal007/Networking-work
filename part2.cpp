#include <stdio.h>

#define MAX_NODES 4  // Max number of nodes (routers)

// Function to perform flooding
void flood(int network[MAX_NODES][MAX_NODES], int source, int hopCount) {
    if (hopCount <= 0) {
        printf("Packet discarded at router %d (counter = 0)\n", source);
        return;  // Stop flooding if the counter reaches zero
    }

    printf("Flooding from router %d (counter = %d)\n", source, hopCount);

    for (int i = 0; i < MAX_NODES; i++) {
        if (network[source][i] == 1) {  // If there is a link, flood the adjacent router
            printf("Flooding to router %d from router %d\n", i, source);
            flood(network, i, hopCount - 1);  // Decrease the counter and flood the next router
        }
    }
}

int main() {
    // Manually defined 4x4 adjacency matrix
    int network[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int sourceRouter;
    int initialHopCount;

    // Ask the user for the source router and the hop count
    printf("Enter the source router (0 to 3): ");
    scanf("%d", &sourceRouter);
    printf("Enter the initial hop count: ");
    scanf("%d", &initialHopCount);

    // Perform flooding starting from the source router with the hop counter
    flood(network, sourceRouter, initialHopCount);

    return 0;
}

