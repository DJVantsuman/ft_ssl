#ifndef _SSL_H
# define _SSL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef  struct s_container
{
    char                flag;
    char                *message;
    size_t              message_len;
    struct container    *next;
}               t_container;

typedef enum    e_type
{
    UNDEFINED,
    HASH_MD_5,
    HASH_SHA256
}               t_type;

t_type  type;

void	checkArguments(int ac, char **av, t_container *container);
void    getCommand(char *command);

#endif