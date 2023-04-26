/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:45:27 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 12:24:11 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// rotate cam right and left with keyborad arrows

// move player right left up down with W A S D 

void move_up(t_data *data) // forward
{
	if (data->map.tab[(int)(data->player.pos_x + (data->ray.dir_x * data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y + (data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y += data->ray.dir_y * data->ray.move_speed;
}

void move_down(t_data *data) // backward
{
	// ? Exemple pour securiser les bordures si le move speed est rapide
	// int calcul_x = (int)(data->player.pos_x - (data->ray.dir_x * data->ray.move_speed * 2));
	// int pos_y = (int)data->player.pos_y;
	// if ((calcul_x < data->map.height && pos_y < data->map.longest_map_line) && (0 < calcul_x && 0 < pos_y))
	// {
	// 	if (data->map.tab[calcul_x][pos_y] == '0')
	// 		data->player.pos_x -= data->ray.dir_x * data->ray.move_speed;
	// }
	
	// int pos_x = (int)data->player.pos_x;
	// int calcul_y = (int)(data->player.pos_y - (data->ray.dir_y * data->ray.move_speed * 2));
	// if ((pos_x < data->map.height && calcul_y < data->map.longest_map_line) && (0 < pos_x && 0 < calcul_y))
	// {
	// 	if (data->map.tab[pos_x][calcul_y] == '0')
	// 		data->player.pos_y -= data->ray.dir_y * data->ray.move_speed;
	// }
	
	if (data->map.tab[(int)(data->player.pos_x - (data->ray.dir_x * data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->ray.dir_x * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y - (data->ray.dir_y * data->ray.move_speed * 2))] == '0')
		data->player.pos_y -= data->ray.dir_y * data->ray.move_speed;
}

void move_left(t_data *data)
{
	if (data->map.tab[(int)(data->player.pos_x - data->ray.dir_y * (data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->ray.dir_y * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y + data->ray.dir_x * (data->ray.move_speed * 2))] == '0')
		data->player.pos_y += data->ray.dir_x * data->ray.move_speed;
}

void move_right(t_data *data)
{
	if (data->map.tab[(int)(data->player.pos_x + data->ray.dir_y * (data->ray.move_speed * 2))][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->ray.dir_y * data->ray.move_speed;
	if (data->map.tab[(int)data->player.pos_x][(int)(data->player.pos_y - data->ray.dir_x * (data->ray.move_speed * 2))] == '0')
		data->player.pos_y -= data->ray.dir_x * data->ray.move_speed;
}

void rotate_left(t_data *data) // rotate
{
	double old_dir_x;
    double old_plane_x;
	
	old_dir_x= data->ray.dir_x;
   	old_plane_x = data->ray.plane_x;
    data->ray.dir_x = data->ray.dir_x * cos(0.2) - data->ray.dir_y * sin(0.2);
    data->ray.dir_y = old_dir_x* sin(0.2) + data->ray.dir_y * cos(0.2);
    data->ray.plane_x = data->ray.plane_x * cos(0.2) - data->ray.plane_y * sin(0.2);
    data->ray.plane_y = old_plane_x * sin(0.2) + data->ray.plane_y * cos(0.2);
}

void rotate_right(t_data *data) // rotate
{
	double old_dir_x;
    double old_plane_x;
	
	old_dir_x = data->ray.dir_x;
	old_plane_x = data->ray.plane_x;
    data->ray.dir_x = data->ray.dir_x * cos(-0.2) - data->ray.dir_y * sin(-0.2);
    data->ray.dir_y = old_dir_x * sin(-0.2) + data->ray.dir_y * cos(-0.2);
    data->ray.plane_x = data->ray.plane_x * cos(-0.2) - data->ray.plane_y * sin(-0.2);
    data->ray.plane_y = old_plane_x * sin(-0.2) + data->ray.plane_y * cos(-0.2);
}

int	handle_input(int key, t_data *data)
{
	// printf("pos_x = %d\n", (int)(data->player.pos_x - (data->ray.dir_x * data->ray.move_speed * 2)));
	// printf("pos_y = %d\n", (int)(data->player.pos_y + (data->ray.dir_x * data->ray.move_speed * 2)));
	// printf("%d", (int).9);
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
	else if (key == XK_Left)
		rotate_left(data);
	else if (key == XK_Right)
		rotate_right(data);
	return (0);
}
