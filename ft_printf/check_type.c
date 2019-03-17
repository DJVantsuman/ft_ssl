/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:15:26 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 18:43:02 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(const char *format, t_strf *f)
{
	int		i;
	int		j;
	char	*type;

	i = 0;
	type = "sSpdDioOuUxXcC";
	while (is_spesify(format[i]))
	{
		j = -1;
		while (type[++j] != '\0')
			if (type[j] == format[i])
			{
				f->type = format[i];
				if (f->type == 'p')
				{
					f->flag[0] = '#';
					f->mod_size = 'l';
					f->pr = 3;
				}
				return ;
			}
		i++;
	}
}
