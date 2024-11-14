/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:50 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 20:24:43 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	row_len(char *row)
{
	size_t	len;

	len = 0;
	while (row[len] != row_end)
	{
		len++;
	}
	return (len);
}

size_t	count_map_rows(char **map)
{
	size_t	row_count;

	row_count = 0;
	while (map[row_count] != NULL)
		row_count++;
	if (map[row_count - 1][0] == row_end)
		row_count--;
	return (row_count);
}

char	**duplicate_map(char **map)
{
	int		i;
	char	**map_dup;

	map_dup = (char **)malloc((count_map_rows(map) + 1) * sizeof(char *));
	if (!map_dup)
	{
		free_map(map);
		error_handler(malloc_error);
	}
	i = 0;
	while (map[i] != NULL && map[i][0] != row_end)
	{
		map_dup[i] = ft_strdup(map[i]);
		if (!map_dup[i])
		{
			free_map(map);
			free_map(map_dup);
			error_handler(malloc_error);
		}
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}

t_coord	find_tile_coordinates(char **map, char tile)
{
	t_coord	coord;

	coord.y = 0;
	while (map[coord.y] != NULL)
	{
		coord.x = 0;
		while (map[coord.y][coord.x] != row_end)
		{
			if (map[coord.y][coord.x] == tile)
				return (coord);
			coord.x++;
		}
		coord.y++;
	}
	coord.x = -1;
	coord.y = -1;
	return (coord);
}

int	count_tiles_of_type(char **map, char tile)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != row_end)
		{
			if (map[i][j] == tile)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
