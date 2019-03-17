/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:37:44 by itsuman           #+#    #+#             */
/*   Updated: 2017/03/14 20:36:20 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef	struct	s_strf
{
	char		flag[5];
	char		mod_size;
	int			pr;
	char		type;
	int			width;
	int			precision;
}				t_strf;

int				g_ivan;

void			formater_arg(const char *format, t_strf *f, va_list ap);
void			check_type(const char *format, t_strf *f);
void			check_mod_size(const char *format, t_strf *f);
void			check_width(const char *format, t_strf *f);
void			check_flag(const char *format, t_strf *f);
void			check_pricision(const char *format, t_strf *f);
void			print_str(t_strf *f, va_list ap, const char *format);

char			*flag_plus(char *s, t_strf *f);
char			*get_vaule(t_strf *f, va_list ap, const char *format);
char			*fill_type(t_strf *f, va_list ap);
char			*fill_precision(char *s, t_strf *f);
char			*fill_width(char *s, t_strf *f);
char			*ft_strjoin(char const *s1, char const *s2);
char			*fill_s(char *s);
char			*fill_d(t_strf *f, va_list ap);
char			*fill_ox(t_strf *f, va_list ap);
char			*fill_u(t_strf *f, va_list ap);
char			*fill_c(va_list ap, t_strf *f);
char			*fill_p(char *s);
char			*fill(char *s, t_strf *f, int t, char c);
char			*type_x(t_strf *f, char *s);
char			*flag_0_and_num_min(char *s, t_strf *f);
char			*type_c_width(char *s, t_strf *f);

int				is_spesify(char c);
int				is_f(t_strf *f, char c);
int				ft_printf(const char *format, ...);

#endif
