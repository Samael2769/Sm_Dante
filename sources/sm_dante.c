/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_dante
*/

#include <stdio.h>
#include "sm_dante.h"

int sm_dante()
{
    int size_x = 20;
    int size_y = 20;
    int **maze = init_map(size_x, size_y);
    map_t map = {
        .size_x = size_x,
        .size_y = size_y,
        .map = maze
    };

    print_int_map(maze, size_x, size_y);
    maze = depth_first_backtracking(&map);
    print_int_map(maze, size_x, size_y);
    dante_algorithm(size_x, size_y, maze);
    return 0;
}