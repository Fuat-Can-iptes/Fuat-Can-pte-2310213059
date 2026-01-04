#include <stdio.h>

#define N 6

int graph[N][N] = {
    {0,1,0,0,0,0},
    {1,0,1,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,0,1,1},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0}
};

int visited[N];

void DFS(int node) {

    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {

    int queue[N];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {

        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < N; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS: ");
    DFS(0);

    printf("\nBFS: ");
    BFS(0);

    return 0;
}