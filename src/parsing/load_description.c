/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/24 16:22:15 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_background (unsigned int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pixel_put(&data->img, j++, i, color);
		i++;
	}
	return (0); 
}

int	get_background_fix (unsigned int color, t_data *data, int id)
{
	int	i;
	int	j;
	
	i = data->texture[id].y;
	while (i < data->texture[id].y + data->texture[id].height)
	{
		j = data->texture[id].x;
		while (j < data->texture[id].x + data->texture[id].width)
			my_mlx_pixel_put(&data->img, j++, i, color);
		i++;
	}
	return (0); 
}

int load_textures(t_data *data)
{
	int i;

	i = 0;
	while (data->texture[i].ad)
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

int	render_colors(t_data *data)
{
	draw(data);
	// get_background(BACKGROUND_COLOR, data);
	// get_background_fix(data->floor, data, data->F);
	// get_background_fix(data->ceil, data, data->C);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);

	// printf("PLAYER POS_X = %f\n", data->player.pos_x);
	// printf("PLAYER POS_Y = %f\n", data->player.pos_y);
	return (0);
}

int	load_image (t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->texture[data->F].x = 0;
	data->texture[data->F].y = WINDOW_HEIGHT - (WINDOW_HEIGHT / 3);
	load_textures(data);
	return (0);
}
