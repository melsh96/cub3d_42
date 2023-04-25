/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:45:27 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/25 13:52:05 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// rotate cam right and left with keyborad arrows

// move player right left up down with W A S D 

void move_up(t_data *data) // North or forward
{
	if (data->map.tab[(int)(data->player.pos_x + (data->ray.dir_x * data->ray.move_speed *2))][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y + (data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y += data->ray.dir_y * data->ray.move_speed;
}

void move_down(t_data *data) // North or forward
{
	if (data->map.tab[(int)(data->player.pos_x - (data->ray.dir_x * data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y - (data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y -= data->ray.dir_y * data->ray.move_speed;
}

void move_left(t_data *data)
{
	double oldDirX = data->ray.dir_x;
    data->ray.dir_x = data->ray.dir_x * cos(0.2) - data->ray.dir_y * sin(0.2);
    data->ray.dir_y = oldDirX * sin(0.2) + data->ray.dir_y * cos(0.2);
    double oldPlaneX = data->ray.plane_x;
    data->ray.plane_x = data->ray.plane_x * cos(0.2) - data->ray.plane_y * sin(0.2);
    data->ray.plane_y = oldPlaneX * sin(0.2) + data->ray.plane_y * cos(0.2);
}

void move_right(t_data *data)
{
	double oldDirX = data->ray.dir_x;
    data->ray.dir_x = data->ray.dir_x * cos(-0.2) - data->ray.dir_y * sin(-0.2);
    data->ray.dir_y = oldDirX * sin(-0.2) + data->ray.dir_y * cos(-0.2);
    double oldPlaneX = data->ray.plane_x;
    data->ray.plane_x = data->ray.plane_x * cos(-0.2) - data->ray.plane_y * sin(-0.2);
    data->ray.plane_y = oldPlaneX * sin(-0.2) + data->ray.plane_y * cos(-0.2);
}

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		destroy_cub(data);
	else if (key == XK_w || key == XK_W)
		move_up(data);
	else if (key == XK_a | key == XK_A)
	 	move_left(data);
	else if (key == XK_s | key == XK_S)
		move_down(data);
	else if (key == XK_d | key == XK_D)
		move_right(data);
	return (0);
}
