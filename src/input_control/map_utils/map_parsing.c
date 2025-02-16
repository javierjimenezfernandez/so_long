/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:02:14 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/10 19:56:39 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parse_line(int fd)
{
	int			i;
	char		*new_line;
	char		*aux;
	static char	lf_str[2];

	new_line = get_next_line(fd);
	if (!new_line)
		return (NULL);
	i = 0;
	while (new_line[i] != null_char)
	{
		if (new_line[i] == lf_char)
			return (new_line);
		i++;
	}
	lf_str[0] = lf_char;
	lf_str[1] = null_char;
	aux = ft_strjoin(new_line, lf_str);
	free(new_line);
	new_line = aux;
	return (new_line);
}

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
	new_line = parse_line(fd);
	i = 0;
	while (new_line)
	{
		map[i] = new_line;
		new_line = parse_line(fd);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
