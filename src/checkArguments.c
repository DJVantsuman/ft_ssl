#include "../inc/ssl.h"


void	addLst(t_container **alst, t_container *newLst)
{
    t_container	*list;

    if (*alst == NULL)
        *alst = newLst;
    else
    {
        list = *alst;
        while (list->next)
            list = list->next;
        list->next = newLst;
    }
}

t_container		*newLst(char *content)
{
    t_container	*list;

    list = (t_container *)malloc(sizeof(t_container));
    if (!list)
        return (NULL);
    if (content)
        list->message = content;
    else
        list->message = NULL;
    list->fileName = 0;
    list->message_len = 0;
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
    while (*(++av[i]))
    {
        t_container *var;

        var = newLst(NULL);
        var->flag = *av[i];
        if (*av[i] == 's')
        {
            if (av[i][1])
                var->message = ft_strdup(++av[i]);
            else if (i + 1 < ac)
                var->message = ft_strdup(av[++i]);
            else
                var->isValid = 0;
            if (var->message)
                var->message_len = ft_strlen(var->message);
            addLst(container, var);
            break ;
        }
        addLst(container, var);
    }
    return i;
}

void	checkArguments(int ac, char **av, t_container **container)
{
    int i;
    int f;

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
            var->fileName = ft_strdup(av[i]);
            addLst(container, var);
            f = 1;
        }
    }
}
