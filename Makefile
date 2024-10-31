# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 20:31:03 by javjimen          #+#    #+#              #
#    Updated: 2024/10/31 20:47:17 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= so_long


# Operating system name
UNAME		= $(shell uname)


# Dependancies
INCLUDES	= -I includes -I libft/includes
ifeq ($(shell uname), Linux)
	INCLUDES += -I/usr/include -Imlx
else
	INCLUDES += -I/opt/X11/include -Imlx
endif

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= ./mlx
MLX_LIB		= $(MLX_DIR)/libmlx_$(UNAME).a


# List of source files
SRC_DIR		= src/
SRC			= $(addprefix $(SRC_DIR), main.c)


# List of object files
OBJ_DIR		= obj/
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


# List of header files
INC_DIR		= includes/
INC			= $(addprefix includes/, so_long.h)


# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror
ARFLAGS		= -r -c -s

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

SANITIZE	= $(CFLAGS) -fsanitize=address


# Rule name protection
.PHONY:		all libft clean fclean re sanitize

all: 		$(NAME)


# Make rules
$(NAME):	$(LIBFT) $(MLX_LIB) $(OBJ) $(INC)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_FLAGS)

$(LIBFT):
			make -C $(LIBFT_DIR) all

$(MLX_LIB):
			make -C $(MLX_DIR) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			make -C $(LIBFT_DIR) clean
			make -C $(MLX_DIR) clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_$(UNAME).a
			$(RM) $(NAME)

re:			fclean all

sanitize:	$(LIBFT) $(OBJ) $(INC)
			$(CC) $(SANITIZE) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_FLAGS)
