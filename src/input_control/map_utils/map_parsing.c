/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:02:14 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/05 21:29:01 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *file_name)
{
	size_t	i;
	int		fd;
	char	*new_line;
	char	**map;

	map = (char **)malloc((count_file_lines(file_name) + 1) * sizeof(char *));
	if (!map)
		error_handler(malloc_error);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		error_handler(open_file_error);
	}
	new_line = get_next_line(fd);
	i = 0;
	while (new_line)
	{
		map[i] = new_line;
		new_line = get_next_line(fd);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
