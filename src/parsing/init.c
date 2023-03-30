/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:29 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 13:18:04 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map(t_data *data)
{
	data->map.width = 0;
	data->map.height = 0;
	data->map.tab = NULL;
	data->map.line = NULL;
}
