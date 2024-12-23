/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:37:35 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/23 13:46:35 by javjimen         ###   ########.fr       */
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
		return (mlx_data->textures[exit_tile_tx]);
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
