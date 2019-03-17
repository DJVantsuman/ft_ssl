/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:31:43 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:26:19 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_strf	f_initial(t_strf *f)
{
	f->flag[0] = '\0';
	f->flag[1] = '\0';
	f->flag[2] = '\0';
	f->flag[3] = '\0';
	f->flag[4] = '\0';
	f->mod_size = '\0';
	f->pr = 0;
	f->type = '\0';
	f->width = 0;
	f->precision = 0;
	return (*f);
}

int		lenght(const char *s, char c)
{
	int	i;

	i = 0;
	while (is_spesify(s[i]) && s[i] != c)
		i++;
	if (s[i] == '\0')
		i--;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_strf	f;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			f = f_initial(&f);
			formater_arg(format + i + 1, &f, ap);
			i += lenght(format + i + 1, f.type) + 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (g_ivan);
}
