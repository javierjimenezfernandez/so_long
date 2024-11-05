/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:07:16 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/05 18:56:58 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_error_type error_type)
{
	ft_putstr_fd("Error\n", 2);
	if (error_type == wrong_usage)
		ft_putstr_fd("Wrong usage. Try: ./so_long [MAP_FILE]\n", 2);
	if (error_type == map_name_error)
		ft_putstr_fd("Wrong map file name. Extension must be .ber\n", 2);
	if (error_type == open_file_error)
		ft_putstr_fd("Could not open map file.\n", 2);
	if (error_type == malloc_error)
		ft_putstr_fd("Malloc error.\n", 2);
	if (error_type == invalid_map)
		ft_putstr_fd("Invalid map. Check map requirements in subject.\n", 2);
	exit(EXIT_FAILURE);
}
