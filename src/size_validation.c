/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:08:57 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 17:57:16 by javjimen         ###   ########.fr       */
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
