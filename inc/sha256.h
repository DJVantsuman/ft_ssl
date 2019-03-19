/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:50:55 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/19 22:51:24 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHA256_H
# define _SHA256_H

# include "../inc/ssl.h"

unsigned int	rotate(unsigned int value, int shift);
unsigned int	shr(unsigned int x, int n);
unsigned int	ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int	maj(unsigned int x, unsigned int y, unsigned int z);
unsigned int	sigma0(unsigned int x);
unsigned int	sigma1(unsigned int x);
unsigned int	delta0(unsigned int x);
unsigned int	delta1(unsigned int x);
void			main_loop_sha256(unsigned int *x, t_variables *var);

#endif
