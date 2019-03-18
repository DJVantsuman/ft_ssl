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

unsigned int    F(unsigned int X, unsigned int Y, unsigned int Z)
{
    return ((X & Y) | ((~X) & Z));
}

unsigned int    G(unsigned int X, unsigned int Y, unsigned int Z)
{
    return (X & Z) | (Y & (~Z));
}

unsigned int    H(unsigned int X, unsigned int Y, unsigned int Z)
{
    return X ^ Y ^ Z;
}

unsigned int    I(unsigned int X, unsigned int Y, unsigned int Z)
{
    return Y ^ (X | (~Z));
}

unsigned int    rotate_left(unsigned int value, int shift)
{
    return value << shift | value >> (32-shift);
}
