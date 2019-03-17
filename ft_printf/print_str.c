/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:59:51 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 20:29:59 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_strf *f, va_list ap, const char *format)
{
	char *s;

	s = get_vaule(f, ap, format);
	ft_putstr(s);
	free(s);
}
