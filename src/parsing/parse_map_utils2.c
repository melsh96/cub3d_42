/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 13:55:33 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*resize_line(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc(len + 2, sizeof(char));
	if (!res)
		return (NULL);
	if (!str)
		str = "";
	while (str && str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	while (i < len)
	{
		res[i] = ' ';
		i++;
	}
	res[len] = '\n';
	res[len + 1] = '\0';
	if (str)
		free(str);
	return (res);
}

int resize_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map.tab[i])
    {
        j = 0;
		if (!data->map.tab[i])
        	return (1);
        while (data->map.tab[i][j])
        {
            if ((int)ft_strlen(data->map.tab[i]) <= data->map.longest_map_line)
            {
                data->map.tab[i] = resize_line(data->map.tab[i], data->map.longest_map_line);
                if (!data->map.tab[i])
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int	check_line(char *str)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 2;
	while (str[i] == ' ')
		i++;
	if (str[i] && str[i] != '1')
		return (1);
	if (len >= 0 && str[len])
	{
		while (len >= 0 && str[len] == ' ')
			len--;
		if (len >= 0 && str[len] && str[len] != '1')
			return (1);
	}
	return (0);
}

int	check_walls(t_data *data)
{
	if (top_wall(data) == 1)
		return (1);
	if (last_wall(data) == 1)
		return (1);
	if (extremity_walls(data) == 1)
		return (1);
	if (horizontal_scan(data) == 1)
		return (1);
	if (vertical_scan(data) == 1)
		return (1);
	return (0);
}