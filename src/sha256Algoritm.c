#include "../inc/sha256.h"


unsigned int	rotate(unsigned int value, int shift)
{
    return (value >> shift) | (value << (32 - shift));
}

unsigned int	shr(unsigned int x, int n)
{
    return (x >> n);
}

unsigned int	ch(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ ((~x) & z);
}

unsigned int	maj(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}
