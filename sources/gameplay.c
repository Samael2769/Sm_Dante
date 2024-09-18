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

int move_player(map_t *map, Point *player, Point end)
{
    int ch = getch();
    switch (ch) {
        case 'z':
        case 'Z':
            if (player->y - 1 >= 0 && map->map[player->y - 1][player->x] == 1) {
                player->y -= 1;
            }
            break;
        case 's':
        case 'S':
            if (player->y + 1 < map->size_y && map->map[player->y + 1][player->x] == 1) {
                player->y += 1;
            }
            break;
        case 'q':
        case 'Q':
            if (player->x - 1 >= 0 && map->map[player->y][player->x - 1] == 1) {
                player->x -= 1;
            }
            break;
        case 'd':
        case 'D':
            if (player->x + 1 < map->size_x && map->map[player->y][player->x + 1] == 1) {
                player->x += 1;
            }
            break;
        case 27: // ESC key
            return 2;
            break;
        default:
            break;
    }
    return 0;
}

int is_same_point(Point a, Point b)
{
    if (a.x == b.x && a.y == b.y) {
        return 1;
    }
    return 0;
}


int gameplay(map_t *map, Point start, Point end)
{
    initscr();
    noecho();
    bool is_end = false;
    Point player = start;
    while(is_end != true) {
        print_map_ncurses(map, start, end, player);
        move_player(map, &player, end);
        if (is_same_point(player, end)) {
            is_end = true;
        }
        refresh();
    }
    endwin();
    return 0;
}