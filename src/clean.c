/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:24:17 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/24 13:51:02 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_texture(t_data *data)
{
	int s;

	s = -1;
	while (++s < 6 && data->texture[s].img)
		mlx_destroy_image(data->mlx, data->texture[s].img);
	s = -1;
	while (++s < 6 && data->texture[s].path)
		free(data->texture[s].path);
	s = -1;
	while (++s < 6 && data->texture[s].id)
		free(data->texture[s].id);
	s = -1;
	while (++s < 6 && data->texture[s].ad)
		free(data->texture[s].ad);
}
