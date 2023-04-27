/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:49:31 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/27 13:03:44 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_line_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] == ' ' || line[i] == '1' || line[i] == '0' \
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' \
			|| line[i] == 'W' || line[i] == '\n'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_only_one_player(t_data *data)
{
	count_positions(data);
	if (data->count.pos == 0)
	{
		printf("%sError:%s Oops, we can't find any player !\n", RED, NC);
		return (1);
	}
	if (data->count.pos == 1)
		return (0);
	else
	{
		printf("%sError:%s You have too many players\n", RED, NC);
		return (1);
	}
	return (0);
}

int	get_biggest_line(t_data *data)
{
	int	i;
	int	longest_line;
	int	actual_line;

	i = 0;
	longest_line = 0;
	actual_line = 0;
	while (i <= data->map.height)
	{
		if (data->map.tab[i] != NULL)
		{
			actual_line = ft_strlen(data->map.tab[i]) - 1;
			if (longest_line < actual_line)
				longest_line = actual_line;
		}
		i++;
	}
	return (longest_line);
}

int	is_right_data(t_data *data, int i)
{
	while (i < data->map.height)
	{
		if (data->line == NULL)
			data->line = get_next_line(data->fd);
		if (data->line == NULL)
			return (free(data->line), 1);
		if (!check_line_chars(data->line))
		{
			data->map.tab[i] = 0;
			free(data->line);
			return (1);
		}
		if (data->line[0] == '\n')
			break ;
		data->map.tab[i] = data->line;
		data->line = NULL;
		i++;
	}
	free(data->line);
	return (0);
}

int	is_right_chars(t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			return (free(data->line), 1);
		if (data->line[0] != '\n')
			break ;
		free(data->line);
	}
	if (is_right_data(data, i) == 1)
		return (1);
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			return (free(data->line), 0);
		if (data->line[0] != '\n')
			return (free(data->line), 1);
		free(data->line);
	}
	data->map.tab[i] = 0;
	return (0);
}
