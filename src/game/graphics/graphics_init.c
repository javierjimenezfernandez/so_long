/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:22:21 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/14 21:37:57 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphics_init(t_mlx_data *mlx_data, char **map)
{
	int	tile_size;

	tile_size = select_tile_size(map);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
		free_map(map);
		error_handler(mlx_error);
	}
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, \
		row_len(*map) * tile_size, count_map_rows(map) * tile_size, GAME_NAME);
	if (!mlx_data->win_ptr)
	{
		free_map(map);
		free(mlx_data->mlx_ptr);
		error_handler(mlx_error);
	}
	mlx_data->map = map;
	mlx_data->coll_count = count_tiles_of_type(mlx_data->map, collectable);
	mlx_data->mvmnt_count = 0;
	mlx_data->game_state = not_started;
	load_textures(mlx_data);
	render_textures(mlx_data);
}
