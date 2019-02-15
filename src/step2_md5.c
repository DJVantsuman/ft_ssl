#include "../inc/md5.h"

unsigned char *step2_md5(unsigned char *msg, t_container *var)
{
    size_t length_bit;

    length_bit = var->message_len * 8;

    for (size_t i = 0; i < 4; i ++)
    {
        msg[size - 8 + i] = (unsigned char)(length_bit >> i * 8);
    }
    return msg;
}
