/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:34 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/11 17:28:12 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == 'N' || data->map.tab[i][j] == 'S' || data->map.tab[i][j] == 'W' || data->map.tab[i][j] == 'E')
				break;
			j++;
		}
		if (j != data->map.longest_map_line + 1)
			break;
		i++;
	}
	data->player.pos_x = i;
	data->player.pos_y = j;
}

int raycasting(t_data *data)
{
	get_player_pos(data);
	printf("PLAYER POS_X = %d\n", data->player.pos_x);
	printf("PLAYER POS_Y = %d\n", data->player.pos_y);
	return (0);
}