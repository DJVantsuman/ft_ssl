/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:12:02 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:33:34 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_str_1(char *s, int pr, int l)
{
	if (s[0] == '-')
	{
		s[0] = '0';
		while ((pr - l) > 0)
		{
			s = ft_strjoin("0", s);
			pr--;
		}
		return (ft_strjoin("-", s));
	}
	else
		while ((pr - l) > 0)
		{
			s = ft_strjoin("0", s);
			pr--;
		}
	return (s);
}

static char	*get_str_2(char *s, int pr)
{
	char	a[2];
	char	*str;
	int		i;

	a[1] = '\0';
	str = "";
	i = 0;
	while (pr > 0)
	{
		a[0] = s[i];
		str = ft_strjoin(str, a);
		pr--;
		i++;
	}
	return (str);
}

char		*fill_precision(char *s, t_strf *f)
{
	int		l;
	int		pr;

	l = ft_strlen(s);
	pr = f->precision;
	if (pr == 0 || (pr < 0 && (s[0] != '0' && s[1] != '\0')))
		return (s);
	if (pr < 0 && s[0] == '0' && f->width == 0)
		return ("");
	if (pr < 0 && s[0] != '%')
		return (" ");
	if (l > pr && f->type != 's' && f->type != 'S' && f->type != 'c'
			&& f->type != 'C')
		return (s);
	else if (l >= pr && (f->type == 's' || f->type == 'S' ||
				f->type == 'c' || f->type == 'C') && s[0] != '%')
		return (get_str_2(s, pr));
	else if (l <= pr && f->type != 's' && f->type != 'S' &&
				f->type != 'c' && f->type != 'C')
		return (get_str_1(s, pr, l));
	return (s);
}
