/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:41:42 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 22:48:53 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

void	printUsage(void)
{
	if (type == HASH_MD_5)
		ft_printf("%s\n", "usage: md5 [-pqr] [-s string] [files ...]");
	else if (type == HASH_SHA256)
		ft_printf("%s\n", "usage: sha256 [-pqr] [-s string] [files ...]");
	exit(0);
}

int		readFromFile(char *fileName, t_container **var)
{
	char	*str;
	char	*tmp;
	char	buffer[101];
	int		i;
	int		fd;

	str = NULL;
	fd = open(fileName, O_RDONLY);
	if (fd > 0)
	{
		while ((i = read(fd, &buffer, 100)) > 0)
		{
			tmp = str;
			buffer[i] = '\0';
			if (tmp == NULL)
				str = ft_strdup(buffer);
			else
				str = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
		(*var)->message = str;
	}
	else
		return (-1);
	return (1);
}

char	*readFromConsole(void)
{
	char	buffer[101];
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	while ((i = read(0, &buffer, 100)) > 0)
	{
		tmp = str;
		buffer[i] = '\0';
		if (tmp == NULL)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	return (str);
}

int		getMessages(t_container **container)
{
	t_container *var;
	int			f;

	var = *container;
	f = 0;
	while (var)
	{
		if (var->flag == 'p' && f == 0)
		{
			f++;
			var->message = readFromConsole();
			ft_printf("%s", var->message);
		}
		else if (var->flag == 'f')
		{
			if (readFromFile(var->fileName, &var) < 0)
				var->error = 1;
		}
		else if (f > 0 && var->flag == 'p')
			var->message = "";
		if (var->message)
			var->message_len = ft_strlen(var->message);
		var = var->next;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_container *container;
	t_container *var;

	container = NULL;
	var = newLst(NULL);
	if (argc == 1)
		printUsage();
	getCommand(argv[1]);
	if (argc == 2)
	{
		var->flag = 'p';
		addLst(&container, var);
	}
	else if (argc > 2)
		checkArguments(argc, argv, &container);
	getMessages(&container);
	if (type == HASH_MD_5)
		calculateMd5(&container);
	else if (type == HASH_SHA256)
		calculateSHA256(&container);
	system("leaks -q ft_ssl");
	return (0);
}
