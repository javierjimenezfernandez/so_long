/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tile_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:02:18 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/14 21:37:36 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	select_tile_size(char **map)
{
	if ((2 * TILE_SIZE * (row_len(*(map)) + 2) > SCREEN_RES_WIDTH) \
	|| (2 * TILE_SIZE * (count_map_rows(map) + 10) > SCREEN_RES_HEIGHT))
		return (TILE_SIZE);
	else
		return (2 * TILE_SIZE);
}
