/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:59 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/05 21:02:22 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_file_name_valid(char *file_name)
{
	size_t	name_len;
	size_t	ext_len;
	char	*ext_found;

	name_len = ft_strlen(file_name);
	ext_len = ft_strlen(MAP_FILE_EXT);
	ext_found = ft_strnstr(file_name, MAP_FILE_EXT, name_len);
	if (!ext_found)
		return (0);
	if ((ext_found - file_name) == (long int)(name_len - ext_len) && \
		(ext_found - file_name) != 0)
		return (1);
	else
		return (0);
}

size_t	count_file_lines(char *file_name)
{
	int		fd;
	size_t	count;
	char	*new_line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(open_file_error);
	count = 0;
	new_line = get_next_line(fd);
	while (new_line)
	{
		count++;
		free(new_line);
		new_line = get_next_line(fd);
	}
	free(new_line);
	close(fd);
	return (count);
}
