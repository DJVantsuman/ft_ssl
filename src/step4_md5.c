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

void    raund1(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + F(var->B, var->C, var->D) + X[0] +
				var->T[ 0]), 7);
	var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[1] +
				var->T[ 1]), 12);
	var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[2] +
				var->T[ 2]), 17);
	var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[3] +
				var->T[ 3]), 22);

	var->A = var->B + rotate_left((var->A + F(var->B ,var->C, var->D) + X[4] +
				var->T[ 4]), 7);
	var->D = var->A + rotate_left((var->D + F(var->A, var->B, var->C) + X[5] +
				var->T[ 5]), 12);
	var->C = var->D + rotate_left((var->C + F(var->D, var->A, var->B) + X[6] +
				var->T[ 6]), 17);
	var->B = var->C + rotate_left((var->B + F(var->C, var->D, var->A) + X[7] +
				var->T[ 7]), 22);

	raund1_1(X, var);
}

void    raund2(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[1] +
				var->T[16]), 5);
	var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[6] +
				var->T[17]), 9);
	var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[11] +
				var->T[18]), 14);
	var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[0] +
				var->T[19]), 20);

	var->A = var->B + rotate_left((var->A + G(var->B, var->C, var->D) + X[5] +
				var->T[20]), 5);
	var->D = var->A + rotate_left((var->D + G(var->A, var->B, var->C) + X[10] +
				var->T[21]), 9);
	var->C = var->D + rotate_left((var->C + G(var->D, var->A, var->B) + X[15] +
				var->T[22]), 14);
	var->B = var->C + rotate_left((var->B + G(var->C, var->D, var->A) + X[4] +
				var->T[23]), 20);

	raund2_1(X, var);
}

void    raund3(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[5] +
				var->T[32]), 4);
	var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[8] +
				var->T[33]), 11);
	var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[11] +
				var->T[34]), 16);
	var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[14] +
				var->T[35]), 23);

	var->A = var->B + rotate_left((var->A + H(var->B, var->C, var->D) + X[1] +
				var->T[36]), 4);
	var->D = var->A + rotate_left((var->D + H(var->A, var->B, var->C) + X[4] +
				var->T[37]), 11);
	var->C = var->D + rotate_left((var->C + H(var->D, var->A, var->B) + X[7] +
				var->T[38]), 16);
	var->B = var->C + rotate_left((var->B + H(var->C, var->D, var->A) + X[10] +
				var->T[39]), 23);

	raund3_1(X, var);
}

void    raund4(unsigned int *X, t_variables *var)
{
	var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[0] +
				var->T[48]), 6);
	var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[7] +
				var->T[49]), 10);
	var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[14] +
				var->T[50]), 15);
	var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[5] +
				var->T[51]), 21);

	var->A = var->B + rotate_left((var->A + I(var->B, var->C, var->D) + X[12] +
				var->T[52]), 6);
	var->D = var->A + rotate_left((var->D + I(var->A, var->B, var->C) + X[3] +
				var->T[53]), 10);
	var->C = var->D + rotate_left((var->C + I(var->D, var->A, var->B) + X[10] +
				var->T[54]), 15);
	var->B = var->C + rotate_left((var->B + I(var->C, var->D, var->A) + X[1] +
				var->T[55]), 21);

	raund4_1(X, var);
}

void    step4_md5(unsigned int *X, t_variables *var)
{
	unsigned int AA;
	unsigned int BB;
	unsigned int CC;
	unsigned int DD;

	for(size_t i = 0, j = 0; i < size / 64; i++, j += 16)
	{
		AA = var->A;
		BB = var->B;
		CC = var->C;
		DD = var->D;
		raund1(X + j, var);
		raund2(X + j, var);
		raund3(X + j, var);
		raund4(X + j, var);
		var->A += AA;
		var->B += BB;
		var->C += CC;
		var->D += DD;
	}
}
