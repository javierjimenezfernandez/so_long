# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 20:31:03 by javjimen          #+#    #+#              #
#    Updated: 2025/02/14 21:32:23 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= so_long


# Operating system name
UNAME		= $(shell uname)


# Dependancies
INCLUDES	= -Iincludes -Ilibft/includes
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
SRC			= $(addprefix $(SRC_DIR), main.c \
									  error_handler/error_handler.c \
									  input_control/file_utils/file_utils.c \
									  input_control/map_utils/map_parsing.c \
									  input_control/map_utils/map_utils.c \
									  input_control/map_utils/print_map.c \
									  input_control/map_utils/free_map.c \
									  input_control/map_utils/on_tile.c \
									  input_control/map_validation/tile_validation.c \
									  input_control/map_validation/size_validation.c \
									  input_control/map_validation/walls_validation.c \
									  input_control/map_validation/resolvable_validation.c \
									  input_control/map_validation/map_validation.c \
									  game/start_game.c \
									  game/graphics/graphics_init.c \
									  game/graphics/load_textures.c \
									  game/graphics/render_textures.c \
									  game/graphics/select_tile_size.c \
									  game/interface/hooks.c \
									  game/mechanics/game_mechanics.c \
									  game/mechanics/movement.c)


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

DEBUG_FLAGS	= -I includes -Og

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
			$(CC) $(DEBUG_FLAGS) -c $< -o $@ $(INCLUDES)

clean:
			make -C $(LIBFT_DIR) clean
			make -C $(MLX_DIR) clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_$(UNAME).a
			$(RM) $(NAME)

re:			fclean all

sanitize:	$(LIBFT) $(MLX_LIB) $(OBJ) $(INC)
			$(CC) $(SANITIZE) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_FLAGS)
