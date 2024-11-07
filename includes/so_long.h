/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:03:12 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 17:55:41 by javjimen         ###   ########.fr       */
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

/* ****************** */
/*       UTILS        */
/* ****************** */

/*   error_handler    */
void	error_handler(t_error_type error_type);

/*     file_utils     */
int		is_file_name_valid(char *file_name);
size_t	count_file_lines(char *file_name);

/*     print_map      */
void	print_map(char **map);

/*      free_map      */
void	free_map(char **map);

/*     on_tile      */
int		on_empty(char c);
int		on_wall(char c);
int		on_collectable(char c);
int		on_exit_tile(char c);
int		on_player(char c);

/* ****************** */
/*        MAP         */
/* ****************** */

/*    map_parsing     */
char	**parse_map(char *file_name);

/* tile_validation  */
int		is_tile_valid(char c);
int		is_row_valid(char *row, int *coll_count, int *exit_count, \
						int *plyr_count);
int		are_all_tiles_valid(char **map);

/*  size_validation   */
size_t	row_len(char *row);
size_t	count_map_rows(char **map);
int		are_all_rows_equal_len(char **map);
int		are_dimensions_valid(char **map);

/*   map_validation   */
int		is_map_valid(char **map);

#endif
