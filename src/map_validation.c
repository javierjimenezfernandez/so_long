/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:14:54 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/05 21:58:21 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_valid(char **map)
{
	if (are_all_tiles_valid(map) && are_dimensions_valid(map))
		return (1);
	else
		return (0);
}
