/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "sm_dante.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    srand(time(NULL));
    if (sm_dante() != 0)
        return 84;
    return 0;
}