/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:12:17 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/01 20:58:31 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tile_interaction_msg(int is_movement_valid, t_tile_type new_tile, \
								int coll_count)
{
	if (is_movement_valid)
	{
		if (on_collectable(new_tile))
		{
			ft_printf("Congratulations! You picked up a collectable!\n");
			if (--coll_count)
				ft_printf("There are still %d collectables.\n", coll_count);
			else
				ft_printf("Everything collected you can go to the exit.\n");
		}
		else if (on_exit_tile(new_tile))
			ft_printf("Congratulations! You won in ");
	}
	else
	{
		ft_printf("Not a valid movement. ");
		if (on_wall(new_tile))
			ft_printf("You can't go through the wall.\n");
		else if (on_exit_tile(new_tile))
		{
			ft_printf("You still need to collect %d ", coll_count);
			ft_printf("collectables to reach the exit.\n");
		}
	}
}

t_coord	movement_logic(int keysym, t_coord player_coord)
{
	int			i;
	t_coord		new_coord;
	const int	move_x_axis[4] = {0, -1, 0, 1};
	const int	move_y_axis[4] = {-1, 0, 1, 0};

	if ((keysym == W_KEY) || (keysym == UP_KEY))
		i = 0;
	else if ((keysym == A_KEY) || (keysym == LEFT_KEY))
		i = 1;
	else if ((keysym == S_KEY) || (keysym == DOWN_KEY))
		i = 2;
	else
		i = 3;
	new_coord.x = player_coord.x + move_x_axis[i];
	new_coord.y = player_coord.y + move_y_axis[i];
	return (new_coord);
}

int	is_movement_valid(t_tile_type new_tile, int coll_count)
{
	if (!on_wall(new_tile) && \
		(!on_exit_tile(new_tile) || \
			(on_exit_tile(new_tile) && coll_count == 0)))
		return (1);
	else
		return (0);
}

void	apply_movement(int keysym, t_mlx_data *mlx_data)
{
	t_coord		player_coord;
	int			coll_count;
	t_coord		new_coord;
	t_tile_type	new_tile;

	player_coord = find_tile_coordinates(mlx_data->map, player);
	coll_count = count_tiles_of_type(mlx_data->map, collectable);
	new_coord = movement_logic(keysym, player_coord);
	new_tile = (mlx_data->map)[new_coord.y][new_coord.x];
	if (is_movement_valid(new_tile, coll_count))
	{
		if (on_collectable(new_tile) || on_exit_tile(new_tile))
			tile_interaction_msg(1, new_tile, coll_count);
		(mlx_data->map)[new_coord.y][new_coord.x] = player;
		(mlx_data->map)[player_coord.y][player_coord.x] = empty;
		(mlx_data->mvmnt_count)++;
		ft_printf("Movement number: %d\n", mlx_data->mvmnt_count);
		if (on_exit_tile(new_tile))
			mlx_data->game_state = win;
	}
	else
		tile_interaction_msg(0, new_tile, coll_count);
}
