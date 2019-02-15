#ifndef _MD5_H
# define _MD5_H

# include "../inc/ssl.h"

typedef     struct s_variables
{
    unsigned int    A;
    unsigned int    B;
    unsigned int    C;
    unsigned int    D;
    unsigned int    T[64];
}                   t_variables;

unsigned int    F(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    G(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    H(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    I(unsigned int X, unsigned int Y, unsigned int Z);

unsigned int    rotate_left(unsigned int value, int shift);
void            print_hex(t_variables *var);

unsigned char   *step1_md5(t_container *container);
unsigned char   *step2_md5(unsigned char *msg, t_container *var);
unsigned int    *step3_md5(unsigned char *msg, t_variables *var);
void            step4_md5(unsigned int *X, t_variables *var);

#endif
