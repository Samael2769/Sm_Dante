/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_dante
*/

#include <stdio.h>
#include "sm_dante.h"
#include <unistd.h>


int sm_dante()
{

    while(1) {
        dante_t dante;

        //Menu de configuration
        if (menu(&dante) == 1) {
            printf("Goodbye\n");
            return 0;
        }

        //Initialisation du labyrinthe
        int size_x = dante.map->size_x;
        int size_y = dante.map->size_y;
        int **maze = init_map(size_x, size_y);
        map_t map = {
            .size_x = size_x,
            .size_y = size_y,
            .map = maze
        };
        Point start = {0, 0};
        Point end = {size_x - 2 , size_y - 2};
        dante.start = start;
        dante.end = end;
        dante.map = &map;
        dante.timer = create_timer(dante.map->size_x * dante.map->size_y / (dante.difficulty * 2));

        //Generation et vérification du labyrinthe
        dante_generator(dante.map, dante.map->size_x, dante.map->size_y);
        dante_algorithm(dante.map->size_x, dante.map->size_y, dante.map->map, dante.start, dante.end);

        //Début du jeu
        gameplay(&dante);
    }
    return 0;
}