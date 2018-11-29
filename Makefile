# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: freezee <freezee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2018/11/29 15:27:02 by freezee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

# Sources
SRC				=	fdf.c						\
					srcs/instance.c				\
					srcs/instance_handlers.c

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
CFLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	-I includes -I $(MLX_FOLDER) -I $(LIBFT_FOLDER)/includes

# Linking
OBJ				=	$(SRC:.c=.o)

# Norm
NORM_FILES		=	$(shell find . -type f \( -path minilibx_macos \) -prune -o  -name "*.c" -o -name "*.h")

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	$(CXX) -o $(NAME) $(OBJ) $(LIB_FOLDERS) $(LIBS) $(LDFLAGS)

.c.o: $(SRC)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	$(CXX) -c $< -o $@ $(INCLUDES) $(CFLAGS)

norm:
	@printf "\033[32mNorminette:\033[0m "
	@if ! norminette $(NORM_FILES) | grep -sB1 -E "Error|Warning";then echo "\033[0mEvery file is following the norm";fi

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
	@printf "\033[32m  Cleaning: \033[0m"
	@find . -name "*.o" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(OBJ)

fclean: clean libft-fclean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "$(NAME)" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(NAME)
	@rm -rf $(MLX_FOLDER)/libmlx.a

re: fclean libft-re mlx-re all

.PHONY: all $(NAME) norm libft libft-clean libft-fclean libft-re mlx mlx-clean mlx-re clean fclean re