#include <stdio.h>
#define MAX_SIZE 100

int adj_matrix[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE];
int n;

void dfs(int vert) {
    int i;
    printf("%d ", vert);
    visited[vert] = 1;
    for (i = 0; i < n; i++) {
        if (adj_matrix[vert][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj_matrix[i][j]);
    
    printf("\nThe DFS path is\n");
    dfs(0);
    printf("\n");

    return 0;
}
