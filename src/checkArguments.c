#include "../inc/ssl.h"


void	addLst(t_container **alst, t_container *new)
{
    t_container	*list;

    if (*alst == NULL)
        *alst = new;
    else
    {
        list = *alst;
        while (list->next)
            list = list->next;
        list->next = new;
    }
}

t_container		*newLst(void const *content)
{
    t_container	*list;

    list = (t_container *)malloc(sizeof(t_container));
    if (!list)
        return (NULL);
    if (content)
        list->message = content;
    else
        list->message = NULL;
    list->next = NULL;
    return (list);
}

void    getCommand(char *command)
{
    if(!ft_strcmp(command, "md5"))
        type = HASH_MD_5;
    else if(!ft_strcmp(command, "sha256"))
        type = HASH_SHA256;
    else
        type = UNDEFINED;
}

int    getFlags(char **av, t_container **container, int i, int ac)
{
    while (++av[i])
    {
        t_container *var;
        var= newLst(NULL);
        if(*av[i] == 'p' || *av[i] == 'q' || *av[i] == 'r')
            var->flag = *av[i];
        else if(*av[i] == 's')
        {
            var->flag = *av[i];
            if(av[i][1])
                var->message = ++av[i];
            else if(i + 1 < ac)
                var->message = av[++i];
            else
                return (-2);
            addLst(container, var);
            return  i;
        }
        else
            return (-1);
        addLst(container, var);
    }
    return i;
}

void    print(t_container **container)
{
    if ((*container)->next) {
        printf("Flag = %c; Message = %s\n", (*container)->flag, (*container)->message);
        print((*container)->next);
    }
}

void	checkArguments(int ac, char **av, t_container **container)
{
    int i;
    int f;

    getCommand(av[1]);
    i = 1;
    f = 0;
    while (++i < ac)
    {
        if(av[i][0] == '-' && f == 0)
            i = getFlags(av, container, i, ac);
        else
        {
            t_container *var;
            var = newLst(NULL);
            var->flag = 'f';
            var->message = av[i];
            addLst(container, var);
            f = 1;
        }
    }
    print(container);
}