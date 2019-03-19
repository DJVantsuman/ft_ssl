# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsuman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 18:22:44 by itsuman           #+#    #+#              #
#    Updated: 2017/03/13 19:16:38 by itsuman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC =	type_c_width.c flag_plus.c check_flag.c check_mod_size.c    \
check_pricision.c check_type.c check_width.c fill_c.c fill_d.c fill_o.c        \
fill_precision.c fill_s.c fill_type.c fill_u.c fill_width.c formater_arg.c     \
ft_printf.c get_vaule.c is_spesify.c print_str.c type_x.c flag_nul_nammin.c
OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC) ../libft/libft.a
	@make clean

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all
