/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:14:22 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/09 18:06:55 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*write_num(unsigned long long n, int l)
{
	char *s;

	s = (char *)malloc(sizeof(char) * l + 1);
	s[l] = '\0';
	while (--l >= 0)
	{
		s[l] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

static char	*count_num(unsigned long long n)
{
	int					l;
	unsigned long long	t;

	l = 1;
	t = n;
	while (n >= 10)
	{
		n /= 10;
		l++;
	}
	return (write_num(t, l));
}

char		*fill_u(t_strf *f, va_list ap)
{
	if (f->mod_size == 'z')
		return (count_num((unsigned long long)(va_arg(ap, ssize_t))));
	else if (f->mod_size == 'j')
		return (count_num((unsigned long long)(va_arg(ap, intmax_t))));
	else if (f->mod_size == 'l' && f->pr == 4)
		return (count_num((unsigned long long)(va_arg(ap, long long))));
	else if ((f->mod_size == 'l' && f->pr == 3) || f->type == 'U')
		return (count_num((unsigned long long)(va_arg(ap, long))));
	else if (f->mod_size == 'h' && f->pr == 2)
		return (count_num((short int)(va_arg(ap, int))));
	else if (f->mod_size == 'h' && f->pr == 1)
		return (count_num((signed char)(va_arg(ap, int))));
	return (count_num((unsigned int)(va_arg(ap, int))));
}
