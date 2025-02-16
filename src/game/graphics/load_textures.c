/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:04 by javjimen          #+#    #+#             */
/*   Updated: 2025/02/16 13:10:26 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parse_asset_name(int fd)
{
	int		i;
	char	*asset_name;

	asset_name = get_next_line(fd);
	if (!asset_name)
		return (NULL);
	i = 0;
	while (asset_name[i] != '\0')
	{
		if (asset_name[i] == '\n')
			asset_name[i] = '\0';
		i++;
	}
	return (asset_name);
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

char	*get_asset_name(t_mlx_data *mlx_data, t_file_data assets_file_list)
{
	int		fd;
	char	*asset_name;

	asset_name = parse_asset_name(assets_file_list.fd);
	if (!asset_name)
	{
		in_game_error_handler(read_assets_file_list_error, \
								assets_file_list.name);
		on_graphics_close_hook(mlx_data);
	}
	fd = open(asset_name, O_RDONLY);
	if (fd < 0)
	{
		in_game_error_handler(open_asset_error, asset_name);
		free(asset_name);
		on_graphics_close_hook(mlx_data);
	}
	return (asset_name);
}

void	loop_on_textures(t_mlx_data *mlx_data, t_file_data assets_file_list, \
							int *width, int *height)
{
	t_texture_type	i;
	char			*asset_name;

	i = empty_tx;
	while (i <= win_screen_tx)
	{
		asset_name = get_asset_name(mlx_data, assets_file_list);
		if (i == win_screen_tx)
		{
			*width *= 2.5;
			*height *= 2;
		}
		mlx_data->textures[i] = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
			asset_name, width, height);
		free(asset_name);
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
	t_file_data	assets_file_list;
	int			tile_size;
	int			width;
	int			height;

	init_textures_to_null(mlx_data);
	tile_size = select_tile_size(mlx_data->map);
	if (tile_size == 32)
		assets_file_list.name = ASSETS_FILE_LIST_X32;
	else
		assets_file_list.name = ASSETS_FILE_LIST_X64;
	assets_file_list.fd = open(assets_file_list.name, O_RDONLY);
	if (assets_file_list.fd == -1)
	{
		in_game_error_handler(open_assets_file_list_error, \
								assets_file_list.name);
		on_graphics_close_hook(mlx_data);
	}
	width = tile_size;
	height = tile_size;
	loop_on_textures(mlx_data, assets_file_list, &width, &height);
	close(assets_file_list.fd);
}
