#pragma once

#include "keyboard.h"

struct fifo_item
{
	uint8_t scancode;

	uint8_t _ : 1;
	uint8_t shift_modifier : 1;
	uint8_t ctrl_modifier : 1;
	uint8_t altgr_modifier : 1;
	enum key_state state : 4;
};

uint8_t fifo_count(void);
void fifo_flush(void);
bool fifo_enqueue(const struct fifo_item item);
void fifo_enqueue_force(const struct fifo_item item);
struct fifo_item fifo_dequeue(void);
