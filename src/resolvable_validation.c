/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvable_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:49:27 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 21:45:29 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_collectables_reachable(char **map, char **map_filled_player)
{
	int	coll_count;
	int	i;
	int	j;

	coll_count = 0;
	i = 0;
	while (map_filled_player[i] != NULL)
	{
		j = 0;
		while (map_filled_player[i][j] != row_end)
		{
			if (map[i][j] == collectable && map_filled_player[i][j] == player)
				coll_count++;
			j++;
		}
		i++;
	}
	if (coll_count == count_tiles_of_type(map, collectable))
		return (1);
	return (0);
}

int	is_exit_reachable(char **map, char **map_filled_exit)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (map_filled_exit[i] != NULL)
	{
		j = 0;
		while (map_filled_exit[i][j] != row_end)
		{
			if (map[i][j] == player && map_filled_exit[i][j] == exit_tile)
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count == 1)
		return (1);
	return (0);
}

void	flood_fill_algorithm(char **map, int x, int y, char fill)
{
	int			i;
	int			new_x;
	int			new_y;
	const int	move_x_axis[4] = {0, 0, -1, 1};
	const int	move_y_axis[4] = {-1, 1, 0, 0};

	map[y][x] = fill;
	i = 0;
	while (i < 4)
	{
		new_x = x + move_x_axis[i];
		new_y = y + move_y_axis[i];
		if (!(map[new_y][new_x] == wall) && \
			!(map[new_y][new_x] == exit_tile) && \
			!(map[new_y][new_x] == fill))
			flood_fill_algorithm(map, new_x, new_y, fill);
		i++;
	}
}

int	is_a_resolvable_map(char **map)
{
	char	**map_filled_player;
	char	**map_filled_exit;
	t_coord	coord;

	map_filled_player = duplicate_map(map);
	coord = find_tile_coordinates(map_filled_player, player);
	flood_fill_algorithm(map_filled_player, coord.x, coord.y, player);
	map_filled_exit = duplicate_map(map);
	coord = find_tile_coordinates(map_filled_exit, exit_tile);
	flood_fill_algorithm(map_filled_exit, coord.x, coord.y, exit_tile);
	if (are_collectables_reachable(map, map_filled_player) && \
		is_exit_reachable(map, map_filled_exit))
	{
		free_map(map_filled_player);
		free_map(map_filled_exit);
		return (1);
	}
	free_map(map_filled_player);
	free_map(map_filled_exit);
	return (0);
}
