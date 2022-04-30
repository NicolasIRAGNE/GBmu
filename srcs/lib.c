#include "lib.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "gb.h"
#include "memory.h"

void test_link()
{
    printf("Called!");
}

int init_gb(const char* rom_name, const char* mode)
{
    enum gb_mode_e m;
    // Convert mode string to gb_mode_e
    if (strcmp(mode, "dmg") == 0)
        m = GB_MODE_DMG;
    else if (strcmp(mode, "cgb") == 0)
        m = GB_MODE_CGB;
    else if (strcmp(mode, "auto") == 0)
        m = GB_MODE_AUTO;
    else
        m = GB_MODE_UNKNOWN;
    init_op_tab();
    init_ext_op_tab();
    struct rom_s* rom = malloc(sizeof(struct rom_s));
    if (open_rom(rom_name, rom))
        return (1);
    return (init_cpu(&gb_global, rom, m));
}


uint8_t get_data_8(uint16_t address)
{
    return read_8_debug(&gb_global, address);
}

uint16_t get_data_16(uint16_t address)
{
    return read_16_debug(&gb_global, address);
}

void destroy_gb()
{
    if (gb_global.mbc.ram_size > 0)
        save_game(&gb_global);

    free(gb_global.rom_ptr->ptr);
    free(gb_global.rom_ptr);
    free(gb_global.extra_ram);
}

void debug_palette_toogle() {
    gb_global.debug_palette = !gb_global.debug_palette;
}

void set_a()
{
    gb_global.joypad.a = 1;
}

void reset_a()
{
    gb_global.joypad.a = 0;
}

void set_b()
{
    gb_global.joypad.b = 1;
}

void reset_b()
{
    gb_global.joypad.b = 0;
}

void set_start()
{
    gb_global.joypad.start = 1;
}

void reset_start()
{
    gb_global.joypad.start = 0;
}

void set_select()
{
    gb_global.joypad.select = 1;
}

void reset_select()
{
    gb_global.joypad.select = 0;
}

void set_up()
{
    gb_global.joypad.up = 1;
}

void reset_up()
{
    gb_global.joypad.up = 0;
}

void set_down()
{
    gb_global.joypad.down = 1;
}

void reset_down()
{
    gb_global.joypad.down = 0;
}

void set_left()
{
    gb_global.joypad.left = 1;
}

void reset_left()
{
    gb_global.joypad.left = 0;
}

void set_right()
{
    gb_global.joypad.right = 1;
}

void reset_right()
{
    gb_global.joypad.right = 0;
}

void load_state(uint32_t slot)
{
    loadstate(&gb_global, slot);
}

void save_state(uint32_t slot)
{
    savestate(&gb_global, slot);
}

uint8_t get_lcdc()
{
    return read_8_debug(&gb_global, LCDC_OFFSET);
}

uint8_t get_stat()
{
    return read_8_debug(&gb_global, STAT_OFFSET);
}

uint8_t get_scx()
{
    return read_8_debug(&gb_global, SCX_OFFSET);
}

uint8_t get_scy()
{
    return read_8_debug(&gb_global, SCY_OFFSET);
}

uint8_t get_ly()
{
    return read_8_debug(&gb_global, LY_OFFSET);
}

uint8_t get_lyc()
{
    return read_8_debug(&gb_global, LYC_OFFSET);
}

uint8_t get_dma()
{
    return read_8_debug(&gb_global, DMA_OFFSET);
}

uint8_t get_bgp()
{
    return read_8_debug(&gb_global, BGP_OFFSET);
}

uint8_t get_obp0()
{
    return read_8_debug(&gb_global, OBP0_OFFSET);
}

uint8_t get_obp1()
{
    return read_8_debug(&gb_global, OBP1_OFFSET);
}

uint8_t get_wx()
{
    return read_8_debug(&gb_global, WX_OFFSET);
}

uint8_t get_wy()
{
    return read_8_debug(&gb_global, WY_OFFSET);
}