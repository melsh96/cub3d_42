/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:29 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/10 19:06:35 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->texture[i].path = NULL;
		data->texture[i].id = NULL;
		data->texture[i].addr = NULL;
		data->texture[i].picture = NULL;
		data->texture[i].picture->img = NULL;
		data->texture[i].picture->bits_per_pixel = 0;
		data->texture[i].picture->line_length = 0;
		data->texture[i].picture->endian = 0;
		i++;
	}
}

void	init_map(t_data *data)
{
	
	data->map.width = 0;
	data->map.height = 0;
	data->map.tab = NULL;
	data->map.line = NULL;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	init_floor_and_ceiling(data);
	mlx_key_hook(data->mlx_win, &handle_input, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, destroy_cub, data);
	mlx_loop(data->mlx);
}


