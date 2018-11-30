# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2018/11/30 17:12:47 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

# Sources
SRC				=	fdf.c						\
					srcs/camera.c				\
					srcs/draw.c					\
					srcs/instance_handlers.c	\
					srcs/instance.c				\
					srcs/mesh.c					\
					srcs/renderer.c

UNAME			=	$(shell uname)

LIBFT_FOLDER	=	libft

ifeq ($(UNAME), Linux)
MLX_FOLDER		=	minilibx
LIB_FOLDERS		=	-L$(MLX_FOLDER) -L$(LIBFT_FOLDER) -L/usr/X11/lib
LIBS			=	-lmlx -lft -lXext -lX11 -lm
LDFLAGS			=
else
MLX_FOLDER		=	minilibx_macos
LIB_FOLDERS		=	-L$(MLX_FOLDER) -L$(LIBFT_FOLDER)
LIBS			=	-lmlx -lft
LDFLAGS			=	-framework OpenGL -framework AppKit
endif

# Compilation
CXX				=	cc
CFLAGS			=	-Wall -Wextra -Werror -O3
INCLUDES		=	-I includes -I $(MLX_FOLDER) -I $(LIBFT_FOLDER)/includes

# Linking
OBJ				=	$(SRC:.c=.o)

# Norm
NORM_FILES		=	$(shell find . -type f \( -path minilibx_macos \) \
	-prune -o -name "*.c" -o -name "*.h")

# Colors
GREEN			=	\033[32m
RESET			=	\033[0m

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[ld]$(RESET): $(NAME)\n"
	$(CXX) -o $(NAME) $(OBJ) $(LIB_FOLDERS) $(LIBS) $(LDFLAGS) $(INCLUDES)

.c.o: $(SRC)
	@printf "$(GREEN)[cc]$(RESET): $< -> $@\n"
	@$(CXX) -c $< -o $@ $(INCLUDES) $(CFLAGS)

run: all
	@./$(NAME)

norm:
	@printf "$(GREEN)Norminette: $(RESET)"
	@if ! norminette $(NORM_FILES) | grep -sB1 -E "Error|Warning"; then \
		echo "$(RESET)Every file is following the norm";fi

libft:
	@make -C libft

libft-clean:
	@make -C $(LIBFT_FOLDER) clean

libft-fclean:
	@make -C $(LIBFT_FOLDER) fclean

libft-re:
	@make -C $(LIBFT_FOLDER) re

mlx:
	@make -C $(MLX_FOLDER)

mlx-clean:
	@make -C $(MLX_FOLDER) clean

mlx-re:
	@make -C $(MLX_FOLDER) re

clean: libft-clean mlx-clean
	@printf "$(GREEN)[rm]$(RESET): "
	@find . -name "*.o" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(OBJ)

fclean: clean libft-fclean
	@printf "$(GREEN)[rm]$(RESET): "
	@find . -name "$(NAME)" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(NAME)
	@rm -rf $(MLX_FOLDER)/libmlx.a

re: fclean libft-re mlx-re all

.PHONY: all $(NAME) norm libft libft-clean libft-fclean libft-re mlx mlx-clean \
	mlx-re clean fclean re
