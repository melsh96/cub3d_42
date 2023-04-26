/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 16:31:31 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_map(t_data *data)
{
	int	i;

	i = 0;
	data->map.tab = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.tab)
		return (0);
	while (i < data->map.height + 1)
	{
		data->map.tab[i] = 0;
		i++;
	}
	if (is_right_chars(data) == 1)
	{
		printf("%sError:%s Wrong Chars\n", RED, NC);
		return (0);
	}
	if (is_only_one_player(data) == 1)
		return (0);
	data->map.longest_map_line = get_biggest_line(data);
	if (resize_map(data) == 1)
	{
		printf("%sError:%s Map is not correctly resized\n", RED, NC);
		return (0);
	}
	print_tab(data->map.tab, data->map.height);
	if (check_walls(data) == 1)
	{
		printf("%sError:%s Your Map is not closed\n", RED, NC);
		return (0);
	}
	return (1);
}

void	get_textures(t_data *data, char *av)
{
	int	i;

	data->fd = open(av, O_RDONLY);
	init_texture(data);
	i = 0;
	while (i < 6)
	{
		data->texture[i].path = get_next_line(data->fd);	
		if (!data->texture[i].path)
		{
			close(data->fd);
			return ;
		}
		if (ft_strncmp(data->texture[i].path, "\n", 1) == 0)
		{
			free(data->texture[i].path);
			i--;
		}
		else if (check_textures(data->texture[i].path) == 0)
			parse_error(data, "Wrong or missing id");
		else if (check_double_path(i, data, data->texture[i].path) == 1)
		 	parse_error(data, "double ligne found");
		else if (get_texture_param(data, &data->texture[i]) == 1)
		  	parse_error(data, "space en trop");
		i++;
	}
	get_colors_and_range(data);
}

int load_textures(t_data *data)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if ((i != data->C) || (i != data->F))
		{
			data->texture[i].img = mlx_xpm_file_to_image(data->mlx, data->texture[i].ad, \
			&data->texture[i].width, &data->texture[i].height);
			if (data->texture[i].img)
				data->texture[i].mlx_ad = mlx_get_data_addr(data->texture[i].img, \
				&data->texture[i].bits_per_pixel, &data->texture[i].line_length, &data->texture[i].endian);
		}
		i++;
	}
	return (0);
}

int	load_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->texture[data->F].x = 0;
	data->texture[data->F].y = WINDOW_HEIGHT - (WINDOW_HEIGHT / 3);
	load_textures(data);
	return (0);
}

int	render_colors(t_data *data)
{
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}