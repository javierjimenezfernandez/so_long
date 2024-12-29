/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:11:48 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/29 19:14:18 by javjimen         ###   ########.fr       */
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
