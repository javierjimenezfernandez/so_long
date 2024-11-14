/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:49:27 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 17:56:12 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_horizontal_border_valid(char *row)
{
	while (*row != row_end)
	{
		if (!on_wall(*row))
			return (0);
		row++;
	}
	return (1);
}

int	is_row_surrounded_by_vertical_walls(char *row)
{
	if (!on_wall(*row))
		return (0);
	while (*row != row_end)
		row++;
	row--;
	if (!on_wall(*row))
		return (0);
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int	i;

	i = count_map_rows(map) - 1;
	if (!is_horizontal_border_valid(map[i]))
		return (0);
	while (i > 0)
	{
		if (!is_row_surrounded_by_vertical_walls(map[i]))
			return (0);
		i--;
	}
	if (!is_horizontal_border_valid(map[i]))
		return (0);
	return (1);
}
