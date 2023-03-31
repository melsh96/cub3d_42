/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/31 19:20:02 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_map(t_data *data)
{
	int		i;
	
	if (data->map.height <= 0)
		parse_error("Fail to read file");
	data->map.tab = (char **)malloc(sizeof(char *) * data->map.height + 1);
	if (!data->map.tab)
		return ;
	i = 0;
	while (i < data->map.height)
	{
		data->map.tab[i] = get_next_line(data->fd);
		if (data->map.tab[i] == NULL)
			break ;
		if (is_map_line(data->map.tab[i]) != 1)
		{
			free(data->map.tab[i]);
			i--;
		}
		i++;
	}
	print_map(&data->map);
}
