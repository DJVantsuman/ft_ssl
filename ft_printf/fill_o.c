/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:45:18 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 18:55:54 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_string(uintmax_t value, size_t base)
{
	int result;

	result = 0;
	while (value >= base)
	{
		value = value / base;
		result++;
	}
	result++;
	return (result);
}

char	*ft_itoa_for_minus(intmax_t value, int base, char *all_bases)
{
	char	*str;
	int		m;

	if (value == -2147483648)
		str = "-2147483648";
	else
	{
		value = -value;
		m = count_string(value, base) + 1;
		str = (char *)malloc(sizeof(char) * m + 1);
		str[m] = '\0';
		while (value >= base)
		{
			str[--m] = all_bases[value % base];
			value = value / base;
		}
		str[--m] = all_bases[value];
		str[--m] = '-';
	}
	return (str);
}

char	*ft_itoa_base(uintmax_t value, char type, size_t base)
{
	char	*all_bases;
	char	*str;
	int		m;

	if (type == 'X' || type == 'O')
		all_bases = "0123456789ABCDEF";
	else
		all_bases = "0123456789abcdef";
	m = count_string(value, base);
	str = (char *)malloc(sizeof(char) * m + 1);
	str[m] = '\0';
	while (value >= base)
	{
		str[--m] = all_bases[value % base];
		value = value / base;
	}
	str[--m] = all_bases[value];
	return (str);
}

char	*fill_ox(t_strf *f, va_list ap)
{
	uintmax_t	n;
	int			base;

	n = 0;
	base = 0;
	if (f->mod_size == 'z')
		n = va_arg(ap, size_t);
	else if (f->mod_size == 'j')
		n = va_arg(ap, uintmax_t);
	else if (f->mod_size == 'l' && f->pr == 4)
		n = va_arg(ap, long long);
	else if ((f->mod_size == 'l' && f->pr == 3) || f->type == 'D')
		n = va_arg(ap, long);
	else if (f->mod_size == 'h' && f->pr == 2)
		n = (short int)(va_arg(ap, int));
	else if (f->mod_size == 'h' && f->pr == 1)
		n = (signed char)(va_arg(ap, int));
	else
		n = va_arg(ap, unsigned int);
	if (f->type == 'x' || f->type == 'X' || f->type == 'p')
		base = 16;
	else
		base = 8;
	return (ft_itoa_base(n, f->type, base));
}
