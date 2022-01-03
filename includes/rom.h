/**
 * @file rom.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief Contains definitions regarding cartridges.
 * @date 2022-01-03
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once

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

int		open_rom(char* name, struct rom_s* rom);
