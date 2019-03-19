/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:45:10 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:45:13 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

void		add_lst(t_container **alst, t_container *new_lst)
{
	t_container	*list;

	if (*alst == NULL)
		*alst = new_lst;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new_lst;
	}
}

t_container	*new_lst(char *content)
{
	t_container	*list;

	list = (t_container *)malloc(sizeof(t_container));
	if (!list)
		return (NULL);
	if (content)
		list->message = content;
	else
		list->message = NULL;
	list->file_name = 0;
	list->message_len = 0;
	list->is_valid = 0;
	list->is_quiet = 0;
	list->is_revers = 0;
	list->next = NULL;
	return (list);
}

void		get_command(char *command)
{
	if (!ft_strcmp(command, "md5"))
		g_type = HASH_MD_5;
	else if (!ft_strcmp(command, "sha256"))
		g_type = HASH_SHA256;
	else
		g_type = UNDEFINED;
	if (g_type == UNDEFINED)
	{
		ft_printf("Error: wrong command\n");
		exit(1);
	}
}

int			get_flags(char **av, t_container **container, int i, int ac)
{
	t_container	*var;

	while (*(++av[i]))
	{
		var = new_lst(NULL);
		var->flag = *av[i];
		if (*av[i] == 's')
		{
			if (av[i][1])
				var->message = ft_strdup(++av[i]);
			else if (i + 1 < ac)
				var->message = ft_strdup(av[++i]);
			else
				var->is_valid = 0;
			if (var->message)
				var->message_len = ft_strlen(var->message);
			add_lst(container, var);
			break ;
		}
		add_lst(container, var);
	}
	return (i);
}

void		check_arguments(int ac, char **av, t_container **container)
{
	t_container	*var;
	int			i;
	int			f;

	i = 1;
	f = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && f == 0)
			i = get_flags(av, container, i, ac);
		else
		{
			f++;
			var = new_lst(NULL);
			var->flag = 'f';
			var->file_name = ft_strdup(av[i]);
			var->is_valid = 1;
			add_lst(container, var);
		}
	}
}
