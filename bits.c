#include <stdio.h>
#include "bits.h"

uint32_t set_bit(uint32_t n, unsigned pos)
{
	
	return(n |= (1u << pos));
}

uint32_t clear_bit(uint32_t n, unsigned pos)
{
	return(n & ~(1u << pos));
}

uint32_t toggle_bit(uint32_t n, unsigned pos)
{
	return(n ^= (1u << pos));
}

int      get_bit(uint32_t n, unsigned pos)
{
	return((n >> pos) & 1);
}
uint32_t write_bit(uint32_t n, unsigned pos, int value)
{
	if(value)
		return(n |= (1u << pos));
	
	return(~(1u << pos) & n);
}
int      popcount(uint32_t n)
{
	int count = 0;
	while(n)
	{
		if((n & 1) == 1)
			count++;
    n = (n >> 1);
	}
	return(count);
}
int      is_power_of_two(uint32_t n)
{
	if(n == 0)
		return(0);
	return(((n - 1) & n) == 0);
}
uint32_t lowest_set_bit(uint32_t n)
{
	uint32_t r = 1;
	while(n)
	{
		if((n & 1) == 0)
			r = (r << 1);
		else
			return(r);

		n = (n >> 1);
	}
	return(0);
}
int	highest_set_bit_pos(uint32_t n)
{
	if(n == 0)
		return(-1);
	int pos = 0;
	int i = 0;
	while(n)
	{
		if((n & 1) == 1)
			pos = i;
		n = (n >> 1);
		i++;
	}
	return(pos);
}
int      parity(uint32_t n)
{
	int results = 0;
	while(n)
	{
		results ^= (n & 1);
    	n = (n >> 1);
	}
	return(results);
}
uint32_t reverse_bits(uint32_t n)
{
	uint32_t res = 0; 
    uint32_t i = 32;
	while(i > 0)
	{
		res = (res << 1)| (n & 1);
		n >>= 1;
		i--;
	}
	return(res);
}
uint32_t rotate_left(uint32_t n, unsigned k)
{
	if(!(k % 32))
		return(n);
	while(k--)
	{
		uint32_t r;
		r = (n >> 31);
		n = (n << 1) | r;
	}
	return(n);
}
uint32_t rotate_right(uint32_t n, unsigned k)
{
	if(!(k % 32))
		return(n);

	while(k--)
	{
		uint32_t r = n;
		n = (n >> 1) | (r << 31);
	}
	return(n);
}
uint32_t swap_bytes(uint32_t n)
{
	return ((n >> 24 & 0x000000ff) |
			(n >> 8 & 0x0000ff00) |
			(n << 8 & 0x00ff0000) |
			(n << 24 & 0xff000000));
}
uint32_t swap_bits(uint32_t n, unsigned i, unsigned j)
{
	unsigned bit_i = (n >> i) & 1;
	unsigned bit_j = (n >> j) & 1;
	
	if(bit_i != bit_j)
	{
		n ^= (1u << j);
		n ^= (1u << i);
	}
	return(n);
}
uint32_t make_mask(unsigned len)
{
	if(!len)
		return(0);

	if(len >= 32)
		return(UINT32_MAX);
	return((1u << len) -1);
}
uint32_t extract_bits(uint32_t n, unsigned start, unsigned len)
{
	if (len == 0 || start >= 32 || len > 32 - start)
		return (0);

    if (len == 32)
        return (n);

	uint32_t musk = (1U << len) - 1;

	return((n >> start) & musk);
}
uint32_t insert_bits(uint32_t n, uint32_t val, unsigned start, unsigned len)
{
	if (len == 0 || start >= 32 || len > 32 - start)
		return (n);

	uint32_t mask;

	if (len == 32)
		mask = UINT32_MAX;
	else
		mask = (1U << len) - 1;

	n &= ~(mask << start);
	n |= (val & mask) << start;

	return (n);
}

void print_bits(uint32_t n)
{
	for(int i = 31; i >= 0; i--)
	{
		printf("%d", (n >> i) & 1);
	}
}
void dump_memory(const void *p, size_t size)
{
    const unsigned char *C = (const unsigned char *)p;
    char hex[] = "0123456789abcdef";
	for(size_t i = 0; i < size; i++)
	{
		unsigned char byte = *(C + i);
	
		printf("%c%c",hex [byte / 16], hex[byte % 16]);
		if(i < size - 1)
			printf(" ");
	}
    printf("\n");
}