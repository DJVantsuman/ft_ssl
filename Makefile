# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsuman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 21:04:51 by itsuman           #+#    #+#              #
#    Updated: 2018/08/29 21:05:38 by itsuman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ssl
FLAGS = -g -Wall -Werror -Wextra
SRC_PATH = ./src/
SRC = src/main.c src/calculate_md5.c src/check_arguments.c src/step1_md5.c \
src/step2_md5.c src/step3_md5.c src/step4_md5.c src/md5_algoritm.c        \
src/print_output.c src/calculate_sha256.c src/sha256_algoritm.c            \
src/sha256_algoritm_1.c src/main_loop_sha256.c src/step4_md5_1.c
OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	@make -C libft
	@make -C ft_printf
	@gcc -o $(NAME) $(FLAGS) $(OSRC) libft/libft.a ft_printf/libftprintf.a
	@make clean

%.o: %.c
	@gcc -g $(FLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -f $(OSRC)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
