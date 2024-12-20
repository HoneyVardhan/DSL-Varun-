#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void DFS(int start) {
    push(start);
    while (!isEmpty()) {
        int v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
            for (int i = MAX; i >= 0; i--) {
                if (adj[v][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}

int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1; 
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);

    return 0;
}
