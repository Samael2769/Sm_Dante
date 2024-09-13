
#include <stdio.h>
#include "dante_algorithm.h"


int dante_algorithm(int N, int M, int **maze)
{
    Point start = {0, 0}; // Point de départ
    Point end = {4, 4};   // Point d'arrivée

    // Appel de BFS
    if (bfs(N, M, maze, start, end)) {
        printf("Chemin trouvé !\n");
    } else {
        printf("Pas de chemin disponible.\n");
    }

    return 0;
}