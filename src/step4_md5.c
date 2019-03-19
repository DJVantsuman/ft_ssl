/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:43:03 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:43:07 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

void	raund1(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + f(var->b, var->c, var->d) + x[0] +
				var->t[0]), 7);
	var->d = var->a + rotate_left((var->d + f(var->a, var->b, var->c) + x[1] +
				var->t[1]), 12);
	var->c = var->d + rotate_left((var->c + f(var->d, var->a, var->b) + x[2] +
				var->t[2]), 17);
	var->b = var->c + rotate_left((var->b + f(var->c, var->d, var->a) + x[3] +
				var->t[3]), 22);
	var->a = var->b + rotate_left((var->a + f(var->b, var->c, var->d) + x[4] +
				var->t[4]), 7);
	var->d = var->a + rotate_left((var->d + f(var->a, var->b, var->c) + x[5] +
				var->t[5]), 12);
	var->c = var->d + rotate_left((var->c + f(var->d, var->a, var->b) + x[6] +
				var->t[6]), 17);
	var->b = var->c + rotate_left((var->b + f(var->c, var->d, var->a) + x[7] +
				var->t[7]), 22);
	raund1_1(x, var);
}

void	raund2(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + g(var->b, var->c, var->d) + x[1] +
				var->t[16]), 5);
	var->d = var->a + rotate_left((var->d + g(var->a, var->b, var->c) + x[6] +
				var->t[17]), 9);
	var->c = var->d + rotate_left((var->c + g(var->d, var->a, var->b) + x[11] +
				var->t[18]), 14);
	var->b = var->c + rotate_left((var->b + g(var->c, var->d, var->a) + x[0] +
				var->t[19]), 20);
	var->a = var->b + rotate_left((var->a + g(var->b, var->c, var->d) + x[5] +
				var->t[20]), 5);
	var->d = var->a + rotate_left((var->d + g(var->a, var->b, var->c) + x[10] +
				var->t[21]), 9);
	var->c = var->d + rotate_left((var->c + g(var->d, var->a, var->b) + x[15] +
				var->t[22]), 14);
	var->b = var->c + rotate_left((var->b + g(var->c, var->d, var->a) + x[4] +
				var->t[23]), 20);
	raund2_1(x, var);
}

void	raund3(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + h(var->b, var->c, var->d) + x[5] +
				var->t[32]), 4);
	var->d = var->a + rotate_left((var->d + h(var->a, var->b, var->c) + x[8] +
				var->t[33]), 11);
	var->c = var->d + rotate_left((var->c + h(var->d, var->a, var->b) + x[11] +
				var->t[34]), 16);
	var->b = var->c + rotate_left((var->b + h(var->c, var->d, var->a) + x[14] +
				var->t[35]), 23);
	var->a = var->b + rotate_left((var->a + h(var->b, var->c, var->d) + x[1] +
				var->t[36]), 4);
	var->d = var->a + rotate_left((var->d + h(var->a, var->b, var->c) + x[4] +
				var->t[37]), 11);
	var->c = var->d + rotate_left((var->c + h(var->d, var->a, var->b) + x[7] +
				var->t[38]), 16);
	var->b = var->c + rotate_left((var->b + h(var->c, var->d, var->a) + x[10] +
				var->t[39]), 23);
	raund3_1(x, var);
}

void	raund4(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + i(var->b, var->c, var->d) + x[0] +
				var->t[48]), 6);
	var->d = var->a + rotate_left((var->d + i(var->a, var->b, var->c) + x[7] +
				var->t[49]), 10);
	var->c = var->d + rotate_left((var->c + i(var->d, var->a, var->b) + x[14] +
				var->t[50]), 15);
	var->b = var->c + rotate_left((var->b + i(var->c, var->d, var->a) + x[5] +
				var->t[51]), 21);
	var->a = var->b + rotate_left((var->a + i(var->b, var->c, var->d) + x[12] +
				var->t[52]), 6);
	var->d = var->a + rotate_left((var->d + i(var->a, var->b, var->c) + x[3] +
				var->t[53]), 10);
	var->c = var->d + rotate_left((var->c + i(var->d, var->a, var->b) + x[10] +
				var->t[54]), 15);
	var->b = var->c + rotate_left((var->b + i(var->c, var->d, var->a) + x[1] +
				var->t[55]), 21);
	raund4_1(x, var);
}

void	step4_md5(unsigned int *x, t_variables *var, size_t i, size_t j)
{
	unsigned int	aa;
	unsigned int	bb;
	unsigned int	cc;
	unsigned int	dd;

	i = 0;
	j = 0;
	while (i < g_size / 64)
	{
		aa = var->a;
		bb = var->b;
		cc = var->c;
		dd = var->d;
		raund1(x + j, var);
		raund2(x + j, var);
		raund3(x + j, var);
		raund4(x + j, var);
		var->a += aa;
		var->b += bb;
		var->c += cc;
		var->d += dd;
		i++;
		j += 16;
	}
}
