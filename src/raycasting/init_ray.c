/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:26:36 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/12 16:27:01 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting_data(t_data *data)
{
	data->ray.x = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	get_player_pos(data);
}
