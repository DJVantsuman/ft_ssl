/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:20 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 20:29:46 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_type(t_strf *f, va_list ap)
{
	if (f->type == 's' || f->type == 'S')
		return (fill_s(va_arg(ap, char *)));
	else if (f->type == 'd' || f->type == 'i' || f->type == 'D')
		return (fill_d(f, ap));
	else if (f->type == 'o' || f->type == 'O'
			|| f->type == 'x' || f->type == 'X' || f->type == 'p')
		return (fill_ox(f, ap));
	else if (f->type == 'u' || f->type == 'U')
		return (fill_u(f, ap));
	else if (f->type == 'c' || f->type == 'C')
		return (fill_c(ap, f));
	return (0);
}
