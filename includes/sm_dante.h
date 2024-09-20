/*
** EPITECH PROJECT, 2022
** $$
** File description:
** include
*/

#ifndef SM_DANTE_H_
#define SM_DANTE_H_

#include "struct.h"

int sm_dante();
int dante_generator(map_t *map, int size_x, int size_y);
int dante_algorithm(int N, int M, int **maze, Point start, Point end);
int menu(dante_t *dante);
int gameplay(dante_t *dante);

#endif /* !SM_DANTE_H_ */