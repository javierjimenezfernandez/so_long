/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:03:12 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 20:24:56 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define MAP_FILE_EXT ".ber"

typedef enum e_error_type
{
	wrong_usage,
	map_name_error,
	open_file_error,
	malloc_error,
	invalid_map
}		t_error_type;

typedef enum e_tile_type
{
	empty = '0',
	wall = '1',
	collectable = 'C',
	exit_tile = 'E',
	player = 'P',
	row_end = '\n'
}		t_tile_type;

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

/* ****************** */
/*       UTILS        */
/* ****************** */

/*   error_handler    */
void	error_handler(t_error_type error_type);

/*     file_utils     */
int		is_file_name_valid(char *file_name);
size_t	count_file_lines(char *file_name);

/* ****************** */
/*        MAP         */
/* ****************** */

/*    map_parsing     */
char	**parse_map(char *file_name);

/*     map_utils      */
size_t	row_len(char *row);
size_t	count_map_rows(char **map);
char	**duplicate_map(char **map);
t_coord	find_tile_coordinates(char **map, char tile);
int		count_tiles_of_type(char **map, char tile);

/*     print_map      */
void	print_map(char **map);

/*      free_map      */
void	free_map(char **map);

/*     on_tile      */
int		on_empty(char tile);
int		on_wall(char tile);
int		on_collectable(char tile);
int		on_exit_tile(char tile);
int		on_player(char tile);

/* tile_validation  */
int		is_tile_valid(char tile);
int		is_row_valid(char *row, int *coll_count, int *exit_count, \
						int *plyr_count);
int		are_all_tiles_valid(char **map);

/*  size_validation   */
int		are_all_rows_equal_len(char **map);
int		are_dimensions_valid(char **map);

/*  walls_validation  */
int		is_horizontal_border_valid(char *row);
int		is_row_surrounded_by_vertical_walls(char *row);
int		is_surrounded_by_walls(char **map);

/* resolvable_validation */
int		are_collectables_reachable(char **map, char **map_filled_player);
int		is_exit_reachable(char **map, char **map_filled_exit);
void	flood_fill_algorithm(char **map, int x, int y, char fill);
int		is_a_resolvable_map(char **map);

/*   map_validation   */
int		is_map_valid(char **map);

#endif
