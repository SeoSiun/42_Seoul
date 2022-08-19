# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 22:32:35 by siseo             #+#    #+#              #
#    Updated: 2022/08/20 00:14:20 by siseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c print_c.c print_diu.c print_percent.c print_pxX.c print_s.c
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft
LIBFT_LIB = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT_LIB) .
	mv $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

bonus:

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_PATH)/$(LIBFT_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus