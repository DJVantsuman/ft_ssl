#include "../inc/md5.h"

size_t  getSize(t_container *container)
{

    size_t rest;

    size = 0;
    rest = container->message_len % 64;
    if(rest < 56)
        size = container->message_len - rest + 56 + 8;
    else
        size = container->message_len + 64 - rest + 56 + 8;
    return size;
}

void    fillMsg(unsigned char *msg, t_container *var)
{
    for(size_t i = 0; i < var->message_len; i++)
        msg[i] = (unsigned char)var->message[i];
    msg[var->message_len] = 0x80;
    for(size_t i = var->message_len + 1; i < size; i++)
        msg[i] = 0;
}

unsigned char    *step1_md5(t_container *var)
{
    unsigned char   *msg;

    size = getSize(var);
    msg = (unsigned char *)malloc(size +1);
    if(!msg)
    {
        printf("Error in step #1");
        exit(1);
    }
    fillMsg(msg, var);
    return msg;
}
