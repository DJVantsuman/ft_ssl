/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_spesify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:18:03 by itsuman           #+#    #+#             */
/*   Updated: 2017/02/24 17:03:59 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_spesify(char c)
{
	char	*spesify;

	spesify = "sSpdDioOuUxXcChljz#0-+ .123456789";
	while (*spesify != '\0')
	{
		if (*spesify == c)
			return (1);
		spesify++;
	}
	return (0);
}