/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:08:57 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/14 22:30:46 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_all_rows_equal_len(char **map)
{
	size_t	i;
	size_t	len;
	size_t	rows;

	len = row_len(map[0]);
	rows = count_map_rows(map);
	i = 1;
	while (i < rows)
	{
		if (len != row_len(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	are_dimensions_valid(char **map)
{
	size_t	cols;
	size_t	rows;

	if (are_all_rows_equal_len(map))
	{
		rows = count_map_rows(map);
		cols = row_len(map[0]);
		if ((rows >= 3 && cols >= 5) || (rows >= 5 && cols >= 3))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	is_the_map_too_big(char **map)
{
	if ((TILE_SIZE * (row_len(*(map)) + 2) > SCREEN_RES_WIDTH) \
	|| (TILE_SIZE * (count_map_rows(map) + 10) > SCREEN_RES_HEIGHT))
		return (1);
	else
		return (0);
}
