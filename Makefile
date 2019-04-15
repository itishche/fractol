# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itishche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:48:25 by itishche          #+#    #+#              #
#    Updated: 2019/03/25 10:48:28 by itishche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes
SRC		=	./main.c \
			./minilib.c \
			./help_mouse_key.c \
			./mandelbrot.c \
			./julia_set.c \
			./burning_ship.c \
			./mandelbrot3.c

OBJ = $(SRC:.c=.o)
MLX_DIR	= /Users/tishchenko/minilibx_macos/
MLX_LNK = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) includes/ft_fractol.h
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ)  $(MLX_LNK) -o $(NAME)

clean:
	# make -C $(FT_DIR) clean 
	make -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	# make -C $(FT_DIR) fclean
	rm -f $(NAME)

re: fclean all
