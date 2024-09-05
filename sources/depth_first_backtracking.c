/*
Implémentation de l'algorithme de backtracking en profondeur
*/

#include "dante_generator.h"
#include <stdio.h>
#include <stdlib.h>


int DIRECTIONS[4][2] = {
    {0, 1},  // droite
    {0, -1}, // gauche
    {1, 0},  // bas
    {-1, 0}  // haut
};

int is_valid(int **visited, int x, int y, int size_x, int size_y) {
    return (x >= 0 && x < size_x && y >= 0 && y < size_y && !visited[x][y]);
}

void remove_wall(int **maze, int x1, int y1, int x2, int y2) {
    maze[x1][y1] = 1;  // Marquer la première cellule comme chemin
    maze[x2][y2] = 1;  // Marquer la seconde cellule comme chemin
    maze[(x1 + x2) / 2][(y1 + y2) / 2] = 1;  // Supprimer le mur entre les deux
}

void dfs(int **maze, int **visited, int x, int y, int size_x, int size_y) {
    visited[x][y] = 1;  // Marquer la cellule comme visitée

    // Mélanger les directions pour rendre la génération du labyrinthe aléatoire
    int dir[4] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = dir[i];
        dir[i] = dir[j];
        dir[j] = temp;
    }

    // Parcours des 4 directions aléatoires
    for (int i = 0; i < 4; i++) {
        int dx = DIRECTIONS[dir[i]][0];
        int dy = DIRECTIONS[dir[i]][1];
        int nx = x + 2 * dx;
        int ny = y + 2 * dy;

        if (is_valid(visited, nx, ny, size_x, size_y)) {
            remove_wall(maze, x, y, nx, ny);
            dfs(maze, visited, nx, ny, size_x, size_y);
        }
    }
}

int **depth_first_backtracking(map_t *map)
{
    map_t visited = {
        .size_x = map->size_x,
        .size_y = map->size_y,
        .map = init_map(map->size_x, map->size_y)
    };
    int start_x = (rand() % (map->size_x / 2)) * 2;
    int start_y = (rand() % (map->size_y / 2)) * 2;
    dfs(map->map, visited.map, start_x, start_y, map->size_x, map->size_y);
    free_map(visited.map, visited.size_y);
    print_map(map->map, map->size_x, map->size_y);
    return map->map;
}

