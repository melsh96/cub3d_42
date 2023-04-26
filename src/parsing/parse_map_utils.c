/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:49:31 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 13:49:54 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_line_chars(char *line)
{
	int 	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] == ' ' || line[i] == '1' || line[i] == '0' \
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\n'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_right_chars(t_data *data)
{
	int		i;
	char	*line;
	
	i = 0;
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			return (free(line), 1);
		if (line[0] != '\n')
			break;
		free(line);
	}
	while (i < data->map.height)
	{
		if (line == NULL)
			line = get_next_line(data->fd);
		if (line == NULL)
			return (free(line), 1);
		if (!check_line_chars(line))
		{
			data->map.tab[i] = 0;
			free(line);
			return (1);
		}
		if (line[0] == '\n')
			break ;
		data->map.tab[i] = line;
		line = NULL;
		i++;
	}
	free(line);
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			return (free(line), 0);
		if (line[0] != '\n')
			return (free(line), 1);
		free(line);
	}
	data->map.tab[i] = 0;
	return (0);
}

void	count_positions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->count.pos = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == 'N')
				data->count.pos++;
			else if (data->map.tab[i][j] == 'S')
				data->count.pos++;
			else if (data->map.tab[i][j] == 'E')
				data->count.pos++;
			else if (data->map.tab[i][j] == 'W')
				data->count.pos++;
			j++;
		}
		i++;
	}
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