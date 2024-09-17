#include <stdio.h>

#define MAX_NODES 4  // Max number of nodes (routers)

// Function to perform flooding for all lines
void flood_all_lines(int network[MAX_NODES][MAX_NODES], int source, int hopCount, int time) {
    if (hopCount <= 0) {
        printf("Time %d: Packet discarded at router %d (counter = 0)\n", time, source);
        return;
    }

    printf("Time %d: Flooding from router %d (counter = %d)\n", time, source, hopCount);

    for (int i = 0; i < MAX_NODES; i++) {
        if (network[source][i] == 1) {  // If there is a link, flood to adjacent router
            printf("Time %d: Flooding to router %d from router %d\n", time, i, source);
            flood_all_lines(network, i, hopCount - 1, time + 1);  // Decrease counter, increase time
        }
    }
}

// Function to flood all lines except the input line
void flood_except_input(int network[MAX_NODES][MAX_NODES], int source, int previousRouter, int hopCount, int time) {
    if (hopCount <= 0) {
        printf("Time %d: Packet discarded at router %d (counter = 0)\n", time, source);
        return;
    }

    printf("Time %d: Flooding from router %d (counter = %d)\n", time, source, hopCount);

    for (int i = 0; i < MAX_NODES; i++) {
        if (network[source][i] == 1 && i != previousRouter) {  // Skip the input line
            printf("Time %d: Flooding to router %d from router %d\n", time, i, source);
            flood_except_input(network, i, source, hopCount - 1, time + 1);  // Decrease counter, increase time
        }
    }
}

// Function to flood the best k lines
void flood_best_k_lines(int network[MAX_NODES][MAX_NODES], int source, int hopCount, int time, int k) {
    if (hopCount <= 0) {
        printf("Time %d: Packet discarded at router %d (counter = 0)\n", time, source);
        return;
    }

    printf("Time %d: Flooding from router %d (counter = %d)\n", time, source, hopCount);

    int lines_flooded = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        if (network[source][i] == 1 && lines_flooded < k) {  // Flood only k lines
            printf("Time %d: Flooding to router %d from router %d\n", time, i, source);
            flood_best_k_lines(network, i, hopCount - 1, time + 1, k);  // Decrease counter, increase time
            lines_flooded++;
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

    int sourceRouter, initialHopCount, version, k;

    // Ask the user for the source router, hop count, and version
    printf("Enter the source router (0 to 3): ");
    scanf("%d", &sourceRouter);
    printf("Enter the initial hop count: ");
    scanf("%d", &initialHopCount);
    printf("Choose the flooding version (1: All lines, 2: All except input line, 3: Best k lines): ");
    scanf("%d", &version);

    if (version == 3) {
        printf("Enter the value of k (best k lines to flood): ");
        scanf("%d", &k);
    }

    // Perform flooding based on the chosen version
    switch (version) {
        case 1:
            flood_all_lines(network, sourceRouter, initialHopCount, 0);
            break;
        case 2:
            flood_except_input(network, sourceRouter, -1, initialHopCount, 0);  // No previous router for source
            break;
        case 3:
            flood_best_k_lines(network, sourceRouter, initialHopCount, 0, k);
            break;
        default:
            printf("Invalid version choice.\n");
            break;
    }

    return 0;
}

