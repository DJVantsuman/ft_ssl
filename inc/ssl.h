#ifndef _SSL_H
# define _SSL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef  struct s_container
{
    char                flag;
    char                *message;
    char                *fileName;
    size_t              message_len;
    int                 isValid;
    struct s_container  *next;
}                       t_container;

typedef enum    e_type
{
                UNDEFINED,
                HASH_MD_5,
                HASH_SHA256
}               t_type;

t_type  type;
char    *fileName;

void            calculateMd5(t_container **container);
void            step1(t_container *container);
void            checkArguments(int ac, char **av, t_container **container);
void            getCommand(char *command);
void            addLst(t_container **alst, t_container *newLst);
t_container		*newLst(char *content);


#endif
