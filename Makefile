# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majrou <majrou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 20:01:57 by majrou            #+#    #+#              #
#    Updated: 2023/10/25 22:53:01 by majrou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = CUB3D
SRC = main.c parse.c parse_color.c parse_texteur.c error.c raycasting/cub3d.c raycasting/draw_things.c raycasting/rays_logic.c raycasting/texteur.c
CC = cc
CFLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
libft = libft/libft.a
HEADER = cub3d.h
RM = rm -rf

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJ)
		@$(MAKE) -C libft all
		 @$(CC) $(libft) $(OBJ) -o $(NAME) mlx/libmlx42.a -Iinclude -lglfw -L"/Users/majrou/goinfre/homebrew/opt/glfw/lib" -fsanitize=address
		@echo "Compiling up..."

clean :
		@rm -rf $(OBJ)
		@$(MAKE) clean -C libft
		@echo "Cleaning up..."

fclean : clean
		@rm -rf  $(NAME)
		@$(MAKE) fclean -C libft
		@echo "Full cleaning up..."

re : fclean all

.PHONY : all fclean clean re
