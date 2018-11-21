# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2018/11/21 19:49:06 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

# Sources
SRC			=	main.c				\
				srcs/instance.c		\
				srcs/pos.c
MLX_FOLDER	=	minilibx_macos

# Compilation
CXX			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I includes -I $(MLX_FOLDER)

# Linking
OBJ			=	$(SRC:.c=.o)
MLX			=	$(MLX_FOLDER)/libmlx.a
LDFLAGS		=	-framework OpenGL -framework AppKit

# Norm
NORM_FILES	=	$(shell find . -name "*.c" -o -name "*.h")

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	@$(CXX) -o $(NAME) $(OBJ) $(MLX) $(LDFLAGS)

.c.o: $(SRC)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	@$(CXX) -c $< -o $@ $(INCLUDES) $(CFLAGS)

norm:
	@printf "\033[32mNorminette:\033[0m "
	@if ! norminette $(NORM_FILES) | grep -sB1 -E "Error|Warning";then echo "\033[0mEvery file is following the norm";fi

clean:
	@printf "\033[32m  Cleaning: \033[0m"
	@find . -name "*.o" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(OBJ)

fclean: clean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "$(NAME)" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(NAME)

re: fclean all
