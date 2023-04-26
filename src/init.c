/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:29 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 18:38:22 by cchapon          ###   ########.fr       */
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
		data->texture[i].ad = NULL;
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

int	render_colors(t_data *data)
{
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		destroy_cub(data);
	else if (key == XK_w || key == XK_W)
		move_up(data);
	else if (key == XK_a || key == XK_A)
	 	move_left(data);
	else if (key == XK_s || key == XK_S)
		move_down(data);
	else if (key == XK_d || key == XK_D)
		move_right(data);
	else if (key == XK_Left || key == XK_Right)
		rotate(data, key);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"Hello world!");
	if (data->mlx_win == NULL)
		return ;
	load_image(data);
	init_raycasting_data(data);
	init_game(data);
	data->map.tab[(int)data->player.pos_x][(int)data->player.pos_y] = '0';
	mlx_loop_hook(data->mlx, render_colors, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_input, data);
	mlx_hook(data->mlx_win, 3, 1L << 0, handle_input, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, destroy_cub, data);
	mlx_loop(data->mlx);
}
