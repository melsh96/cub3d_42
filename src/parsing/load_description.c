/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:40 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/14 17:58:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_background (unsigned int color, t_data *data, int id)
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

int	render_colors(t_data *data)
{
	get_background(data->floor, data, data->C);
	get_background(data->ceil, data, data->F);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	
	return (0);
}

int	load_image (t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
