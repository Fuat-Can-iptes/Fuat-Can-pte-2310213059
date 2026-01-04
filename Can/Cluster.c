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

void dfs(int node) {

    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {

    int clusterNo = 1;

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < N; i++) {

        if (visited[i] == 0) {
            printf("Cluster %d: ", clusterNo);
            dfs(i);
            printf("\n");
            clusterNo++;
        }
    }

    return 0;
}