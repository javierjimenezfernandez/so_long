/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:22:21 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/18 21:14:02 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_graphics_close_hook(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while ((i < 5) && (mlx_data->textures[i] != NULL))
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->textures[i]);
		i++;
	}
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	free_map(mlx_data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	on_keypress_hook(int keysym, t_mlx_data *mlx_data)
{
	(void)mlx_data;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

t_mlx_data	graphics_init(char **map)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
	{
		free_map(map);
		error_handler(mlx_error);
	}
	mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, \
		row_len(*map) * TILE_SIZE, count_map_rows(map) * TILE_SIZE, GAME_NAME);
	if (!mlx_data.win_ptr)
	{
		free_map(map);
		free(mlx_data.mlx_ptr);
		error_handler(mlx_error);
	}
	mlx_data.map = map;
	load_textures(&mlx_data);
	render_textures(&mlx_data);
	mlx_hook(mlx_data.win_ptr, KeyRelease, KeyReleaseMask, \
				&on_keypress_hook, &mlx_data);
	mlx_hook(mlx_data.win_ptr, DestroyNotify, StructureNotifyMask, \
				&on_graphics_close_hook, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	return (mlx_data);
}
