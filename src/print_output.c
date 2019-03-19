/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:42:02 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:42:07 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

void			print_output(t_variables *var, t_container *cnt)
{
	if (cnt->is_quiet == 1 || cnt->flag == 'p')
		ft_printf("%.8x%.8x%.8x%.8x\n",
				rev_bit(var->a), rev_bit(var->b), rev_bit(var->c),
				rev_bit(var->d));
	else if (cnt->flag == 'f' && cnt->is_revers == 0)
		ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", cnt->file_name,
				rev_bit(var->a), rev_bit(var->b), rev_bit(var->c),
				rev_bit(var->d));
	else if (cnt->is_revers == 1 && cnt->flag == 'f')
		ft_printf("%.8x%.8x%.8x%.8x %s\n", rev_bit(var->a),
				rev_bit(var->b), rev_bit(var->c), rev_bit(var->d),
				cnt->file_name);
	else if (cnt->is_revers == 1)
		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", rev_bit(var->a),
				rev_bit(var->b), rev_bit(var->c), rev_bit(var->d),
				cnt->message);
	else
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", cnt->message,
				rev_bit(var->a), rev_bit(var->b), rev_bit(var->c),
				rev_bit(var->d));
}

void			print_output_sha256(t_variables *var, t_container *cnt)
{
	if (cnt->is_quiet == 1 || cnt->flag == 'p')
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
				var->h0, var->h1, var->h2, var->h3,
				var->h4, var->h5, var->h6, var->h7);
	else if (cnt->flag == 'f' && cnt->is_revers == 0)
		ft_printf("SHA256 (%s) = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
				cnt->file_name, var->h0, var->h1, var->h2, var->h3,
				var->h4, var->h5, var->h6, var->h7);
	else if (cnt->is_revers == 1 && cnt->flag == 'f')
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x  %s\n",
				var->h0, var->h1, var->h2, var->h3,
				var->h4, var->h5, var->h6, var->h7,
				cnt->file_name);
	else if (cnt->is_revers == 1)
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x  \"%s\"\n",
				var->h0, var->h1, var->h2, var->h3,
				var->h4, var->h5, var->h6, var->h7,
				cnt->message);
	else
		ft_printf("SHA256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
				cnt->message, var->h0, var->h1, var->h2, var->h3,
				var->h4, var->h5, var->h6, var->h7);
}

unsigned int	rev_bit(unsigned int var)
{
	unsigned int t;

	t = var << 24;
	t += (var & 65280) << 8;
	t += (var & 16711680) >> 8;
	t += var >> 24;
	return (t);
}
