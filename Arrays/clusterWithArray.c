#include <stdio.h>
#include <stdbool.h>

#define V 7

void DFS(int graph[V][V], bool visited[], int startNode) {
    printf("%d ", startNode);
    visited[startNode] = true;

    for (int i = 0; i < V; i++) {
        if (graph[startNode][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

void findClusters(int graph[V][V]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int clusterCount = 0;

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            DFS(graph, visited, i);
            printf("\n");
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0}
    };

    findClusters(graph);

    return 0;
}