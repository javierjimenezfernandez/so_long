/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:35:13 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/18 21:35:01 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* implement printf error handling */

int	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (ft_printf(map[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
