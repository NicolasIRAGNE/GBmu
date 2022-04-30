#ifndef LIB_H
# define LIB_H

#include "gbmu.h"
#include "op.h"
#include "debug.h"

uint8_t get_data_8(uint16_t address);
uint16_t get_data_16(uint16_t address);

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

int init_gb(const char* rom, const char* mode);

void destroy_gb();

void load_state(uint32_t slot);
void save_state(uint32_t slot);

uint8_t get_lcdc();
uint8_t get_stat();
uint8_t get_scy();
uint8_t get_scx();
uint8_t get_ly();
uint8_t get_lyc();
uint8_t get_dma();
uint8_t get_bgp();
uint8_t get_obp0();
uint8_t get_obp1();
uint8_t get_wy();
uint8_t get_wx();

#endif


