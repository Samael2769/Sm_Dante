#include "dante_algorithm.h"
#include <stdlib.h>

// Mouvement possible dans 4 directions (haut, bas, gauche, droite)
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

// File d'attente pour BFS
typedef struct {
    Point data[MAX*MAX];
    int front, rear;
} Queue;

// Initialiser la file d'attente
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// Enfiler un point
void enqueue(Queue* q, Point p) {
    q->data[q->rear++] = p;
}

// Défiler un point
Point dequeue(Queue* q) {
    return q->data[q->front++];
}

// Vérifier si la file d'attente est vide
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Vérifier si un mouvement est valide (les 1 représentent les passages et les 0 les murs)
int isValid(int x, int y, int N, int M, int **maze, int **visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1 && !visited[x][y]);
}

// BFS pour trouver le chemin le plus court
int bfs(int N, int M, int **maze, Point start, Point end) {
    // Allocation dynamique pour le tableau visited
    int **visited = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        visited[i] = (int *)malloc(M * sizeof(int));
    }

    // Initialiser le tableau visited à 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    Queue q;
    initQueue(&q);

    visited[start.x][start.y] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        Point current = dequeue(&q);

        // Si on atteint la fin
        if (current.x == end.x && current.y == end.y) {
            // Libération de la mémoire avant de retourner
            for (int i = 0; i < N; i++)
                free(visited[i]);
            free(visited);
            return 1; // Chemin trouvé
        }

        // Explorer les 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + row[i];
            int newY = current.y + col[i];

            if (isValid(newX, newY, N, M, maze, visited)) {
                visited[newX][newY] = 1;
                Point next = {newX, newY};
                enqueue(&q, next);
            }
        }
    }

    // Libération de la mémoire si aucun chemin n'a été trouvé
    for (int i = 0; i < N; i++)
        free(visited[i]);
    free(visited);

    return 0; // Pas de chemin trouvé
}
