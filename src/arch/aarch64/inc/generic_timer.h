#ifndef TIMER_H
#define TIMER_H

#include "utils.h"

static uint64_t TIMER_WAIT = 2;

void set_el2_timer_sec(uint64_t);
void timer_el2_init (void);
void timer_handler2(void);

#endif