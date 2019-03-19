/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4_md5_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:44:46 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/18 21:44:49 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

void	raund1_1(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + f(var->b, var->c, var->d) + x[8] +
				var->t[8]), 7);
	var->d = var->a + rotate_left((var->d + f(var->a, var->b, var->c) + x[9] +
				var->t[9]), 12);
	var->c = var->d + rotate_left((var->c + f(var->d, var->a, var->b) + x[10] +
				var->t[10]), 17);
	var->b = var->c + rotate_left((var->b + f(var->c, var->d, var->a) + x[11] +
				var->t[11]), 22);
	var->a = var->b + rotate_left((var->a + f(var->b, var->c, var->d) + x[12] +
				var->t[12]), 7);
	var->d = var->a + rotate_left((var->d + f(var->a, var->b, var->c) + x[13] +
				var->t[13]), 12);
	var->c = var->d + rotate_left((var->c + f(var->d, var->a, var->b) + x[14] +
				var->t[14]), 17);
	var->b = var->c + rotate_left((var->b + f(var->c, var->d, var->a) + x[15] +
				var->t[15]), 22);
}

void	raund2_1(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + g(var->b, var->c, var->d) + x[9] +
				var->t[24]), 5);
	var->d = var->a + rotate_left((var->d + g(var->a, var->b, var->c) + x[14] +
				var->t[25]), 9);
	var->c = var->d + rotate_left((var->c + g(var->d, var->a, var->b) + x[3] +
				var->t[26]), 14);
	var->b = var->c + rotate_left((var->b + g(var->c, var->d, var->a) + x[8] +
				var->t[27]), 20);
	var->a = var->b + rotate_left((var->a + g(var->b, var->c, var->d) + x[13] +
				var->t[28]), 5);
	var->d = var->a + rotate_left((var->d + g(var->a, var->b, var->c) + x[2] +
				var->t[29]), 9);
	var->c = var->d + rotate_left((var->c + g(var->d, var->a, var->b) + x[7] +
				var->t[30]), 14);
	var->b = var->c + rotate_left((var->b + g(var->c, var->d, var->a) + x[12] +
				var->t[31]), 20);
}

void	raund3_1(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + h(var->b, var->c, var->d) + x[13] +
				var->t[40]), 4);
	var->d = var->a + rotate_left((var->d + h(var->a, var->b, var->c) + x[0] +
				var->t[41]), 11);
	var->c = var->d + rotate_left((var->c + h(var->d, var->a, var->b) + x[3] +
				var->t[42]), 16);
	var->b = var->c + rotate_left((var->b + h(var->c, var->d, var->a) + x[6] +
				var->t[43]), 23);
	var->a = var->b + rotate_left((var->a + h(var->b, var->c, var->d) + x[9] +
				var->t[44]), 4);
	var->d = var->a + rotate_left((var->d + h(var->a, var->b, var->c) + x[12] +
				var->t[45]), 11);
	var->c = var->d + rotate_left((var->c + h(var->d, var->a, var->b) + x[15] +
				var->t[46]), 16);
	var->b = var->c + rotate_left((var->b + h(var->c, var->d, var->a) + x[2] +
				var->t[47]), 23);
}

void	raund4_1(unsigned int *x, t_variables *var)
{
	var->a = var->b + rotate_left((var->a + i(var->b, var->c, var->d) + x[8] +
				var->t[56]), 6);
	var->d = var->a + rotate_left((var->d + i(var->a, var->b, var->c) + x[15] +
				var->t[57]), 10);
	var->c = var->d + rotate_left((var->c + i(var->d, var->a, var->b) + x[6] +
				var->t[58]), 15);
	var->b = var->c + rotate_left((var->b + i(var->c, var->d, var->a) + x[13] +
				var->t[59]), 21);
	var->a = var->b + rotate_left((var->a + i(var->b, var->c, var->d) + x[4] +
				var->t[60]), 6);
	var->d = var->a + rotate_left((var->d + i(var->a, var->b, var->c) + x[11] +
				var->t[61]), 10);
	var->c = var->d + rotate_left((var->c + i(var->d, var->a, var->b) + x[2] +
				var->t[62]), 15);
	var->b = var->c + rotate_left((var->b + i(var->c, var->d, var->a) + x[9] +
				var->t[63]), 21);
}
