
#pragma once

// Structure pour représenter un point (cellule)
typedef struct {
    int x, y;
} Point;

#define MAX 100

int bfs(int N, int M, int** maze, Point start, Point end);