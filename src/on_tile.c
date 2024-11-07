/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:00:51 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 19:49:59 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_empty(char tile)
{
	if (tile == empty)
		return (1);
	else
		return (0);
}

int	on_wall(char tile)
{
	if (tile == wall)
		return (1);
	else
		return (0);
}

int	on_collectable(char tile)
{
	if (tile == collectable)
		return (1);
	else
		return (0);
}

int	on_exit_tile(char tile)
{
	if (tile == exit_tile)
		return (1);
	else
		return (0);
}

int	on_player(char tile)
{
	if (tile == player)
		return (1);
	else
		return (0);
}
