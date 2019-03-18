/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:58:43 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 18:05:40 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formater_arg(const char *format, t_strf *f, va_list ap)
{
	check_type(format, f);
	check_mod_size(format, f);
	check_pricision(format, f, 0);
	check_width(format, f);
	check_flag(format, f);
	print_str(f, ap, format);
}
