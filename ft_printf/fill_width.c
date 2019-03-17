/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:42:10 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:52:04 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_f(t_strf *f, char c)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (f->flag[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*fill(char *s, t_strf *f, int t, char c)
{
	int		i;
	char	a[2];
	int		l;

	l = ft_strlen(s);
	i = f->width;
	a[1] = '\0';
	a[0] = c;
	if (is_f(f, '-'))
		t = 0;
	while (i - l > 0)
	{
		if (t == 1)
			s = ft_strjoin(a, s);
		else
			s = ft_strjoin(s, a);
		i--;
	}
	return (s);
}

char	*f_alt(t_strf *f, char *s)
{
	int		i;
	char	s1[3];
	int		l;

	i = 0;
	s1[0] = '0';
	s1[1] = f->type == 'X' ? 'X' : 'x';
	s1[2] = '\0';
	l = ft_strlen(s);
	if (f->precision < 0 && (f->type == 'x' || f->type == 'X'))
		return ("");
	if ((f->type == 'o' || f->type == 'O') && s[0] != '0')
		s = ft_strjoin("0", s);
	else if ((f->type == 'x' || f->type == 'X') && f->width > l)
		return (type_x(f, s));
	else if ((f->type == 'x' || f->type == 'X' || f->type == 'p') &&
			f->width <= l)
		if (is_f(f, '#'))
			s = ft_strjoin(s1, s);
	if (is_f(f, '-'))
		return (fill(s, f, 0, ' '));
	else if (is_f(f, '0') && !(is_f(f, '-')))
		return (fill(s, f, 1, '0'));
	return (fill(s, f, 1, ' '));
}

char	*f1(char *s, t_strf *f)
{
	if (is_f(f, '#') && (f->type == 'o' ||
				f->type == 'x' || f->type == 'O' || f->type == 'X'))
		return (f_alt(f, s));
	else if (is_f(f, '-'))
		return (fill(s, f, 0, ' '));
	else if (is_f(f, '0') && s[0] != '-' && s[0] != '0' && f->precision == 0)
		return (fill(s, f, 1, '0'));
	else if (is_f(f, '0') && s[0] == '-')
		return (flag_0_and_num_min(s, f));
	return (fill(s, f, 1, ' '));
}

char	*fill_width(char *s, t_strf *f)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	if (is_f(f, '+') && f->type != 'u')
		return (flag_plus(s, f));
	else if (s[0] == '0' && s[1] == '\0' && f->type != 'p')
		return (s);
	if (f->width <= l && (!(is_f(f, ' ')) ||
				(is_f(f, ' ') && s[0] == '-') || s[0] == '%') &&
			!(is_f(f, '#')) && !(is_f(f, '+')))
		return (s);
	else if (f->width <= l && is_f(f, ' ') && s[0] != '-' &&
			!(is_f(f, '#')) && f->type != 'u')
		return (ft_strjoin(" ", s));
	else if (f->width > l && (s[0] != '\0' || f->type == 's'))
		return (f1(s, f));
	else if (is_f(f, '#') && (f->type == 'o' || f->type == 'p' ||
				f->type == 'x' || f->type == 'O' || f->type == 'X'))
		return (f_alt(f, s));
	return (s);
}
