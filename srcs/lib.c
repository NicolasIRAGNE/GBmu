#include "lib.h"
#include <signal.h>

void test_link()
{
    printf("Called!");
}

int init_gb(const char* rom)
{
    // Init cpu global state
    if ((gb_global.rom_ptr = malloc(sizeof(struct rom_s))) == NULL)
        return (1);
    if (open_rom(rom, gb_global.rom_ptr))
        return (1);
    if (gb_global.rom_ptr->header->title[15] == 0x80 || gb_global.rom_ptr->header->title[15] == 0xC0)
        gb_global.mode = GB_MODE_CGB;
    else
        gb_global.mode = GB_MODE_DMG;
    gb_global.booted = 1;
    init_registers(&gb_global.reg, gb_global.booted, gb_global.mode);
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

    // Init Cpu instructions
    init_op_tab();
    init_ext_op_tab();

    // Load save
    load_game(&gb_global);

    return (0);
}

void destroy_gb()
{
    if (gb_global.mbc.ram_size > 0)
        save_game(&gb_global);

    free(gb_global.rom_ptr->ptr);
    free(gb_global.rom_ptr);
    free(gb_global.extra_ram);
}
