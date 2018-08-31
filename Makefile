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
FLAGS = -Wall -Werror -Wextra
SRC_PATH = ./src/
SRC = src/main.c src/checkArguments.c
OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OSRC) libft/libft.a
	@make clean

%.o: %.c
	@gcc -g $(FLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	@rm -f $(OSRC)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
