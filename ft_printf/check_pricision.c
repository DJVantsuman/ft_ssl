/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pricision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:40:18 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 19:44:31 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_num(t_strf *f, char *s)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	if(s != NULL)
        while (s[i] != '\0')
        {
            n = n * 10 + s[i] - '0';
            i++;
        }
	f->precision = n;
}

void	check_pr(const char *format, t_strf *f)
{
	int i;

	i = -1;
	while (is_spesify(format[++i]))
		if (format[i] == '.')
		{
			if (!(format[i + 1] >= 49 && format[i + 1] <= 57) ||
					format[i] == '0')
				f->precision = -1;
			break ;
		}
}

void	check_pricision(const char *format, t_strf *f, int i)
{
	char	*s;
	char    *tmp;
	char	a[2];

	i = 0;
	s = NULL;
	a[1] = '\0';
	while (is_spesify(format[i]))
		if (format[i] == '.')
		{
			i++;
			f->precision = 0;
			while ((format[i] >= 49 && format[i] <= 58) || format[i] == '0')
			{
			    tmp = s;
				a[0] = format[i];
				s = ft_strjoin(tmp, a);
				ft_strdel(&tmp);
				i++;
			}
			get_num(f, s);
			break ;
		}
		else
			i++;
	check_pr(format, f);
}
