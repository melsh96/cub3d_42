/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:34 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 12:48:55 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	draw(t_data *data)
{
	data->ray.x = -1;

	while (++data->ray.x < WINDOW_WIDTH)
	{
		ray_init(data);
		// Calculate ray position and direction
		data->ray.camera_x = 2 * data->ray.x / (double)WINDOW_WIDTH - 1; // x coordinate in camera space
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;
	
		// Length of ray from one x or y-side to next x or y-side
		init_rays(&data);

      	// Calculate step and initial sideDist
		init_step_side_distance(&data);

		data->ray.ray_pos_x = data->player.pos_x;
		data->ray.ray_pos_y = data->player.pos_y;

		data->ray.side = 0;

		// Start DDA Algo
		find_wall(&data);
		// printf("Hello\n");

		data->ray.hit = 0;
		
		// Calculate Texture
		pass_to_3d(data);
	}
	// return (0);
}
