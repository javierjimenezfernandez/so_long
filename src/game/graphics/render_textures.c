/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:37:35 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/06 22:12:59 by javjimen         ###   ########.fr       */
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
	void	*texture;

	x = 0;
	y = 0;
	while ((mlx_data->map[y] != NULL) && (mlx_data->map[y][0] != row_end))
	{
		x = 0;
		while (mlx_data->map[y][x] != row_end)
		{
			texture = switch_case_textures(mlx_data, x, y);
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
									texture, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_win_screen(t_mlx_data *mlx_data)
{
	int		width;
	int		height;
	char	*file_name;

	file_name = "assets/win_screen/win_screen.xpm";
	width = 2.5 * TILE_SIZE;
	height = 2 * TILE_SIZE;
	mlx_data->textures[win_screen_tx] = \
		mlx_xpm_file_to_image(mlx_data->mlx_ptr, file_name, &width, &height);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
		mlx_data->textures[win_screen_tx], \
		(row_len(*(mlx_data->map)) * TILE_SIZE - width) / 2, \
		(count_map_rows(mlx_data->map) * TILE_SIZE - height) / 2);
}
