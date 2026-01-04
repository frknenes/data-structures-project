#include <stdio.h>
#include <stdbool.h>

#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void DFS(int graph[MAX][MAX], bool visited[], int start) {
    printf("%d ", start);
    visited[start] = true;

    for (int i = 0; i < MAX; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

void BFS(int graph[MAX][MAX], bool visited[], int start) {
    enqueue(start);
    visited[start] = true;

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

void resetVisited(bool visited[]) {
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0} 
    };

    bool visited[MAX];

    resetVisited(visited);
    printf("DFS Traversal: ");
    DFS(graph, visited, 0);
    printf("\n");

    resetVisited(visited);
    front = -1; 
    rear = -1;  
    
    printf("BFS Traversal: ");
    BFS(graph, visited, 0);
    printf("\n");

    return 0;
}