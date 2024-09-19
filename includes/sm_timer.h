
#pragma once

#include <stdbool.h>
#include <ncurses.h>

typedef struct sm_timer_s
{
    int time;
    int max_time;
    bool is_paused;
    bool is_finished;
} sm_timer_t;

sm_timer_t create_timer(int time);
int update_timer(sm_timer_t *timer);
int pause_timer(sm_timer_t *timer);
int resume_timer(sm_timer_t *timer);
int reset_timer(sm_timer_t *timer);
void print_time(sm_timer_t timer, int posX, int posY);