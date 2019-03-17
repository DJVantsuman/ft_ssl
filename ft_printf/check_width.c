/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:05:53 by itsuman           #+#    #+#             */
/*   Updated: 2017/02/24 17:03:32 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_nam(char *s, t_strf *f)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	f->width = n;
}

void	check_width(const char *format, t_strf *f)
{
	int		i;
	char	a[2];
	char	*s;

	i = 0;
	a[1] = '\0';
	s = "";
	while (is_spesify(format[i]) && f->width == 0 && format[i] != '.')
	{
		if (format[i] >= 49 && format[i] <= 57)
		{
			while (format[i] >= 48 && format[i] <= 57)
			{
				a[0] = format[i];
				s = ft_strjoin(s, a);
				i++;
			}
			take_nam(s, f);
		}
		i++;
	}
}
