/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/11 18:22:40 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_picture *picture, int x, int y, unsigned int color)
{
	char	*dst;

	dst = picture->addr + (y * picture->line_length + x * (picture->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_background(t_picture *picture, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(picture, j++, i, color);
		}
		++i;
	}
}

void load_floor_or_ceiling(t_data *data, t_picture *picture, unsigned int color)
{
	int	i;
	int	j;
	
	picture->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length, &picture->endian);
	if (data->mlx_win == NULL)
		return ;
	if (color == data->ceil)
	{
		i = 0;
		while (i < WINDOW_HEIGHT)
		{
			j = 0;
			while (j < WINDOW_WIDTH)
				my_mlx_pixel_put(picture, j++, i, color);
			i++;
		}
	}
	else if (color == data->floor)
	{
		i = WINDOW_HEIGHT;
		while (i > WINDOW_HEIGHT / 2)
		{
			j = 0;
			while (j < WINDOW_WIDTH)
				my_mlx_pixel_put(picture, j++, i, color);
			i--;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, picture->img, 0, 0);
}

int	init_floor_and_ceiling(t_data *data)
{
	int i;
	int	len;
	t_picture background;
	background.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_background(&background, BACKGROUND_COLOR);
	
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
	return (0);
}
