/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:07:16 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/03 20:44:48 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_error_type error_type)
{
	ft_putstr_fd("Error\n", 2);
	if (error_type == wrong_usage)
		ft_putstr_fd("Wrong usage. Try: ./so_long [MAP_FILE]\n", 2);
	else if (error_type == map_name_error)
		ft_putstr_fd("Wrong map file name. Extension must be .ber\n", 2);
	else if (error_type == open_file_error)
		ft_putstr_fd("Could not open map file.\n", 2);
	else if (error_type == malloc_error)
		ft_putstr_fd("Malloc error.\n", 2);
	else if (error_type == invalid_map)
		ft_putstr_fd("Invalid map. Check map requirements in subject.\n", 2);
	exit(EXIT_FAILURE);
}

void	in_game_error_handler(t_error_type error_type, char *error_info)
{
	ft_putstr_fd("Error\n", 2);
	if (error_type == mlx_error)
		ft_putstr_fd("MLX graphics failed.\n", 2);
	else if (error_type == open_asset_file_error)
		ft_putstr_fd("Could not open: ", 2);
	else if (error_type == read_asset_file_error)
		ft_putstr_fd("Could not read: ", 2);
	else if (error_type == open_current_asset_file_error)
		ft_putstr_fd("Could not open the asset file: ", 2);
	ft_putstr_fd("\"", 2);
	ft_putstr_fd(error_info, 2);
	ft_putstr_fd("\"\n", 2);
}
