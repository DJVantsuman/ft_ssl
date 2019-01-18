#include "../inc/ssl.h"


size_t  step1_size(t_container *container)
{
    size_t size;
    size_t rest;

    size = 0;
    rest = container->message_len % 64;
    if(rest < 56)
        size = container->message_len - rest + 56 + 8;
    else
        size = container->message_len - rest + 56 + 8;
    return size;
}

void    fillMsg()
{

}

void    step1(t_container *var)
{
    size_t          lenght;
    unsigned char   *msg;

    lenght = step1_size(var);
    msg = (unsigned char *)malloc(lenght +1);
    if(!msg)
    {
        printf("Error in step1");
        exit(1);
    }
}
