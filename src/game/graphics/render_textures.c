/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:37:35 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/16 17:33:18 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*switch_case_textures(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x] == empty)
		return (mlx_data->textures[empty_tx]);
	else if (mlx_data->map[y][x] == wall)
		return (mlx_data->textures[wall_tx]);
	else if (mlx_data->map[y][x] == collectable)
		return (mlx_data->textures[collectable_tx]);
	else if (mlx_data->map[y][x] == exit_tile)
	{
		if (mlx_data->game_state == exit_open)
			return (mlx_data->textures[exit_open_tx]);
		else
			return (mlx_data->textures[exit_closed_tx]);
	}
	else if (mlx_data->map[y][x] == player)
		return (mlx_data->textures[player_tx]);
	else
		return (NULL);
}

void	render_textures(t_mlx_data *mlx_data)
{
	int		x;
	int		y;
	int		tile_size;
	void	*texture;

	x = 0;
	y = 0;
	tile_size = select_tile_size(mlx_data->map);
	while ((mlx_data->map[y] != NULL) && (mlx_data->map[y][0] != lf_char))
	{
		x = 0;
		while (mlx_data->map[y][x] != lf_char)
		{
			texture = switch_case_textures(mlx_data, x, y);
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
									texture, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}

void	render_win_screen(t_mlx_data *mlx_data)
{
	int		tile_size;
	int		width;
	int		height;

	tile_size = select_tile_size(mlx_data->map);
	width = 2.5 * tile_size;
	height = 2 * tile_size;
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
		mlx_data->textures[win_screen_tx], \
		(row_len(*(mlx_data->map)) * tile_size - width) / 2, \
		(count_map_rows(mlx_data->map) * tile_size - height) / 2);
}
