#ifndef LIB_H
# define LIB_H

#include "gbmu.h"
#include "op.h"
#include "debug.h"

void test_link();

void set_a();
void reset_a();

void set_b();
void reset_b();

void set_start();
void reset_start();

void set_select();
void reset_select();

void set_up();
void reset_up();

void set_down();
void reset_down();

void set_left();
void reset_left();

void set_right();
void reset_right();

void debug_palette_toogle();

extern uint32_t m_TextureData[160][144];

int init_gb(const char* rom);

void destroy_gb();

#endif
