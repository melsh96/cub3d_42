/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/05 13:33:13 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_biggest_line(t_data *data)
{
	int	i;
	int	longest_line;

	i = 0;
	longest_line = ft_strlen(data->map.tab[i]) - 1;
	while (i < data->map.height)
	{
		dprintf(2, "longest_line = %d\n", longest_line);
		if (longest_line < (int)ft_strlen(data->map.tab[i]))
			longest_line = ft_strlen(data->map.tab[i]) - 1;
		i++;
	}
	return (longest_line);
}

int	check_line_chars(char *line)
{
	int 	i;

	i = 0;
	if (line[0] == '\n')
		return(0);
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
	int		new_line;
	
	i = 0;
	new_line = 1;
	while (new_line)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			return (1);
		if (line[0] != '\n')
			break;
		free(line);
	}
	while (i < data->map.height)
	{
		if (line == NULL)
			line = get_next_line(data->fd);
		if (line == NULL)
			return (1);
		if (!check_line_chars(line))
		{
			data->map.tab[i] = 0;
			free(line);
			return (1);
		}
		data->map.tab[i] = line;
		line = NULL;
		i++;
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
	printf("pos_count = %d\n", data->count.pos);
	if (data->count.pos == 0)
	{
		printf("Error: Oops, we can't find any player !\n");
		return (1);
	}
	if (data->count.pos == 1)
		return (0);
	else
	{
		printf("Error: You have too many players\n");
		return (1);	
	}
	return (0);
}

int	get_map(t_data *data)
{
	int	i;

	i = 0;
	data->map.tab = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	while (i < data->map.height + 1)
	{
		data->map.tab[i] = 0;
		i++;
	}
	if (is_right_chars(data) == 1)
	{
		printf("Error: Wrong Chars\n");
		return (0);
	}
	if (is_only_one_player(data) == 1)
		return (0);
	print_tab(data->map.tab, data->map.height);
	return (1);
}
