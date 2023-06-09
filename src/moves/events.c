/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:45:27 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/27 14:02:10 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_data *data)
{
	if (data->map.tab[(int)(data->player.pos_x + (data->ray.dir_x * \
	data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y + \
	(data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y += data->ray.dir_y * data->ray.move_speed;
}

void	move_down(t_data *data)
{	
	if (data->map.tab[(int)(data->player.pos_x - (data->ray.dir_x * \
	data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y - \
	(data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y -= data->ray.dir_y * data->ray.move_speed;
}

void	move_left(t_data *data)
{
	if (data->map.tab[(int)(data->player.pos_x - data->ray.dir_y * \
	(data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->ray.dir_y * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y + \
	data->ray.dir_x * (data->ray.move_speed * 2))] == '0')
		data->player.pos_y += data->ray.dir_x * data->ray.move_speed;
}

void	move_right(t_data *data)
{
	if (data->map.tab[(int)(data->player.pos_x + data->ray.dir_y * \
	(data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->ray.dir_y * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y - \
	data->ray.dir_x * (data->ray.move_speed * 2))] == '0')
		data->player.pos_y -= data->ray.dir_x * data->ray.move_speed;
}

void	rotate(t_data *data, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	old_plane_x = data->ray.plane_x;
	if (key == XK_Left)
	{
		data->ray.dir_x = data->ray.dir_x * cos(0.2) - data->ray.dir_y * \
		sin(0.2);
		data->ray.dir_y = old_dir_x * sin(0.2) + data->ray.dir_y * cos(0.2);
		data->ray.plane_x = data->ray.plane_x * cos(0.2) - data->ray.plane_y * \
		sin(0.2);
		data->ray.plane_y = old_plane_x * sin(0.2) + data->ray.plane_y * \
		cos(0.2);
	}
	else if (key == XK_Right)
	{
		data->ray.dir_x = data->ray.dir_x * cos(-0.2) - data->ray.dir_y * \
		sin(-0.2);
		data->ray.dir_y = old_dir_x * sin(-0.2) + data->ray.dir_y * cos(-0.2);
		data->ray.plane_x = data->ray.plane_x * cos(-0.2) - data->ray.plane_y * \
		sin(-0.2);
		data->ray.plane_y = old_plane_x * sin(-0.2) + data->ray.plane_y * \
		cos(-0.2);
	}
}
