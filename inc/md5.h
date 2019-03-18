#ifndef _MD5_H
# define _MD5_H

# include "../inc/ssl.h"

unsigned int    F(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    G(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    H(unsigned int X, unsigned int Y, unsigned int Z);
unsigned int    I(unsigned int X, unsigned int Y, unsigned int Z);

unsigned int    rotate_left(unsigned int value, int shift);
unsigned char   *step1_md5(t_container *container);
unsigned char   *step2_md5(unsigned char *msg, t_container *var);
unsigned int    *step3_md5(unsigned char *msg, t_variables *var);
void            step4_md5(unsigned int *X, t_variables *var);
void            raund1_1(unsigned int *X, t_variables *var);
void            raund2_1(unsigned int *X, t_variables *var);
void            raund3_1(unsigned int *X, t_variables *var);
void            raund4_1(unsigned int *X, t_variables *var);

void            checkFlags(t_container **container, int isRevers, int isQuiet);

#endif
