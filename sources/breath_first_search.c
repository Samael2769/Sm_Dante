
#include "dante_algorithm.h"

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

// Vérifier si un mouvement est valide
int isValid(int x, int y, int N, int M, int maze[N][M], int visited[N][M]) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y]);
}

// BFS pour trouver le chemin le plus court
int bfs(int N, int M, int **maze, Point start, Point end) {
    int visited[N][M];
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

    return 0; // Pas de chemin trouvé
}