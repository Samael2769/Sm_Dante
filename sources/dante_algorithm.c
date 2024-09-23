
#include <stdio.h>
#include "dante_algorithm.h"


int dante_algorithm(int N, int M, int **maze, Point start, Point end)
{
    // Appel de BFS
    if (bfs(N, M, maze, start, end)) {
        return 0;
    } else {
        return 1;
    }

    return 0;
}