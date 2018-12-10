# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: freezee <freezee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2018/12/07 23:09:03 by freezee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

# Sources
SRC				=	fdf.c						\
					srcs/camera.c				\
					srcs/draw.c					\
					srcs/errors.c				\
					srcs/instance_handlers.c	\
					srcs/instance.c				\
					srcs/mesh.c					\
					srcs/parser.c				\
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

# Colors
GREEN			=	\033[32m
RESET			=	\033[0m

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[cc]$(RESET): done\n"
	@printf "$(GREEN)[ld]$(RESET): $(NAME)\n"
	@$(CXX) -o $(NAME) $(OBJ) $(LIB_FOLDERS) $(LIBS) $(LDFLAGS) $(INCLUDES)

.c.o: $(SRC)
	@printf "$(GREEN)[cc]$(RESET): $< -> $@\n"
	@echo -en "\e[1A"
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@echo -en "\e[0K"

run: all
	@./$(NAME)

libft:
	@printf "$(GREEN)[mk]$(RESET): libft all\n";
	@make -C libft >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

libft-clean:
	@printf "$(GREEN)[mk]$(RESET): libft clean\n";
	@make -C $(LIBFT_FOLDER) clean >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

libft-fclean:
	@printf "$(GREEN)[mk]$(RESET): libft fclean\n";
	@make -C $(LIBFT_FOLDER) fclean >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

libft-re:
	@printf "$(GREEN)[mk]$(RESET): libft re\n";
	@make -C $(LIBFT_FOLDER) re >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

mlx:
	@printf "$(GREEN)[mk]$(RESET): mlx all\n";
	@make -C $(MLX_FOLDER) >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

mlx-clean:
	@printf "$(GREEN)[mk]$(RESET): mlx clean\n";
	@make -C $(MLX_FOLDER) clean >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

mlx-fclean: mlx-clean
	@printf "$(GREEN)[mk]$(RESET): mlx fclean\n";
	@rm -rf $(MLX_FOLDER)/libmlx.a
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

mlx-re:
	@printf "$(GREEN)[mk]$(RESET): mlx re\n";
	@make -C $(MLX_FOLDER) re >/dev/null
	@echo -en "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): done\n";

clean: libft-clean mlx-clean
	@printf "$(GREEN)[rm]$(RESET): object files\n"
	@rm -rf $(OBJ)

fclean: clean libft-fclean mlx-fclean
	@printf "$(GREEN)[rm]$(RESET): binary file\n"
	@rm -rf $(NAME)

re: fclean libft-re mlx-re all

.PHONY: all $(NAME) norm libft libft-clean libft-fclean libft-re mlx mlx-clean \
	mlx-fclean mlx-re clean fclean re
