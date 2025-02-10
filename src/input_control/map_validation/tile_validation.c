/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:56:27 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/10 19:23:22 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_tile_valid(char tile)
{
	if (on_empty(tile) \
		|| on_wall(tile) \
		|| on_collectable(tile) \
		|| on_exit_tile(tile) \
		|| on_player(tile))
		return (1);
	else
		return (0);
}

int	is_row_valid(char *row, int *coll_count, int *exit_count, int *plyr_count)
{
	size_t	i;

	i = 0;
	while ((row[i] != lf_char) && (row[i] != null_char))
	{
		if (is_tile_valid(row[i]))
		{
			*coll_count += on_collectable(row[i]);
			*exit_count += on_exit_tile(row[i]);
			*plyr_count += on_player(row[i]);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	are_all_tiles_valid(char **map)
{
	int	coll_count;
	int	exit_count;
	int	plyr_count;

	coll_count = 0;
	exit_count = 0;
	plyr_count = 0;
	while (*map != NULL)
	{
		if (!is_row_valid(*map, &coll_count, &exit_count, &plyr_count))
			return (0);
		map++;
	}
	if ((coll_count >= 1) && (exit_count == 1) && (plyr_count == 1))
		return (1);
	else
		return (0);
}
