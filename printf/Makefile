# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:56:37 by eduarodr          #+#    #+#              #
#    Updated: 2023/04/24 17:37:17 by eduarodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c\
		functions.c\
		functions2.c\

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = @gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
