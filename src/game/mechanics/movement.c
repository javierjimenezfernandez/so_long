/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:12:17 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/29 20:19:53 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keysym, t_coord player_coord, char **map)
{
	int			i;
	int			new_x;
	int			new_y;
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
	new_x = player_coord.x + move_x_axis[i];
	new_y = player_coord.y + move_y_axis[i];
	map[new_y][new_x] = player;
	map[player_coord.y][player_coord.x] = empty;
}

int	is_movement_valid(int keysym, t_coord player_coord, char **map)
{
	int			i;
	int			new_x;
	int			new_y;
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
	new_x = player_coord.x + move_x_axis[i];
	new_y = player_coord.y + move_y_axis[i];
	if (!(map[new_y][new_x] == wall) && ( \
			!(map[new_y][new_x] == exit_tile) || ( \
				(map[new_y][new_x] == exit_tile) && \
				(count_tiles_of_type(map, collectable) == 0))))
		return (1);
	else
		return (0);
}

void	apply_movement(int keysym, t_mlx_data *mlx_data)
{
	t_coord	player_coord;

	player_coord = find_tile_coordinates(mlx_data->map, player);
	if (is_movement_valid(keysym, player_coord, mlx_data->map))
		move_player(keysym, player_coord, mlx_data->map);
	else
		ft_printf("Not a valid movement.\n");
}
