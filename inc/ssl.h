/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:51:52 by itsuman           #+#    #+#             */
/*   Updated: 2019/03/19 23:01:47 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SSL_H
# define _SSL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef	struct			s_container
{
	char				flag;
	char				*message;
	char				*file_name;
	size_t				message_len;
	int					is_valid;
	int					is_revers;
	int					is_quiet;
	int					error;
	struct s_container	*next;
}						t_container;

typedef struct			s_variables
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		h0;
	unsigned int		h1;
	unsigned int		h2;
	unsigned int		h3;
	unsigned int		h4;
	unsigned int		h5;
	unsigned int		h6;
	unsigned int		h7;
	unsigned int		t[64];
}						t_variables;

typedef enum			e_type
{
	UNDEFINED,
	HASH_MD_5,
	HASH_SHA256
}						t_type;

t_type					g_type;
size_t					g_size;

void					print_usage();
void					illegal_option(char flag);
void					print_output(t_variables *var, t_container *container);
void					print_output_sha256(t_variables *var, t_container *cnt);
void					calculate_md5(t_container **container);
void					calculate_sha256(t_container **container);
void					check_arguments(int ac, char **av,
		t_container **container);
void					get_command(char *command);
void					add_lst(t_container **alst, t_container *new_lst);
t_container				*new_lst(char *content);
unsigned int			rev_bit(unsigned int var);

#endif
