/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/10 19:01:30 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(t_data *data, char *color_line)
{
	char **colors;
	int	i;
	int	l;
	int color;

	colors = ft_split(color_line, ',');
	l = 0;
	while (colors[l])
		l++;
	if (l != 3)
	{
		free_double_tab(colors, l);
		parse_error(data, "Bad colors description");
	}
	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			free_double_tab(colors, l);
			parse_error(data, "Bad color range");
		}
		i++;
	}
	color = ft_atoi(colors[0]) << 16 | ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]);
	free_double_tab(colors, l);
	return (color);
}

void	my_mlx_pixel_put(t_picture *picture, int x, int y, int color)
{
	char	*dst;

	dst = picture->addr + (y * picture->line_length + x * (picture->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void load_floor_or_ceiling(t_data *data, t_picture *picture, unsigned int color)
{
	picture->img = mlx_new_image(data->mlx, 1920, 400);
	picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length, &picture->endian);
	my_mlx_pixel_put(picture->img, 5, 5, color);
	if (color == data->floor)
		mlx_put_image_to_window(data->mlx, data->mlx_win, picture->img, 0, 0);
	else if (color == data->ceil)
		mlx_put_image_to_window(data->mlx, data->mlx_win, picture->img, 5, 5);
}

void load_colors(t_data *data)
{
	int	i;
	int	len;
	
	i = 0;
	while (i < 6)
	{
		len = ft_strlen(data->texture[i].id);
		if (ft_strncmp(data->texture[i].id, "F", len) == 0)
			data->floor = get_color(data, data->texture[i].addr);
		if (ft_strncmp(data->texture[i].id, "C", len) == 0)
			data->ceil = get_color(data, data->texture[i].addr);
		i++;
	}
}

void	init_floor_and_ceiling(t_data *data)
{
	int i;
	int	len;
	
	i = 0;
	while (i < 6)
	{
		len = ft_strlen(data->texture[i].id);
		if (ft_strncmp(data->texture[i].id, "F", len) == 0)
			load_floor_or_ceiling(data, data->texture[i].picture, data->floor);
		if (ft_strncmp(data->texture[i].id, "C", len) == 0)
			load_floor_or_ceiling(data, data->texture[i].picture, data->ceil);
		i++;
	}
}
