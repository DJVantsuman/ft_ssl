/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:55:56 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:37:07 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_c_2(char c, t_strf *f)
{
	char	*a;
	int		i;

	a = malloc(sizeof(char) * 2);
	if (c == '\0')
	{
		g_ivan++;
		if (f->width > 0)
		{
			f->width = 1;
			c = ' ';
		}
		if (is_f(f, ' '))
		{
			i = 0;
			while (f->flag[i] != ' ')
				i++;
			f->flag[i] = '\0';
		}
	}
	a[0] = c;
	a[1] = '\0';
	return (a);
}

char	*fill_c(va_list ap, t_strf *f)
{
	char c;

	c = (char)va_arg(ap, int);
	if (c == 0 && !(is_f(f, ' ')) && f->width == 0)
	{
		write(1, &c, 1);
		g_ivan++;
		return ("");
	}
	return (fill_c_2(c, f));
}
