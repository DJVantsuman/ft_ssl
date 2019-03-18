/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256Algoritm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:44:07 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:44:09 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sha256.h"

unsigned int	rotate(unsigned int value, int shift)
{
    return (value >> shift) | (value << (32 - shift));
}

unsigned int	shr(unsigned int x, int n)
{
    return (x >> n);
}

unsigned int	ch(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ ((~x) & z);
}

unsigned int	maj(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}
