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

unsigned char *step2_md5(unsigned char *msg, t_container *var)
{
	size_t length_bit;


	length_bit = var->message_len * 8;

	for (size_t i = 0; i < 4; i ++)
	{
		msg[size - 8 + i] = (unsigned char)(length_bit >> i * 8);
	}
	return msg;
}
