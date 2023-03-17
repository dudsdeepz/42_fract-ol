# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:57:13 by eduarodr          #+#    #+#              #
#    Updated: 2023/03/17 10:27:41 by eduarodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

SRC = fract_ol.c\
		src/controls.c\
		src/win_managment.c\
		src/utils.c\
		src/mandelbrot.c\

OBJ = ${SRC:.c=.o}


CC = cc

RM = rm -f

CCFLAGS = -Werror -Wextra -Werror

PRINTF_PATH = ./printf
PRINTF_NAME = libftprintf.a

MLX_NAME = libmlx.a
MLX_PATH = ./mlx
MLX = ./mlx/libmlx.a

$(PRINTF_NAME):
		@make -C $(PRINTF_PATH)

all: ${MLX_NAME} ${NAME}

${MLX_NAME}:
	@make -C ${MLX_PATH}

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o ${NAME} ${MLX} -L ./printf -lftprintf

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
