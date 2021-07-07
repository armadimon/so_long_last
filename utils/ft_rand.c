#include "etc.h"

unsigned short	ft_rand(void)
{
	static unsigned short	lfsr = 0x02;
	static unsigned int		bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 1)) & 1;
	return (lfsr = (lfsr >> 1) | (bit << 3));
}
