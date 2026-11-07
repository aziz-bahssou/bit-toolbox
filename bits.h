#ifndef BITS_H
# define BITS_H

# include <stdint.h>
# include <stddef.h>

//single bits 
uint32_t	set_bit(uint32_t n, unsigned pos);
uint32_t	clear_bit(uint32_t n, unsigned pos);
uint32_t	toggle_bit(uint32_t n, unsigned pos);
int			get_bit(uint32_t n, unsigned pos);
uint32_t	write_bit(uint32_t n, unsigned pos, int value);

//queries
int			popcount(uint32_t n);
int			is_power_of_two(uint32_t n);
uint32_t	lowest_set_bit(uint32_t n);
int			highest_set_bit_pos(uint32_t n);
int			parity(uint32_t n);

//transformations
uint32_t	reverse_bits(uint32_t n);
uint32_t	rotate_left(uint32_t n, unsigned k);
uint32_t	rotate_right(uint32_t n, unsigned k);
uint32_t	swap_bytes(uint32_t n);
uint32_t	swap_bits(uint32_t n, unsigned i, unsigned j);

//fields and masks
uint32_t	make_mask(unsigned len);
uint32_t	extract_bits(uint32_t n, unsigned start, unsigned len);
uint32_t	insert_bits(uint32_t n, uint32_t val, unsigned start, unsigned len);

//visibility
void		print_bits(uint32_t n);
void		dump_memory(const void *p, size_t size);


#endif