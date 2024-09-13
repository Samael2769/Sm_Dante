

#include "dante_generator.h"
#include <stdio.h>
#include <stdlib.h>

int **init_map(int size_x, int size_y)
{
    int **map = malloc(sizeof(int *) * size_y);
    for (int i = 0; i < size_y; i++)
    {
        map[i] = malloc(sizeof(int) * size_x);
        for (int j = 0; j < size_x; j++)
        {
            map[i][j] = 0;
        }
    }
    return map;
}

void print_map(int **map, int size_x, int size_y)
{
    for (int i = 0; i < size_x + 2; ++i)
    {
        printf("X");
    }
    printf("\n");
    for (int i = 0; i < size_y; i++)
    {
        printf("X");
        for (int j = 0; j < size_x; j++)
        {
            
            if (map[i][j] == 0)
                printf("X");
            else
                printf(" ");
        }
        printf("X");
        printf("\n");

    }
    for (int i = 0; i < size_x + 2; ++i)
    {
        printf("X");
    }
    printf("\n");
}

void print_int_map(int **map, int size_x, int size_y)
{
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

void free_map(int **map, int size_y)
{
    for (int i = 0; i < size_y; i++)
    {
        free(map[i]);
    }
    free(map);
}


int dante_generator(int size_x, int size_y)
{
    map_t map;
    map.size_x = size_x;
    map.size_y = size_y;
    map.map = init_map(size_x, size_y);
    depth_first_backtracking(&map);
    free_map(map.map, size_y);
    return 0;
}