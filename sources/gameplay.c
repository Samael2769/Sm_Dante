#include "struct.h"
#include <ncurses.h>


int print_map_ncurses(map_t *map, Point start, Point end, Point player)
{
    //print boders
    for (int i = 0; i < map->size_x + 1; i++) {
        mvprintw(0, i, "#");
    }
    for (int i = 1; i < map->size_y + 1; i++) {
        for (int j = 0; j < map->size_x + 1; j++) {
            if (i - 1 == player.y && j - 1 == player.x) {
                mvprintw(i, j, "P");
            } else if (i -1 == end.y && j - 1 == end.x) {
                mvprintw(i, j, "E");
            } else if (i - 1 == start.y && j - 1 == start.x) {
                mvprintw(i, j, "S");
            } else if (map->map[i - 1][j - 1] == 0) {
                mvprintw(i, j, "#");
            } else if (map->map[i - 1][j - 1] == 1) {
                mvprintw(i, j, " ");
            }
        }
    }
    return 0;
}


int gameplay(map_t *map, Point start, Point end)
{
    initscr();
    noecho();
    bool is_end = false;
    while(is_end != true) {
        print_map_ncurses(map, start, end, start);
        refresh();
    }
    endwin();
    return 0;
}