#include "struct.h"
#include "sm_timer.h"
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

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

int move_player(map_t *map, Point *player)
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

int is_end_game(Point player, Point end, sm_timer_t timer)
{
    if (is_same_point(player, end)) {
        return 1;
    }
    if (timer.is_finished) {
        return 2;
    }
    return 0;
}


int gameplay(dante_t *dante)
{
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    clear();
    refresh();
    sm_timer_t timer = dante->timer;

    time_t start_time = time(NULL);
    time_t last_time = start_time;
    time_t current_time;
    bool is_end = false;

    map_t *map = dante->map;
    Point start = dante->start;
    Point end = dante->end;
    Point player = start;
    while(is_end != true) {
        print_map_ncurses(map, start, end, player);
        if (move_player(map, &player) == 2) {
            is_end = true;
        }
        current_time = time(NULL);
        if (difftime(current_time, last_time) >= 1) {
            update_timer(&timer);
            last_time = current_time;
        }
        print_time(timer, 0, map->size_y + 1);
        refresh();
        switch (is_end_game(player, end, timer)) {
            case 1:
                is_end = true;
                break;
            case 2:
                is_end = true;
                break;
            default:
                break;
        }
        napms(10);
    }
    endwin();
    return is_end_game(player, end, timer);
}

int menu(dante_t *dante) {
    initscr();
    noecho();
    nodelay(stdscr, FALSE); // Permet l'entrée des chiffres
    keypad(stdscr, TRUE);   // Activer les touches spéciales comme KEY_UP, KEY_DOWN

    int ch;
    int selected = 0;
    char *choices[] = {
        "Labyrinth width (X):",
        "Labyrinth height (Y):",
        "Difficulty level (0-10):",
        "Start",
        "Quit"
    };

    int n_choices = sizeof(choices) / sizeof(char *);
    int x = 10;    // Valeur par défaut pour la largeur du labyrinthe
    int y = 10;    // Valeur par défaut pour la hauteur du labyrinthe
    int difficulty = 5; // Valeur par défaut pour la difficulté

    while (1) {
        clear();
        
        for (int i = 0; i < n_choices; i++) {
            if (i == selected) {
                attron(A_REVERSE);
            }
            
            if (i == 0) {
                mvprintw(i + 1, 1, "%s %d", choices[i], x);
            } else if (i == 1) {
                mvprintw(i + 1, 1, "%s %d", choices[i], y);
            } else if (i == 2) {
                mvprintw(i + 1, 1, "%s %d", choices[i], difficulty);
            } else {
                mvprintw(i + 1, 1, "%s", choices[i]);
            }
            
            if (i == selected) {
                attroff(A_REVERSE);
            }
        }

        ch = getch();
        
        switch (ch) {
            case 'z':
            case 'Z':
                selected--;
                if (selected < 0) {
                    selected = n_choices - 1;
                }
                break;
            case 's':
            case 'S':
                selected++;
                if (selected >= n_choices) {
                    selected = 0;
                }
                break;
            case 10: // Touche Enter
                if (selected == 3) { // Start
                    endwin();
                    dante->map = (map_t *)malloc(sizeof(map_t));
                    dante->map->size_x = x;
                    dante->map->size_y = y;
                    dante->difficulty = difficulty;
                    return 0; // Démarrer le jeu
                } else if (selected == 4) { // Quit
                    endwin();
                    return 1; // Quitter le jeu
                }
                break;
            case KEY_BACKSPACE: // Gérer la suppression avec Backspace
                if (selected == 0 && x > 0) {
                    x /= 10; // Supprimer le dernier chiffre
                } else if (selected == 1 && y > 0) {
                    y /= 10; // Supprimer le dernier chiffre
                } else if (selected == 2 && difficulty > 0) {
                    difficulty /= 10; // Supprimer le dernier chiffre
                }
                break;
            default:
                // Si l'utilisateur sélectionne une option avec des valeurs numériques
                if (selected == 0 && ch >= '0' && ch <= '9') {
                    x = x * 10 + (ch - '0'); // Ajouter le chiffre à x
                } else if (selected == 1 && ch >= '0' && ch <= '9') {
                    y = y * 10 + (ch - '0'); // Ajouter le chiffre à y
                } else if (selected == 2 && ch >= '0' && ch <= '9') {
                    int temp = ch - '0';
                    if (temp > 0 && temp <= 10) {
                        difficulty = temp; // Mettre à jour la difficulté
                    }
                }
                break;
        }
    }

    endwin();
    return 0;
}