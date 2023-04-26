/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:43:46 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 13:23:48 by cchapon          ###   ########.fr       */
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