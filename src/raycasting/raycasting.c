/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:34 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 17:50:24 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

/*	Step 1: Init Rays Data
	
	This while loop will calculate each time the pos x & y of the player.
	For ther Raycasting we will need ray positions and directions.
	
	camera_x is the x coordinate : 
		- right side of screen = coord 1,
		- center = coord 0;
		- left = coord -1;
	
	rays will be calculated as the sum of the direction and a part of the camera plane
*/

/*	Step 2: Calculate Rays Distance
	
	Calculate Delta distance with pythagorias formulas
	Calculate Steps from ray distance starting from x and y pos of player
*/

/* Step 3: DDA Algorithm*/

/* Step 4: Textures*/

void	draw(t_data *data)
{
	data->ray.x = -1;

	while (++data->ray.x < WINDOW_WIDTH)
	{
		ray_init(data);
		data->ray.camera_x = 2 * data->ray.x / (double)WINDOW_WIDTH - 1;
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;
		init_delta_dist(&data);
		init_step_side_distance(&data);
		data->ray.ray_pos_x = data->player.pos_x;
		data->ray.ray_pos_y = data->player.pos_y;
		data->ray.side = 0;
		touch_wall(&data);
		find_wall(&data);
		data->ray.hit = 0;
		pass_to_3d(data);
	}
}
