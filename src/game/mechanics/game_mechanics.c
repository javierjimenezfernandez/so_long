/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:56:24 by javjimen          #+#    #+#             */
/*   Updated: 2025/01/20 21:52:18 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_movement_key(int keysym)
{
	if ((keysym == UP_KEY) || \
		(keysym == LEFT_KEY) || \
		(keysym == DOWN_KEY) || \
		(keysym == RIGHT_KEY) || \
		(keysym == W_KEY) || \
		(keysym == A_KEY) || \
		(keysym == S_KEY) || \
		(keysym == D_KEY))
		return (1);
	else
		return (0);
}

void	game_mechanics(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == ESC_KEY)
		on_graphics_close_hook(mlx_data);
	else if (is_movement_key(keysym))
		apply_movement(keysym, mlx_data);
	else
		ft_printf("Not a valid key.\n");
}
