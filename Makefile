# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 10:30:17 by imamasol          #+#    #+#              #
#    Updated: 2025/07/07 10:36:14 by imamasol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_hexconvert.c ft_paramchar.c ft_paramint.c ft_paramptr.c ft_paramunt.c ft_putchar_fd.c ft_strlcpy.c \
ft_utoa.c ft_itoa.c ft_paramhex.c ft_paramper.c ft_paramstr.c ft_printf.c ft_putstr_fd.c ft_strlen.c

OBJ = $(SRCS:.c=.o)
COMP = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c printf.h
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all