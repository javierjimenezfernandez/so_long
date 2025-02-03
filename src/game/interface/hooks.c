/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:11:48 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/03 21:15:30 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_graphics_close_hook(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while ((i <= win_screen_tx) && (mlx_data->textures[i] != NULL))
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
	// ft_printf("Pressed key: %d\n", keysym);
	if (keysym == ESC_KEY)
		on_graphics_close_hook(mlx_data);
	else
	{
		if (mlx_data->game_state != win)
		{
			game_mechanics(keysym, mlx_data);
			render_textures(mlx_data);
		}
		if (mlx_data->game_state == win)
		{
			ft_printf("Please, close the game window or press ESC key.\n");
			render_win_screen(mlx_data);
		}
	}
	return (0);
}
