#include "lib.h"
#include <stdlib.h>
#include <signal.h>

void test_link()
{
    printf("Called!");
}

int init_gb(const char* rom)
{
    // Init cpu global state
	memset(&gb_global, 0, sizeof(gb_global));
    if ((gb_global.rom_ptr = malloc(sizeof(struct rom_s))) == NULL)
        return (1);
    if (open_rom(rom, gb_global.rom_ptr))
        return (1);
    if (gb_global.rom_ptr->header->title[15] == 0x80 || gb_global.rom_ptr->header->title[15] == 0xC0)
        gb_global.mode = GB_MODE_CGB;
    else
        gb_global.mode = GB_MODE_DMG;
    debug_print_rom(gb_global.rom_ptr);
    gb_global.booted = 1;
    init_registers(&gb_global.reg, gb_global.booted, gb_global.mode);
    // Init Cpu instructions
    init_op_tab();
    init_ext_op_tab();

    // Load save
    load_game(&gb_global);

    if (gb_global.mode == GB_MODE_DMG)
    {
        return (init_cpu_dmg(&gb_global, gb_global.rom_ptr));
    }
    else if (gb_global.mode == GB_MODE_CGB)
    {
        return (init_cpu_cgb(&gb_global, gb_global.rom_ptr));
    }
    else
    {
        fprintf(stderr, "fatal : unrecognized hardware type\n");
        return (1);
    }
}

void destroy_gb()
{
    if (gb_global.mbc.ram_size > 0)
        save_game(&gb_global);

    free(gb_global.rom_ptr->ptr);
    free(gb_global.rom_ptr);
    free(gb_global.extra_ram);
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
