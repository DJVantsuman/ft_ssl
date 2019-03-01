#include "../inc/sha256.h"

unsigned int	sigma0(unsigned int x)
{
    return (rotate(x, 2) ^ rotate(x, 13) ^ rotate(x, 22));
}

unsigned int	sigma1(unsigned int x)
{
    return (rotate(x, 6) ^ rotate(x, 11) ^ rotate(x, 25));
}

unsigned int	delta0(unsigned int x)
{
    return (rotate(x, 7) ^ rotate(x, 18) ^ shr(x, 3));
}

unsigned int	delta1(unsigned int x)
{
    return (rotate(x, 17) ^ rotate(x, 19) ^ shr(x, 10));
}
