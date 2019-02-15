#include "../inc/md5.h"

unsigned int    *step3_md5(unsigned char *msg, t_variables *var)
{
    unsigned int *X;

    X = (unsigned int *)malloc(size / 4);
    for (int i = 0; i < 64; i++)
        var->T[i] = (unsigned int)(pow(2, 32) * fabs(sin(i + 1)));
     X = (unsigned int *)(msg);
    return X;
}
