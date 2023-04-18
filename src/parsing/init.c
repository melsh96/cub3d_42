/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:29 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/17 15:54:57 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	init_picture(t_picture *picture)
// {
// 	picture->addr = NULL;
// 	picture->img = NULL;
// 	picture->bits_per_pixel = 0;
// 	picture->line_length = 0;
// 	picture->endian = 0;
// 	picture->x = 0;
// 	picture->y = 0;
// 	picture->width = 0;
// 	picture->height = 0;
// }

void	init_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->texture[i].path = NULL;
		data->texture[i].id = NULL;
		data->texture[i].ad = NULL;
		data->texture[i].img = NULL;
		data->texture[i].bits_per_pixel = 0;
		data->texture[i].line_length = 0;
		data->texture[i].endian = 0;
		data->texture[i].x = 0;
		data->texture[i].y = 0;
		data->texture[i].width = WINDOW_WIDTH ;
		data->texture[i].height = WINDOW_HEIGHT / 3;
		i++;
	}
}

void	init_map(t_data *data)
{
	data->map.width = 0;
	data->map.height = 0;
	data->map.tab = NULL;
	data->map.line = NULL;
  	data->map.longest_map_line = 0;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (data->mlx_win == NULL)
		return ;
	load_image(data);	
	init_raycasting_data(data);
	mlx_loop_hook(data->mlx, &render_colors, data);
	mlx_key_hook(data->mlx_win, &handle_input, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, destroy_cub, data);
	mlx_loop(data->mlx);
}
