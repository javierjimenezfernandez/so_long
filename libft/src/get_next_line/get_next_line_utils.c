/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/11/01 15:11:03 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_findeol(char *line, char **eol)
{
	size_t	i;

	i = 0;
	*eol = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			*eol = &line[i];
			break ;
		}
		i++;
	}
	return (i);
}

void	ft_clear_str(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
