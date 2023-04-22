/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/17 19:22:06 by meshahrv         ###   ########.fr       */
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
	data->texture[data->NO].img = mlx_xpm_file_to_image(data->mlx, data->texture[data->NO].ad, &data->texture[data->NO].width, &data->texture[data->NO].height);
	data->texture[data->SO].img = mlx_xpm_file_to_image(data->mlx, data->texture[data->SO].ad, &data->texture[data->SO].width, &data->texture[data->SO].height);
	data->texture[data->WE].img = mlx_xpm_file_to_image(data->mlx, data->texture[data->WE].ad, &data->texture[data->WE].width, &data->texture[data->WE].height);
	data->texture[data->EA].img = mlx_xpm_file_to_image(data->mlx, data->texture[data->EA].ad, &data->texture[data->EA].width, &data->texture[data->EA].height);
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
