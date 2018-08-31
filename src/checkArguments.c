#include "../inc/ssl.h"

void    getCommand(char *command)
{
    if(!ft_strcmp(command, "md5"))
        type = HASH_MD_5;
    else if(!ft_strcmp(command, "sha256"))
        type = HASH_SHA256;
    else
        type = UNDEFINED;
}

void    getFlags(char *str, t_container *container)
{
    while (*str)
    {
        if(*str == 'p' || *str == 'q' || *str == 'r')
            container->flag = *strl;
        else if(*str == '-')
            continue ;
        else if(*str == 's')
        {

        }
        else
            exit(10);
//            printf("%s  %c\n", "Hello World", *str);
        str++;
    }
    container = 0;
}

void	checkArguments(int ac, char **av, t_container *container)
{
    int i;

    getCommand(av[1]);
    i = 1;
    while (++i < ac)
    {
        if(av[i][0] == '-')
            getFlags(av[i], container);
    }


    container = 0;
//    printf("%s\n", "Hello World");
}