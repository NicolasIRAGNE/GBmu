/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 10:37:00 by niragne           #+#    #+#             */
/*   Updated: 2020/05/09 12:32:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBC_H
# define MBC_H
# include <stdint.h>

# define BUILT_IN_RAM_SIZE 0x200 // built in ram inside MBC2 chip

struct	gb_cpu_s;

enum	mbc_mode_e
{
	MBC_MODE_ROM,
	MBC_MODE_RAM,
	MBC_MODE_RTC
};

struct	mbc_s
{
	char*			name;
	enum mbc_mode_e	mode;
	uint8_t			(*read)(struct gb_cpu_s*, uint16_t);	
	void			(*write)(struct gb_cpu_s*, uint16_t, uint8_t);
	uint16_t		bank;
	uint16_t		ram_bank;
	uint8_t			rtc;
	uint32_t		rom_size;
	uint32_t		ram_size;
};

struct mbc_s get_mbc(int index);

void write_no_mbc(struct gb_cpu_s* gb, uint16_t addr, uint8_t x);
uint8_t	read_no_mbc(struct gb_cpu_s* gb, uint16_t addr);

void	write_mbc1(struct gb_cpu_s* gb, uint16_t addr, uint8_t x);
uint8_t	read_mbc1(struct gb_cpu_s* gb, uint16_t addr);

void	write_mbc2(struct gb_cpu_s* gb, uint16_t addr, uint8_t x);
uint8_t	read_mbc2(struct gb_cpu_s* gb, uint16_t addr);

void	write_mbc3(struct gb_cpu_s* gb, uint16_t addr, uint8_t x);
uint8_t	read_mbc3(struct gb_cpu_s* gb, uint16_t addr);

void	write_mbc5(struct gb_cpu_s* gb, uint16_t addr, uint8_t x);
uint8_t	read_mbc5(struct gb_cpu_s* gb, uint16_t addr);

#endif