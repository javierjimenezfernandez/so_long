/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:00:51 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/07 17:53:11 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_empty(char c)
{
	if (c == empty)
		return (1);
	else
		return (0);
}

int	on_wall(char c)
{
	if (c == wall)
		return (1);
	else
		return (0);
}

int	on_collectable(char c)
{
	if (c == collectable)
		return (1);
	else
		return (0);
}

int	on_exit_tile(char c)
{
	if (c == exit_tile)
		return (1);
	else
		return (0);
}

int	on_player(char c)
{
	if (c == player)
		return (1);
	else
		return (0);
}
