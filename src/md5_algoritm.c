/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5Algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:45:26 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:45:29 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

unsigned int	f(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) | ((~x) & z));
}

unsigned int	g(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & z) | (y & (~z)));
}

unsigned int	h(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int	i(unsigned int x, unsigned int y, unsigned int z)
{
	return (y ^ (x | (~z)));
}

unsigned int	rotate_left(unsigned int value, int shift)
{
	return (value << shift | value >> (32 - shift));
}
