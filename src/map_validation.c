/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:14:54 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 21:47:32 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_valid(char **map)
{
	if (are_all_tiles_valid(map) && \
		are_dimensions_valid(map) && \
		is_surrounded_by_walls(map) && \
		is_a_resolvable_map(map))
		return (1);
	else
		return (0);
}
