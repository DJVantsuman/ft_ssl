#include "../inc/md5.h"

unsigned int    F(unsigned int X, unsigned int Y, unsigned int Z)
{
    return ((X & Y) | ((~X) & Z));
}

unsigned int    G(unsigned int X, unsigned int Y, unsigned int Z)
{
    return (X & Z) | (Y & (~Z));
}

unsigned int    H(unsigned int X, unsigned int Y, unsigned int Z)
{
    return X ^ Y ^ Z;
}

unsigned int    I(unsigned int X, unsigned int Y, unsigned int Z)
{
    return Y ^ (X | (~Z));
}

unsigned int    rotate_left(unsigned int value, int shift)
{
    return value << shift | value >> (32-shift);
}
