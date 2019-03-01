#ifndef _SHA256_H
# define _SHA256_H

# include "../inc/ssl.h"

unsigned int    rotate(unsigned int value, int shift);
unsigned int	shr(unsigned int x, int n);
unsigned int	ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int	maj(unsigned int x, unsigned int y, unsigned int z);
unsigned int	sigma0(unsigned int x);
unsigned int	sigma1(unsigned int x);
unsigned int	delta0(unsigned int x);
unsigned int	delta1(unsigned int x);
void            mainLoopSha256(unsigned int *X, t_variables *var);

#endif
