/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:08:13 by javjimen          #+#    #+#             */
/*   Updated: 2025/01/20 21:57:31 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* find how mlx loop work and how could continuous rendering and mechanics
	implementation could be done. */

int	start_game(char **map)
{
	t_mlx_data	mlx_data;

	mlx_data = graphics_init(map);
	//graphics_init(map);
	//mechanics_init();
	//render_textures(&mlx_data);
	return (0);
}
