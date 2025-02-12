/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:04 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/12 19:25:01 by javjimen         ###   ########.fr       */
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
			in_game_error_handler(read_asset_file_error, ASSETS_FILE_LIST);
			on_graphics_close_hook(mlx_data);
		}
		check_asset_file(mlx_data, file_name);
		mlx_data->textures[i] = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
			file_name, width, height);
		free(file_name);
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
	int	fd;
	int	width;
	int	height;

	init_textures_to_null(mlx_data);
	fd = open(ASSETS_FILE_LIST, O_RDONLY);
	if (fd == -1)
	{
		in_game_error_handler(open_asset_file_error, ASSETS_FILE_LIST);
		on_graphics_close_hook(mlx_data);
	}
	width = TILE_SIZE;
	height = TILE_SIZE;
	loop_on_texture_files(mlx_data, fd, &width, &height);
	close(fd);
}
