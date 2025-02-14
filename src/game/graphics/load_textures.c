/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:04 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/14 22:03:58 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_asset_file_name(int fd)
{
	int		i;
	char	*file_name;

	file_name = get_next_line(fd);
	if (!file_name)
		return (NULL);
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
	while (i <= win_screen_tx)
	{
		mlx_data->textures[i] = NULL;
		i++;
	}
}

void	check_asset_file(t_mlx_data *mlx_data, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		in_game_error_handler(open_current_asset_file_error, file_name);
		free(file_name);
		on_graphics_close_hook(mlx_data);
	}
}

void	loop_on_texture_files(t_mlx_data *mlx_data, t_file_data file_data, \
								int *width, int *height)
{
	t_texture_type	i;
	char			*assets_file_name;

	i = empty_tx;
	while (i <= win_screen_tx)
	{
		assets_file_name = get_asset_file_name(file_data.fd);
		if (!assets_file_name)
		{
			in_game_error_handler(read_asset_file_error, file_data.name);
			on_graphics_close_hook(mlx_data);
		}
		check_asset_file(mlx_data, assets_file_name);
		if (i == win_screen_tx)
		{
			*width *= 2.5;
			*height *= 2;
		}
		mlx_data->textures[i] = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
			assets_file_name, width, height);
		free(assets_file_name);
		if (!(mlx_data->textures[i]))
		{
			in_game_error_handler(mlx_error, "Texture missing");
			on_graphics_close_hook(mlx_data);
		}
		i++;
	}
}

void	load_textures(t_mlx_data *mlx_data)
{
	t_file_data	file_data;
	int			tile_size;
	int			width;
	int			height;

	init_textures_to_null(mlx_data);
	tile_size = select_tile_size(mlx_data->map);
	if (tile_size == 32)
		file_data.name = ASSETS_FILE_LIST_X32;
	else
		file_data.name = ASSETS_FILE_LIST_X64;
	file_data.fd = open(file_data.name, O_RDONLY);
	if (file_data.fd == -1)
	{
		in_game_error_handler(open_asset_file_error, file_data.name);
		on_graphics_close_hook(mlx_data);
	}
	width = tile_size;
	height = tile_size;
	loop_on_texture_files(mlx_data, file_data, &width, &height);
	close(file_data.fd);
}
