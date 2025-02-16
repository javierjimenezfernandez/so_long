/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:45:07 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/05 14:46:02 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	line_count;

	line_count = 0;
	while (map[line_count] != NULL)
		line_count++;
	line_count--;
	while (line_count >= 0)
	{
		free(map[line_count]);
		line_count--;
	}
	free(map);
}
