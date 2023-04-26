/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:53:41 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 16:47:32 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	top_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map.tab[0][j])
	{
		if (!(data->map.tab[0][j] == '1' || data->map.tab[0][j] == ' ' \
		|| data->map.tab[0][j] == '\n'))
			return (1);
		j++;
	}
	return (0);
}

int	last_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map.tab[data->map.height - 1] && \
	data->map.tab[data->map.height - 1][j])
	{
		if (!(data->map.tab[data->map.height - 1][j] == '1' || \
		data->map.tab[data->map.height - 1][j] == ' ' || \
		data->map.tab[data->map.height - 1][j] == '\n'))
			return (1);
		j++;
	}
	return (0);
}

int	extremity_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (check_line(data->map.tab[i]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	horizontal_scan(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j] && data->map.tab[i][j + 1])
		{
			if (data->map.tab[i][j] == ' ' && data->map.tab[i][j + 1] != '\n')
			{
				if (!(data->map.tab[i][j + 1] == '1' || \
				data->map.tab[i][j + 1] == ' '))
					return (1);
			}
			else if (data->map.tab[i][j + 1] == ' ')
			{
				if (!(data->map.tab[i][j] == '1' || data->map.tab[i][j] == ' '))
					return (1);
			}
			j++;
		}
		i++;
	}
	// i = 0;
	// while (data->map.tab[i])
	// {
	// 	j = 0;
	// 	while (data->map.tab[i][j] && data->map.tab[i][j + 1])
	// 	{
	// 		if (data->map.tab[i][j + 1] == ' ')
	// 		{
	// 			if (!(data->map.tab[i][j] == '1' || data->map.tab[i][j] == ' '))
	// 				return (1);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (0);
}

int	vertical_scan(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j] && data->map.tab[i + 1])
		{
			if (data->map.tab[i][j] == ' ')
			{
				if (data->map.tab[i + 1] && !(data->map.tab[i + 1][j] == '1' \
				|| data->map.tab[i + 1][j] == ' '))
					return (1);
			}
			else if (data->map.tab[i + 1][j] == ' ')
			{
				if (data->map.tab[i] && !(data->map.tab[i][j] == '1' \
				|| data->map.tab[i][j] == ' '))
					return (1);
			}
			j++;	
		}
		i++;
	}
	// i = 0;
	// while (data->map.tab[i])
	// {
	// 	j = 0;
	// 	while (data->map.tab[i][j] && data->map.tab[i + 1])
	// 	{
	// 		if (data->map.tab[i + 1][j] == ' ')
	// 		{
	// 			if (data->map.tab[i] && !(data->map.tab[i][j] == '1' || data->map.tab[i][j] == ' '))
	// 				return (1);
	// 		}
	// 		j++;	
	// 	}
	// 	i++;
	// }
	return (0);
}
