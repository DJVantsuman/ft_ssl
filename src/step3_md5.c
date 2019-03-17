#include "../inc/md5.h"

unsigned int    *step3_md5(unsigned char *msg, t_variables *var)
{
    unsigned int *X;

    var->A = 0x67452301;
    var->B = 0xefcdab89;
    var->C = 0x98badcfe;
    var->D = 0x10325476;
    for (int i = 0; i < 64; i++)
        var->T[i] = (unsigned int)(pow(2, 32) * fabs(sin(i + 1)));
     X = (unsigned int *)(msg);
     free(msg);
    return X;
}
