/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mod_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:44:29 by itsuman           #+#    #+#             */
/*   Updated: 2017/02/24 16:50:26 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_size(char size, int pr, t_strf *f)
{
	f->mod_size = size;
	f->pr = pr;
}

void	check_mod_size(const char *format, t_strf *f)
{
	int	i;

	i = 0;
	while (is_spesify(format[i]))
	{
		if (format[i] == 'z' && f->pr < 6)
			take_size('z', 6, f);
		else if (format[i] == 'j' && f->pr < 5)
			take_size('j', 5, f);
		else if (format[i] == 'l' && format[i + 1] == 'l' && f->pr < 4)
		{
			take_size('l', 4, f);
			i++;
		}
		else if (format[i] == 'l' && f->pr < 3)
			take_size('l', 3, f);
		else if (format[i] == 'h' && format[i + 1] == 'h' && f->pr < 1)
		{
			take_size('h', 1, f);
			i++;
		}
		else if (format[i] == 'h' && f->pr < 2)
			take_size('h', 2, f);
		i++;
	}
}
