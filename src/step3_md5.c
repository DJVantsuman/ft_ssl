/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:46:12 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:46:14 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

unsigned int	*step3_md5(unsigned char *msg, t_variables *var)
{
	unsigned int	*x;
	int				i;

	i = 0;
	var->a = 0x67452301;
	var->b = 0xefcdab89;
	var->c = 0x98badcfe;
	var->d = 0x10325476;
	while (i < 64)
	{
		var->t[i] = (unsigned int)(pow(2, 32) * fabs(sin(i + 1)));
		i++;
	}
	x = (unsigned int *)(msg);
	free(msg);
	return (x);
}
