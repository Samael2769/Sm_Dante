
#include <stdio.h>
#include "dante_algorithm.h"


int dante_algorithm(void)
{
    // Dimensions du labyrinthe
    int N = 5;
    int M = 5;

    // Labyrinthe : 0 = chemin, 1 = mur
    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

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