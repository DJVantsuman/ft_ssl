/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:17:33 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:42:28 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_num(uintmax_t n, int l, int f)
{
	char *s;

	s = (char *)malloc(sizeof(char) * l + 1);
	s[l] = '\0';
	if (f == 0)
		while (--l >= 0)
		{
			s[l] = n % 10 + '0';
			n = n / 10;
		}
	else
	{
		s[0] = '-';
		l--;
		while (l > 0)
		{
			s[l] = n % 10 + '0';
			n = n / 10;
			l--;
		}
	}
	return (s);
}

char	*count_num(intmax_t n)
{
	int			l;
	int			f;
	uintmax_t	num;
	uintmax_t	t;

	l = 1;
	f = 0;
	if (n < 0)
	{
		l++;
		f++;
		t = -n;
	}
	else
		t = n;
	num = t;
	while (t >= 10)
	{
		t /= 10;
		l++;
	}
	return (write_num(num, l, f));
}

char	*fill_d(t_strf *f, va_list ap)
{
	if (f->mod_size == 'z')
		return (count_num((long long)(va_arg(ap, ssize_t))));
	else if (f->mod_size == 'j')
		return (count_num((long long)(va_arg(ap, intmax_t))));
	else if (f->mod_size == 'l' && f->pr == 4)
		return (count_num(va_arg(ap, long long)));
	else if ((f->mod_size == 'l' && f->pr == 3) || f->type == 'D')
		return (count_num((long long)(va_arg(ap, long))));
	else if (f->mod_size == 'h' && f->pr == 2)
		return (count_num((short int)(va_arg(ap, int))));
	else if (f->mod_size == 'h' && f->pr == 1)
		return (count_num((signed char)(va_arg(ap, int))));
	return (count_num((long long)(va_arg(ap, int))));
}
