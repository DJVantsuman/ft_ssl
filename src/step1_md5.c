/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:42:30 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:42:36 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

size_t			get_size(t_container *container)
{
	size_t	rest;

	g_size = 0;
	rest = container->message_len % 64;
	if (rest < 56)
		g_size = container->message_len - rest + 56 + 8;
	else
		g_size = container->message_len + 64 - rest + 56 + 8;
	return (g_size);
}

void			fill_msg(unsigned char *msg, t_container *var)
{
	size_t	i;

	i = 0;
	while (i < var->message_len)
	{
		msg[i] = (unsigned char)var->message[i];
		i++;
	}
	msg[var->message_len] = 0x80;
	i = var->message_len + 1;
	while (i < g_size)
	{
		msg[i] = 0;
		i++;
	}
}

unsigned char	*step1_md5(t_container *var)
{
	unsigned char	*msg;

	g_size = get_size(var);
	msg = (unsigned char *)malloc(g_size + 1);
	if (!msg)
	{
		ft_printf("Error in step #1");
		exit(1);
	}
	fill_msg(msg, var);
	return (msg);
}
