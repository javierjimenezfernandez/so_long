/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:03:12 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/23 13:46:50 by javjimen         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

# define MAP_FILE_EXT ".ber"
# define GAME_NAME "SNORKY scape game"
# define ASSETS_FILE_LIST "assets_file_list.txt"
# define TILE_SIZE 32

typedef enum e_error_type
{
	wrong_usage,
	map_name_error,
	open_file_error,
	malloc_error,
	invalid_map,
	mlx_error,
	open_asset_file_error,
	read_asset_file_error
}			t_error_type;

typedef enum e_tile_type
{
	empty = '0',
	wall = '1',
	collectable = 'C',
	exit_tile = 'E',
	player = 'P',
	row_end = '\n'
}			t_tile_type;

typedef enum e_texture_type
{
	empty_tx,
	wall_tx,
	collectable_tx,
	exit_tile_tx,
	player_tx,
}			t_texture_type;

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	char	**map;
}			t_mlx_data;

/* *************************************************** */
/*                                                     */
/*     ERROR HANDLER                                   */
/*                                                     */
/* *************************************************** */

/*   error_handler    */
void		error_handler(t_error_type error_type);

/* *************************************************** */
/*                                                     */
/*     INPUT CONTROL                                   */
/*                                                     */
/* *************************************************** */

/* ****************** */
/*     FILE UTILS     */
/* ****************** */

/*     file_utils     */
int			is_file_name_valid(char *file_name);
size_t		count_file_lines(char *file_name);

/* ****************** */
/*     MAP UTILS      */
/* ****************** */

/*    map_parsing     */
char		**parse_map(char *file_name);

/*     map_utils      */
size_t		row_len(char *row);
size_t		count_map_rows(char **map);
char		**duplicate_map(char **map);
t_coord		find_tile_coordinates(char **map, char tile);
int			count_tiles_of_type(char **map, char tile);

/*     print_map      */
int			print_map(char **map);

/*      free_map      */
void		free_map(char **map);

/*     on_tile      */
int			on_empty(char tile);
int			on_wall(char tile);
int			on_collectable(char tile);
int			on_exit_tile(char tile);
int			on_player(char tile);

/* ****************** */
/*   MAP VALIDATION   */
/* ****************** */

/* tile_validation  */
int			is_tile_valid(char tile);
int			is_row_valid(char *row, int *coll_count, int *exit_count, \
						int *plyr_count);
int			are_all_tiles_valid(char **map);

/*  size_validation   */
int			are_all_rows_equal_len(char **map);
int			are_dimensions_valid(char **map);

/*  walls_validation  */
int			is_horizontal_border_valid(char *row);
int			is_row_surrounded_by_vertical_walls(char *row);
int			is_surrounded_by_walls(char **map);

/* resolvable_validation */
int			are_collectables_reachable(char **map, char **map_filled_player);
int			is_exit_reachable(char **map, char **map_filled_exit);
void		flood_fill_algorithm(char **map, int x, int y, char fill);
int			is_a_resolvable_map(char **map);

/*   map_validation   */
int			is_map_valid(char **map);

/* *************************************************** */
/*                                                     */
/*     GAME                                            */
/*                                                     */
/* *************************************************** */

/*     start_game     */
int			start_game(char **map);

/* ****************** */
/*      GRAPHICS      */
/* ****************** */

/*   graphics_init    */
int			on_graphics_close_hook(t_mlx_data *mlx_data);
int			on_keypress_hook(int keysym, t_mlx_data *mlx_data);
t_mlx_data	graphics_init(char **map);

/*   load_textures    */
char		*get_asset_file_name(int fd);
void		init_textures_to_null(t_mlx_data *mlx_data);
void		loop_on_texture_files(t_mlx_data *mlx_data, int fd, \
								int *width, int *height);
int			load_textures(t_mlx_data *mlx_data);

/*  render_textures   */
void		*switch_case_textures(t_mlx_data *mlx_data, int x, int y);
void		render_textures(t_mlx_data *mlx_data);

/* ****************** */
/*     MECHANICS      */
/* ****************** */

#endif
