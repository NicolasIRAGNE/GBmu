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
# include "ext_op.h"
# include <limits.h>
# include "mbc.h"
# include <stdio.h>
# include "memory.h"
# include "rom.h"
# include "mode.h"

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

void    init_registers(struct registers_s* reg, int booted, enum gb_mode_e mode);
int		init_cpu_dmg(struct gb_cpu_s* gb, struct rom_s* rom);
int		init_cpu_cgb(struct gb_cpu_s* gb, struct rom_s* rom);
void	signal_handler(int signal);

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
 * @brief Debugger version of read_8().
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
 * @param a8 The lower 7 bits of a8 are the length of the transfer.
 * In case of General transfer, the data is transferred immediately. In case of H-Blank transfer, 0x10 bytes are transferred each time the H-Blank interrupt is triggered.
 * @param mode 0 for general transfer, 1 for H-Blank transfer.
 * @note Starting a general transfer will interrupt any ongoing H-Blank transfer.
 */
void	initiate_hdma_transfer(struct gb_cpu_s* gb, uint8_t a8, uint8_t mode);

/**
 * @brief Process the next 0x10 bytes of the ongoing HDMA transfer. This function should be called on HBLANK only.
 *
 * @param gb
 */
void    resume_hdma_transfer(struct gb_cpu_s* gb);

int		clamp(int val, int min, int max);
void	fatal(struct gb_cpu_s* gb);
int		get_debugger_verbose(struct gb_cpu_s* gb);

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
 * In case the file is found but the content is not what is expected, a warning is emitted but the data is still loaded. 
 * @return int 0 if the load was successful, non-zero otherwise.
 */
int		load_game_from_file(struct gb_cpu_s* gb, const char* save_file);

/**
 * @brief This function attempts to load the following save file: "./saves/<name>.sav" where <name> is the name of the ROM.
 * @copydoc load_game_from_file
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

/**
 * @brief Copies the current cpu registers to dst.
 *
 */
void	copy_registers(void* dst);

/**
 * @brief One full step of the CPU.
 * @return 1 if a frame is ready to be drawn, 0 otherwise, or a negative value if an error occurred.
 */
int		cpu_step();

/**
 * @brief Get the user data directory.
 * On Windows, this equals to C:\\Users\\<username>\\AppData\\GBmu.
 * On Linux, this equals to $HOME/.gbmu.
 * @return char* A newly allocated string containing the path.
 */
char*	get_user_data_dir(void);

#ifdef __cplusplus
}
#endif
#endif
