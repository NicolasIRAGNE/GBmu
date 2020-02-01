#ifndef GB_H
# define GB_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <stdint.h>

struct rom_hdr_s
{
	char	entry[4];
	char	logo[48];
	char	title[11];
};

struct rom_s
{
	struct rom_hdr_s*	header;
	void*				ptr;	
};

#endif