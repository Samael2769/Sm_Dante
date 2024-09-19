
#include "sm_timer.h"

sm_timer_t create_timer(int time) {
    sm_timer_t timer;
    timer.time = time;
    timer.max_time = time;
    timer.is_paused = false;
    timer.is_finished = false;
    return timer;
}

int update_timer(sm_timer_t *timer) {
    if (timer->is_paused || timer->is_finished) {
        return 0;
    }
    timer->time -= 1;
    if (timer->time <= 0) {
        timer->is_finished = true;
    }
    return 0;
}

int pause_timer(sm_timer_t *timer) {
    timer->is_paused = true;
    return 0;
}

int resume_timer(sm_timer_t *timer) {
    timer->is_paused = false;
    return 0;
}

int reset_timer(sm_timer_t *timer) {
    timer->time = timer->max_time;
    timer->is_paused = false;
    timer->is_finished = false;
    return 0;
}

void print_time(sm_timer_t timer, int posX, int posY) {
    mvprintw(posY, posX, "Time: %d !", timer.time);
}