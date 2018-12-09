# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 19:27:14 by rnaumenk          #+#    #+#              #
#    Updated: 2017/12/16 19:27:15 by rnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a
CS =	./CS/ft_strlen.c \
		./CS/ft_putchar.c \
		./CS/ft_putstr.c \
		./CS/validation.c \
		./CS/map_and_figures_creator.c \
		./CS/solver.c
OBJECTS =	./ft_strlen.o \
			./ft_putchar.o \
			./ft_putstr.o \
			./validation.o \
			./map_and_figures_creator.o \
			./solver.o

all: $(NAME)

$(NAME): $(LIB)
	@gcc -Wall -Wextra -Werror ./CS/main.c $< -o $@
	@echo "\033[32mFILLIT IS READY\033[0m"

%.o: ./CS/%.c
	@gcc -Wall -Wextra -Werror -c $< 

$(LIB): $(OBJECTS)
	@ar rc $@ $^ 

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -f $(LIB)
	@echo "\033[33mObjects and libft.a are removed\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mFILLIT is removed\033[0m"

re: fclean all

.PHONY: all clean fclean re
