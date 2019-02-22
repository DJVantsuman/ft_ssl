#ifndef _SSL_H
# define _SSL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

typedef  struct s_container
{
    char                flag;
    char                *message;
    char                *fileName;
    size_t              message_len;
    int                 isValid;
    int                 isRevers;
    int                 isQuiet;

    struct s_container  *next;
}                       t_container;

typedef     struct s_variables
{
    unsigned int    A;
    unsigned int    B;
    unsigned int    C;
    unsigned int    D;
    unsigned int    h0;
    unsigned int    h1;
    unsigned int    h2;
    unsigned int    h3;
    unsigned int    h4;
    unsigned int    h5;
    unsigned int    h6;
    unsigned int    h7;
    unsigned int    T[64];
}                   t_variables;

typedef enum    e_type
{
                UNDEFINED,
                HASH_MD_5,
                HASH_SHA256
}               t_type;

t_type  type;
char    *fileName;
size_t  size;

void            print_output(t_variables *var, t_container *container);
void            calculateMd5(t_container **container);
void            calculateSHA256(t_container **container);
void            checkArguments(int ac, char **av, t_container **container);
void            getCommand(char *command);
void            addLst(t_container **alst, t_container *newLst);
t_container		*newLst(char *content);

unsigned int    rev_bit(unsigned int var);


#endif
