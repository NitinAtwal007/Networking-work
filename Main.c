#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 5

// Function to perform flooding
void flood(int network[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int currentNode) {
    printf("Node %d received the packet.\n", currentNode);

    // Mark the current node as visited
    visited[currentNode] = true;

    // Iterate through all possible nodes
    for (int i = 0; i < MAX_NODES; i++) {
        // If there's a connection to node i and it has not been visited
        if (network[currentNode][i] == 1 && !visited[i]) {
            printf("Node %d forwarding packet to Node %d.\n", currentNode, i);
            flood(network, visited, i);
        }
    }
}

int main() {
    // Example network with 5 nodes
    int network[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0}, // Node 0 is connected to Node 1 and Node 2
        {1, 0, 1, 1, 0}, // Node 1 is connected to Node 0, Node 2, and Node 3
        {1, 1, 0, 1, 0}, // Node 2 is connected to Node 0, Node 1, and Node 3
        {0, 1, 1, 0, 1}, // Node 3 is connected to Node 1, Node 2, and Node 4
        {0, 0, 0, 1, 0}  // Node 4 is connected to Node 3
    };

    int visited[MAX_NODES] = {0}; // Initialize all nodes as not visited

    // Start flooding from Node 0
    printf("Starting flooding from Node 0...\n");
    flood(network, visited, 0);

    return 0;
}
