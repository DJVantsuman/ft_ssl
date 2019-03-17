/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:24:15 by itsuman           #+#    #+#             */
/*   Updated: 2017/02/24 17:23:48 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(t_strf *f, char flag)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (f->flag[i] == flag)
			return (1);
		i++;
	}
	return (0);
}

void	check_flag(const char *format, t_strf *f)
{
	int		i;
	int		j;
	int		t;
	char	*flag;

	i = 0;
	flag = "#0-+ ";
	while (is_spesify(format[i]) && format[i] != f->type)
	{
		t = 0;
		j = 0;
		while (flag[j] != '\0' && !(format[i] >= 49 && format[i] <= 57))
		{
			if (flag[j] == format[i] && !(isflag(f, format[i])))
				f->flag[t] = format[i];
			t++;
			j++;
		}
		if (format[i] >= 49 && format[i] <= 57)
			break ;
		i++;
	}
}
