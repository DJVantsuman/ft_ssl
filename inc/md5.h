/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:42:50 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/19 22:50:16 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MD5_H
# define _MD5_H

# include "../inc/ssl.h"

unsigned int	f(unsigned int x, unsigned int y, unsigned int z);
unsigned int	g(unsigned int x, unsigned int y, unsigned int z);
unsigned int	h(unsigned int x, unsigned int y, unsigned int z);
unsigned int	i(unsigned int x, unsigned int y, unsigned int z);
unsigned int	rotate_left(unsigned int value, int shift);
unsigned char	*step1_md5(t_container *container);
unsigned char	*step2_md5(unsigned char *msg, t_container *var);
unsigned int	*step3_md5(unsigned char *msg, t_variables *var);
void			step4_md5(unsigned int *x, t_variables *var, size_t i,
		size_t j);
void			raund1_1(unsigned int *x, t_variables *var);
void			raund2_1(unsigned int *x, t_variables *var);
void			raund3_1(unsigned int *x, t_variables *var);
void			raund4_1(unsigned int *x, t_variables *var);
void			check_flags(t_container **container, int is_revers,
		int is_quiet);

#endif
