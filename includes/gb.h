/**
 * @file gb.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Contains most of the functions used by the emulator, and the internal gb struct.
 * @date 2021-12-31
 */

#ifndef GB_H
# define GB_H
#ifdef __cplusplus
extern "C" {
#endif

# include <sys/stat.h>
# include <sys/types.h>
// # include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>
// # include <sys/mman.h>
# include <stdint.h>
# include "op.h"
# include "ext_op.h"
# include <limits.h>
# include "mbc.h"
# include <stdio.h>
# include "renderer/wrapper_c/wrapper.h"

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define EOC	"\x1B[0m"

# define SAVE_DIR "../saves/"
# define SAVESTATE_DIR "../savestates/"

# define DEFAULT_VERBOSE 0

enum	gb_mode_e
{
	GB_MODE_DMG, ///< Original Gameboy mode.
	GB_MODE_CGB, ///< Color Gameboy mode.
	GB_MODE_GBA, ///< Gameboy Advance mode. Not supported.
	GB_MODE_AUTO, ///< Auto-detect the gameboy mode. This is done by reading the ROM header.
	GB_MODE_UNKNOWN ///< Unknown mode. This is not used but is here for completeness.
};

/**
 * @brief Info located at index 0x100 of the ROM.
 */
struct rom_hdr_s
{
    /// Entry point of the ROM. This is usually a jump to the ROM's main function.
    uint8_t entry[4];
    /**
     * @brief 48 bytes that correspond to the Nintendo logo.
     * This also acts as a checksum and is verified by the DMG boot rom. In case of a discrepancy, the gameboy will not boot.
     */
    uint8_t logo[48];
    /**
     * @brief The title of the game.
     * @warning
     * This is not as simple as it seems. On older cartridges, the 16 bytes correspond to the title of the game.
     * However, on newer cartridges (from the CGB onwards), the name is either 15 or 11 bytes long.
     * On these cartridges:
     * - bytes 12-15 contain a manufacturer code, that serves an unknown purpose.
     * - upper bite of byte 16 indicates wheter the game is a GBC game or not.
     */
    uint8_t title[16];
    /**
     * @brief Two characters that indicate the game developer.
     * @note This is on newer cartridges only, most cartridges use the rom_hdr_s::manufacturer_code_extend field instead.
     */
    uint8_t licensee_code[2];
    /**
     * @brief If this is set to 0x03, the game supports SGB functions, otherwise it does not.
     */
    uint8_t sgb_flag;
    /**
	 * 
     * @brief One of the most important fields of the ROM header. This indicates the type of the cartridge.
     *
     * - 0x00: ROM ONLY                 
     * - 0x01: MBC1                     
     * - 0x02: MBC1+RAM                 
     * - 0x03: MBC1+RAM+BATTERY         
     * - 0x05: MBC2                     
     * - 0x06: MBC2+BATTERY             
     * - 0x08: ROM+RAM                  
     * - 0x09: ROM+RAM+BATTERY          
     * - 0x0B: MMM01						
     * - 0x0C: MMM01+RAM					
     * - 0x0D: MMM01+RAM+BATTERY			
     * - 0x0F: MBC3+TIMER+BATTERY		
     * - 0x10: MBC3+TIMER+RAM+BATTERY   
     * - 0x11: MBC3                     
     * - 0x12: MBC3+RAM                 
     * - 0x13: MBC3+RAM+BATTERY         
	 * - 0x19: MBC5
	 * - 0x1A: MBC5+RAM
	 * - 0x1B: MBC5+RAM+BATTERY
	 * - 0x1C: MBC5+RUMBLE
	 * - 0x1D: MBC5+RUMBLE+RAM
	 * - 0x1E: MBC5+RUMBLE+RAM+BATTERY
	 * - 0x20: MBC6
	 * - 0x22: MBC7+SENSOR+RUMBLE+RAM+BATTERY
	 * - 0xFC: POCKET CAMERA
	 * - 0xFD: BANDAI TAMA5
	 * - 0xFE: HuC3
	 * - 0xFF: HuC1+RAM+BATTERY
     * - See https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
     */
    uint8_t type;

	/**
	 * @brief Indicates the size of the ROM.
	 * - 0x00: -  32KByte (no ROM banking)
	 * - 0x01: -  64KByte (4 banks)
	 * - 0x02: - 128KByte (8 banks)
	 * - 0x03: - 256KByte (16 banks)
	 * - 0x04: - 512KByte (32 banks)
	 * - 0x05: -   1MByte (64 banks)  - only 63 banks used by MBC1
	 * - 0x06: -   2MByte (128 banks) - only 125 banks used by MBC1
	 * - 0x07: -   4MByte (256 banks)
	 * - 0x08: -   8MByte (512 banks)
	 * - 0x52: - 1.1MByte (72 banks)
	 * - 0x53: - 1.2MByte (80 banks)
	 * - 0x54: - 1.5MByte (96 banks)
	*/
    uint8_t rom_size;
	/**
	 * @brief Indicates the size of the external RAM.
	 * - 0x00: - None
	 * - 0x01: - 2 KBytes
	 * - 0x02: - 8 Kbytes
	 * - 0x03: - 32 KBytes (4 banks of 8KBytes each)
	 * - 0x04: - 128 KBytes (16 banks of 8KBytes each)
	 * - 0x05: - 64 KBytes (8 banks of 8KBytes each)
	 */
    uint8_t ram_size;
	/**
	 * @brief Indicates the destination code of the game.
	 * - 0x00: Japanese
	 * - 0x01: Non-Japanese
	 */
    uint8_t lang;
	/**
	 * @brief Specifies the games company/publisher code in range 00-FFh. 
	 * A value of 33h signalizes that the New License Code in header bytes 0144-0145 is used instead. (Super GameBoy functions won't work if <> $33.) 
	 */
    uint8_t manufacturer_code_extend;
	/**
	 * @brief Specifies the version of the game. Usually 0.
	 */
    uint8_t version;
	/**
	 * @brief Contains a small checksum of the header.
	 */
    uint8_t complement_check;
	/**
	 * @brief Contains a checksum of the ROM. This is however not used by the gameboy.
	 */
    uint8_t checksum[2];
};

/**
 * @brief Contains ROM info.
 */
struct rom_s
{
	struct stat			st; ///< Raw info about the ROM file.
	struct rom_hdr_s*	header; ///< Pointer to the ROM header. @see rom_hdr_s
	void*				ptr; ///< Pointer to the ROM data.
};

/**
 * @brief Wrapper struct used for convenience. I hate C.
 */
struct gbmu_wrapper_s
{
	struct gb_cpu_s* gb;
	struct sdl_context_s* vram_viewer_context;
	struct sdl_context_s* main_context;
};

#ifdef WITH_LIBYACC
/**
 * @brief Struct used by the libyacc debugger.
 * 
 */
struct gbmu_debugger_s
{
	void					*grammar;	///< c++ libyacc DebuggerGrammar instance
	void					*parser;	///< c++ libyacc LRParser instance
	void					*instance;	///< c++ DebuggerContext instance
};
#endif

/**
 * @brief Initializes the gb struct. This should be called after opening a rom but before any other function.
 * This function will call the underlying functions appropriate to the Gameboy type.
 * @note The struct gb_cpu_s* gb should be allocated by the caller.
 * @note The struct gb_cpu_s* gb is zeroed.
 * @param gb 
 * @param rom The rom to load. The rom has to be initialized before with open_rom().
 * @param mode This parameter is used to specify the type of the Gameboy. It can be one of the following:
 * - GB_MODE_DMG: @copydoc gpu_mode_e::GB_MODE_DMG
 * - GB_MODE_CGB: @copydoc gpu_mode_e::GB_MODE_CGB
 * - GB_MODE_GBA: @copydoc gpu_mode_e::GB_MODE_GBA
 * - GB_MODE_AUTO: @copydoc gpu_mode_e::GB_MODE_AUTO
 * - GB_MODE_UNKNOWN: @copydoc gpu_mode_e::GB_MODE_UNKNOWN
 * @return int 0 on success, non-zero on error.
 */
int		init_cpu(struct gb_cpu_s* gb, struct rom_s* rom, enum gb_mode_e mode);

/**
 * @brief Initializes the underlying mbc_s struct. This should not be called directly as it is handled in init_cpu().
 * @param gb 
 * @return int 0 on success, non-zero on error.
 */
int		init_mbc(struct gb_cpu_s* gb);

/**
 * @brief Executes the next instruction currently pointed by the PC register.
 * @note This is NOT equivalent to a step! This is called inside the execute_loop() function.
 * 
 * @param gb 
 * @return int 0 on success, non-zero on error.
 * @warning In case of error, this function will print an error message to stderr and terminate execution.
 */
int		handle_instruction(struct gb_cpu_s* gb);

/**
 * @brief Updates the gb struct. This should be called after each instruction.
 * This sets the gb->current_instruction to the current instruction pointed by the PC register.
 * 
 * @param gb 
 * @return uint8_t The opcode currently pointed by the PC register.
 */
uint8_t	update_current_instruction(struct gb_cpu_s* gb);

/**
 * @brief Fill the opcode table with all the function pointers. This should be called before starting the execution loop.
 */
void	init_op_tab(void);

/**
 * @brief Fill the extended opcode table with all the function pointers. This should be called before starting the execution loop. 
 */
void	init_ext_op_tab(void);

/**
 * @brief Executes one gpu tick. This should be called every step.
 * @param gb 
 */
void	gpu_tick(struct gb_cpu_s* gb);

/**
 * @brief The current execution loop used by the program. This function is not a good piece of code and should be rewritten.
 * 
 * @param wrapper @copydoc struct gbmu_wrapper_s* wrapper
 * @param renderer @copydoc struct gbmu_renderer_s* renderer
 */
void	execute_loop(struct gbmu_wrapper_s* wrapper, void* renderer);

/**
 * @brief Requests an interrupt by writing the corresponding value to the IF register.
 * 
 * @param gb 
 * @param request The interrupt request to set. Can be one of the following:
 * - INT_VBLANK_REQUEST: @copydoc gb_intr_e::INT_VBLANK_REQUEST
 * - INT_STAT_REQUEST: @copydoc gb_intr_e::INT_STAT_REQUEST
 * - INT_TIMER_REQUEST: @copydoc gb_intr_e::INT_TIMER_REQUEST
 * - INT_SERIAL_REQUEST: @copydoc gb_intr_e::INT_SERIAL_REQUEST
 * - INT_JOYPAD_REQUEST: @copydoc gb_intr_e::INT_JOYPAD_REQUEST
 */
void	request_interrupt(struct gb_cpu_s* gb, uint8_t request);

/**
 * // TODO: Better document this function.
 * @brief Updates the timer (#TIMA_OFFSET) and requests an interrupt if needed.
 * 
 * @param gb 
 */
void	update_timer_register(struct gb_cpu_s* gb);

/**
 * @brief Updates the divider register (#DIV_OFFSET).
 * 
 * @param gb 
 */
void	update_div_register(struct gb_cpu_s* gb);

/*
** Memory
*/

/**
 * @brief Read an 8-bit word from the appropriate memory location.
 * This is the safe way to access the gameboy memory. It will check the address range and read from
 * the appropriate memory area.
 * @note Using this functions to read from certain memory areas may not yield the expected result or trigger CPU functions. For example,
 * reading from VRAM will return 0xFF if the PPU is currently rendering.
 * @note To avoid this behavior, use the read_8_force() or read_8_debug() functions.
 * @param gb 
 * @param a16 The address to read from.
 * @return uint8_t The value read from the address.
 */
uint8_t		read_8(struct gb_cpu_s* gb, uint16_t a16);

/**
 * Debugger version of read_8().
 * @see read_8()
 */
uint8_t		read_8_debug(struct gb_cpu_s* gb, uint16_t a16);

/**
 * Generic force version of read_8().
 * @see read_8()
 */
uint8_t		read_8_force(struct gb_cpu_s* gb, uint16_t a16);

/**
 * @brief Read a 16-bit word from the appropriate memory location.
 * This is the safe way to access the gameboy memory. It will check the address range and read from
 * the appropriate memory area.
 * @note Using this functions to read from certain memory areas may not yield the expected result or trigger CPU functions. For example,
 * reading from VRAM will return 0xFF if the PPU is currently rendering.
 * @note To avoid this behavior, use the read_16_force() or read_16_debug() functions.
 * @param gb 
 * @param a16 The address to read from.
 * @return uint16_t The value read from the address.
 */
uint16_t	read_16(struct gb_cpu_s* gb, uint16_t a16);

/**
 * Debugger version of read_16().
 * @see read_16()
 */
uint16_t	read_16_debug(struct gb_cpu_s* gb, uint16_t a16);

/**
 * Generic force version of read_16().
 * @see read_16()
 */
uint16_t	read_16_force(struct gb_cpu_s* gb, uint16_t a16);

/**
 * @brief Write an 8-bit word to the appropriate memory location.
 * This is the safe way to access the gameboy memory. It will check the address range and write to
 * the appropriate memory area.
 * @note Using this functions to write to certain memory areas will trigger specific actions. For example,
 * writing to the OAM will trigger the gpu to update the sprite data.
 * @note To avoid this behavior, use the write_8_force() or write_8_debug() functions.
 * @param gb 
 * @param a16 The address to write to.
 * @param x The byte to write.
 */
void		write_8(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);

/**
 * Debugger version of write_8().
 * @see write_8()
 */
void		write_8_debug(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);

/**
 * Generic force version of write_8().
 * @see write_8()
 */
void		write_8_force(struct gb_cpu_s* gb, uint16_t a16, uint8_t x);

/**
 * @brief Write a 16-bit word to the appropriate memory location.
 * This is the safe way to access the gameboy memory. It will check the address range and write to
 * the appropriate memory area.
 * @note Using this functions to write to certain memory areas will trigger specific actions. For example,
 * writing to the OAM will trigger the gpu to update the sprite data.
 * @note To avoid this behavior, use the write_16_force() or write_16_debug() functions.
 * @param gb 
 * @param a16 The address to write to.
 * @param x The bytes to write.
 */
void		write_16(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);

/**
 * Debugger version of write_16().
 * @see write_16()
 */
void		write_16_debug(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);

/**
 * Generic force version of write_16().
 * @see write_16()
 */
void		write_16_force(struct gb_cpu_s* gb, uint16_t a16, uint16_t x);

uint8_t		read_io(struct gb_cpu_s* gb, uint16_t addr);
void		write_io(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, uint8_t lcdc, enum memory_mode_e mode);


/*
** Debugger
*/
void		execute_debugger(struct gb_cpu_s* gb);

/*
** Debug
*/
void	debug_print_registers(struct registers_s reg);
void	debug_print_gb(struct gb_cpu_s* gb);
void	debug_print_instruction(struct inst_s* inst);
void	debug_print_rom(struct rom_s* rom);
void	debug_print_rom_hdr(struct rom_hdr_s* hdr);
void	debug_print_gb_flags(struct gb_cpu_s* gb);
void	debug_print_stack(struct gb_cpu_s* gb);
void	debug_print_mbc(struct gb_cpu_s* gb);
void	debug_print_flag_register(uint8_t reg);

/*
** Misc
*/
void    cpu_toggle_flag(struct gb_cpu_s* gb, uint8_t flag, int cond);
void    cpu_set_flag(struct gb_cpu_s* gb, uint8_t flag);
void    cpu_unset_flag(struct gb_cpu_s* gb, uint8_t flag);

/**
 * @brief Write c n times to ptr.
 */
void	memset_4(uint32_t* ptr, uint32_t c, size_t n);

/**
 * @brief Transfer data from memory to OAM with a fixed length.
 * This function is available on both CGB and DMG.
 * @param gb 
 * @param a8 The address to start the transfer.
 */
void	process_dma_transfer(struct gb_cpu_s* gb, uint8_t a8);
/**
 * @brief Transfer data from memory to VRAM with an arbitrary length.
 * This function is only available on CGB.
 * 
 * @param gb 
 * @param a8 The first bit of a8 indicates the transfer mode (0: General, 1: H-Blank). The lower 7 bits of a8 are the length of the transfer.
 * In case of General transfer, the data is transferred immediately. In case of H-Blank transfer, 0x10 bytes are transferred each time the H-Blank interrupt is triggered.
 */
void	initiate_hdma_transfer(struct gb_cpu_s* gb, uint8_t a8);
int		clamp(int val, int min, int max);
void	fatal(struct gb_cpu_s* gb);
int		get_debugger_verbose(struct gb_cpu_s* gb);
int		open_rom(char* name, struct rom_s* rom);

/*
** Saving & Loading
*/

/**
 * @brief Attempts to save the game.
 * This is done by saving the current RAM to disk.
 * The file is saved to "./saves/<name>.sav" where <name> is the name of the ROM.
 * @return int 0 if the save was successful, non-zero otherwise.
 */
int		save_game(struct gb_cpu_s* gb);

/**
 * @brief Attempts to load a save file for the current game.
 * This function looks for a file named "./saves/<name>.sav" where <name> is the name of the ROM.
 * In case the file is found but the content is not what is expected, a warning is emitted but the data is still loaded.
 * @return int 0 if the load was successful, non-zero otherwise.
 */
int		load_game(struct gb_cpu_s* gb);

/**
 * @brief Same as save_game(), except it saves the game to "./saves/<name>_CRASH.sav".
 * 
 * @param gb 
 * @return int 
 */
int		save_game_crash(struct gb_cpu_s* gb);

/**
 * @brief Save the current GameBoy state to a file.
 * This is a very straight forward function: it simply saves the gb_cpu_s structure to a file.
 * The file is saved to "./savestates/<name>_<slot>.ss" where <name> is the name of the ROM and <slot> is the slot number.
 * @return int 0 if the save was successful, non-zero otherwise.
 */
int		savestate(struct gb_cpu_s* gb, int number);

/**
 * @brief Load a savestate from a file.
 * This function simply reads the file into the gb_cpu_s structure.
 * @return int 0 if something was loaded, non-zero otherwise.
 */
int		loadstate(struct gb_cpu_s* gb, int number);


#ifdef __cplusplus
}
#endif
#endif