/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:00:51 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 17:38:17 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_empty(char c)
{
	if (c == '0')
		return (1);
	else
		return (0);
}

int	on_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	on_collectable(char c)
{
	if (c == 'C')
		return (1);
	else
		return (0);
}

int	on_exit_tile(char c)
{
	if (c == 'E')
		return (1);
	else
		return (0);
}

int	on_player(char c)
{
	if (c == 'P')
		return (1);
	else
		return (0);
}
