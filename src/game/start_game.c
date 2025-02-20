/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:08:13 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/12 19:38:49 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char **map)
{
	t_mlx_data	mlx_data;

	graphics_init(&mlx_data, map);
	mlx_hook(mlx_data.win_ptr, KeyRelease, KeyReleaseMask, \
				&on_keypress_hook, &mlx_data);
	mlx_hook(mlx_data.win_ptr, DestroyNotify, StructureNotifyMask, \
				&on_graphics_close_hook, &mlx_data);
	mlx_data.game_state = started;
	mlx_loop(mlx_data.mlx_ptr);
}
