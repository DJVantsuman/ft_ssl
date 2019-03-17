/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag+.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:43:27 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:39:39 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*f_min(char *s, t_strf *f)
{
	int		i;
	int		l;
	int		t;

	i = 0;
	l = f->width;
	t = ft_strlen(s);
	if (is_f(f, '0'))
		while (--l - t)
			s = ft_strjoin("0", s);
	else
	{
		s = ft_strjoin("-", s);
		while (--l - t)
			s = ft_strjoin(" ", s);
		return (s);
	}
	return (ft_strjoin("-", s));
}

static char	*f_plus(char *s, t_strf *f)
{
	int		i;
	int		l;
	int		t;

	i = 0;
	l = f->width;
	t = ft_strlen(s);
	if (is_f(f, '0'))
		while (--l - t)
			s = ft_strjoin("0", s);
	else
	{
		s = ft_strjoin("+", s);
		while (--l - t)
			s = ft_strjoin(" ", s);
		return (s);
	}
	return (ft_strjoin("+", s));
}

char		*flag_minus(char *s, t_strf *f)
{
	int l;
	int w;

	s = ft_strjoin("+", s);
	l = ft_strlen(s);
	w = f->width;
	while (w - l > 0)
	{
		s = ft_strjoin(s, " ");
		w--;
	}
	return (s);
}

char		*flag_plus(char *s, t_strf *f)
{
	int l;

	l = ft_strlen(s);
	if (f->width <= l && s[0] != '-')
		return (ft_strjoin("+", s));
	if (f->width > l && s[0] != '-' && is_f(f, '-'))
		return (flag_minus(s, f));
	if (f->width > l && s[0] != '-')
		return (f_plus(s, f));
	if (f->width > l && s[0] == '-')
		return (f_min(s + 1, f));
	return (s);
}
