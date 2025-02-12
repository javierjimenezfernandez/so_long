/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:03:00 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/12 19:10:56 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		error_handler(wrong_usage);
	if (is_file_name_valid(argv[1]))
	{
		map = parse_map(argv[1]);
		if (!is_map_valid(map))
		{
			free_map(map);
			error_handler(invalid_map);
		}
		start_game(map);
		free_map(map);
	}
	else
		error_handler(map_name_error);
	return (0);
}
