/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strworldup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:55:54 by itsuman           #+#    #+#             */
/*   Updated: 2016/11/30 21:17:10 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strworldup(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] >= 97 && s[i] <= 122)
			{
				s[i] -= 32;
				while (s[i] != '\0')
				{
					if (s[i] == 32)
						break ;
					i++;
				}
			}
			else
				i++;
		}
	}
	return (s);
}
