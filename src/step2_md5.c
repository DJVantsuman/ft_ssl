/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:44:20 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:44:27 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

unsigned char	*step2_md5(unsigned char *msg, t_container *var)
{
	size_t	length_bit;
	size_t	i;

	length_bit = var->message_len * 8;
	i = 0;
	while (i < 4)
	{
		msg[g_size - 8 + i] = (unsigned char)(length_bit >> i * 8);
		i++;
	}
	return (msg);
}
