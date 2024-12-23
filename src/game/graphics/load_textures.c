/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:04 by javjimen          #+#    #+#             */
/*   Updated: 2024/12/23 13:45:05 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_asset_file_name(int fd)
{
	int		i;
	char	*file_name;

	file_name = get_next_line(fd);
	i = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '\n')
			file_name[i] = '\0';
		i++;
	}
	return (file_name);
}

void	init_textures_to_null(t_mlx_data *mlx_data)
{
	t_texture_type	i;

	i = empty_tx;
	while (i <= player_tx)
	{
		mlx_data->textures[i] = NULL;
		i++;
	}
}

void	loop_on_texture_files(t_mlx_data *mlx_data, int fd, \
								int *width, int *height)
{
	t_texture_type	i;
	char			*file_name;

	i = empty_tx;
	while (i <= player_tx)
	{
		file_name = get_asset_file_name(fd);
		if (!file_name)
		{
			on_graphics_close_hook(mlx_data);
			error_handler(read_asset_file_error);
		}
		mlx_data->textures[i] = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
			file_name, width, height);
		free(file_name);
		if (!(mlx_data->textures[i]))
		{
			on_graphics_close_hook(mlx_data);
			error_handler(mlx_error);
		}
		i++;
	}
}

int	load_textures(t_mlx_data *mlx_data)
{
	int	fd;
	int	width;
	int	height;

	init_textures_to_null(mlx_data);
	fd = open(ASSETS_FILE_LIST, O_RDONLY);
	if (fd == -1)
	{
		on_graphics_close_hook(mlx_data);
		error_handler(open_asset_file_error);
	}
	width = TILE_SIZE;
	height = TILE_SIZE;
	loop_on_texture_files(mlx_data, fd, &width, &height);
	close(fd);
	return (0);
}
