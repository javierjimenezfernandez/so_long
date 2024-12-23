/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:03:00 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/01 20:29:15 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		error_handler(wrong_usage);
	if (is_file_name_valid(argv[1]))
		map = parse_map(argv[1]);
	else
	{
		error_handler(map_name_error);
		return (1);
	}
	if (is_map_valid(map))
		print_map(map);
	else
	{
		free_map(map);
		error_handler(invalid_map);
		return (1);
	}
	start_game(map);
	free_map(map);
	return (0);
}
