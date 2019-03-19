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

void            raund1_1(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[8] +
				var->T[ 8]), 7);
	var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[9] +
				var->T[ 9]), 12);
	var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[10] +
				var->T[10]), 17);
	var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[11] +
				var->T[11]), 22);

	var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[12] +
				var->T[12]), 7);
	var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[13] +
				var->T[13]), 12);
	var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[14] +
				var->T[14]), 17);
	var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[15] +
				var->T[15]), 22);
}

void            raund2_1(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[9] +
				var->T[24]), 5);
	var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[14] +
				var->T[25]), 9);
	var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[3] +
				var->T[26]), 14);
	var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[8] +
				var->T[27]), 20);

	var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[13] +
				var->T[28]), 5);
	var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[2] +
				var->T[29]), 9);
	var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[7] +
				var->T[30]), 14);
	var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[12] +
				var->T[31]), 20);
}

void            raund3_1(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[13] +
				var->T[40]), 4);
	var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[0] +
				var->T[41]), 11);
	var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[3] +
				var->T[42]), 16);
	var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[6] +
				var->T[43]), 23);

	var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[9] +
				var->T[44]), 4);
	var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[12] +
				var->T[45]), 11);
	var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[15] +
				var->T[46]), 16);
	var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[2] +
				var->T[47]), 23);
}

void            raund4_1(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[8] +
				var->T[56]), 6);
	var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[15] +
				var->T[57]), 10);
	var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[6] +
				var->T[58]), 15);
	var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[13] +
				var->T[59]), 21);

	var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[4] +
				var->T[60]), 6);
	var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[11] +
				var->T[61]), 10);
	var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[2] +
				var->T[62]), 15);
	var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[9] +
				var->T[63]), 21);
}
