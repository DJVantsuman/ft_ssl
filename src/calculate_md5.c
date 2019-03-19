/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculateMd5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:41:22 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:41:29 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include "../inc/md5.h"

void	check_flags(t_container **container, int is_revers, int is_quiet)
{
	t_container *var;

	var = *container;
	while (var)
	{
		if (var->flag == 'r')
			is_revers = 1;
		else if (var->flag == 'q')
			is_quiet = 1;
		if ((var->flag == 's' || var->flag == 'p' || var->flag == 'f')
				&& is_revers == 1)
		{
			var->is_revers = 1;
			is_revers = 0;
		}
		if ((var->flag == 's' || var->flag == 'p' || var->flag == 'f')
				&& is_quiet == 1)
		{
			var->is_quiet = 1;
			is_quiet = 0;
		}
		var = var->next;
	}
}

void	illegal_option(char flag)
{
	if (g_type == HASH_MD_5)
		ft_printf("md5: illegal option -- %c\n", flag);
	else if (g_type == HASH_SHA256)
		ft_printf("sha256: illegal option -- %c\n", flag);
	print_usage();
}

void	calculate_md5(t_container **container)
{
	t_container		*cnt;
	t_variables		var;
	unsigned int	*x;

	cnt = *container;
	check_flags(container, 0, 0);
	while (cnt)
	{
		if (cnt->flag != 's' && cnt->flag != 'p' && cnt->flag != 'r'
				&& cnt->flag != 'q' &&
				!(cnt->flag == 'f' && cnt->is_valid == 1))
			illegal_option(cnt->flag);
		else if (cnt->error == 1)
			ft_printf("md5: %s: No such file or directory\n", cnt->file_name);
		else if (cnt->flag == 'p' || cnt->flag == 's' ||
				(cnt->flag == 'f' && cnt->is_valid == 1))
		{
			x = step3_md5(step2_md5(step1_md5(cnt), cnt), &var);
			step4_md5(x, &var, 0, 0);
			print_output(&var, cnt);
		}
		cnt = cnt->next;
	}
}
