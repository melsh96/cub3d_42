/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/06 19:42:43 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_line_chars(char *line)
{
	int 	i;

	i = 0;
	// if (line[0] == '\n')
	// 	return(0);
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
	// int		new_line;
	
	i = 0;
	// new_line = 1;
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

int	horizontal_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j] && data->map.tab[i][j + 1])
		{
			if (data->map.tab[i][j] == ' ')
			{
				if (!(data->map.tab[i][j + 1] == '1' || data->map.tab[i][j + 1] == ' '))
					return (1);
			}
			j++;	
		}
		i++;
	}
	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j] && data->map.tab[i][j + 1])
		{
			if (data->map.tab[i][j + 1] == ' ')
			{
				if (!(data->map.tab[i][j] == '1' || data->map.tab[i][j] == ' '))
					return (1);
			}
			j++;	
		}
		i++;
	}
	return (0);
}
// int	vertical_check(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map.tab[i])
// 	{
// 		j = 0;
// 		while (data->map.tab[i][++j] && data->map.tab[i + 1])
// 		{
// 			if (data->map.tab[i][j] && data->map.tab[i][j] == ' ')
// 			{
// 				if (!(data->map.tab[i + 1][j] == '1' || data->map.tab[i + 1][j] == ' '))
// 					return (1);
// 			}
// 			j++;	
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (data->map.tab[i])
// 	{
// 		j = 0;
// 		while (data->map.tab[i] && data->map.tab[i + 1])
// 		{
// 			if (data->map.tab[i + 1][j] && data->map.tab[i + 1][j] == ' ')
// 			{
// 				if (!(data->map.tab[i][j] == '1' || data->map.tab[i][j] == ' '))
// 					return (1);
// 			}
// 			j++;	
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	vertical_check(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (data->map.tab[++i])
// 	{
// 		j = -1;
// 		while (data->map.tab[i][++j] && data->map.tab[i][j + 1])
// 			if ((data->map.tab[i][j] == '0' && data->map.tab[i][j + 1] == ' ')
// 				|| (data->map.tab[i][j + 1] == '0' && data->map.tab[i][j] == ' '))
// 				return (1);
// 	}
// 	j = 0;
// 	while (data->map.tab[0][++j])
// 	{
// 		i = -1;
// 		while (data->map.tab[++i] && data->map.tab[i + 1])
// 			if ((data->map.tab[i][j] == '0' && data->map.tab[i + 1][j] == ' ')
// 				|| (data->map.tab[i + 1][j] == '0' && data->map.tab[i][j] == ' '))
// 				return (1);
// 	}
// 	return (0);
// }

int	map_not_closed(t_data *data)
{
	if (horizontal_check(data) == 1)
		return (1);
	// if (vertical_check(data) == 1)
	// 	return (1);
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

char	*resize_line(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	res = calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!str)
		str = "";
	while (str && str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	while (i <= len)
	{
		res[i] = ' ';
		i++;
	}
	res[len] = '\n';
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

void	check_each_line_len(t_data *data)
{
	int	i;
	// int	longest_line;
	int	actual_line;

	i = 0;
	// longest_line = 0;
	actual_line = 0;
	while (i <= data->map.height)
	{
		if (data->map.tab[i] != NULL)
    	{
    	    actual_line = ft_strlen(data->map.tab[i]) - 1;
			printf("actual_line = %d\n", actual_line);
    	}
	    i++;
	}
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
	if (map_not_closed(data) == 1)
	{
		printf("Error: Map is not closed\n");
		return (0);
	}
	data->map.longest_map_line = get_biggest_line(data);
	dprintf(2, "%slongest_fuckin_line =%s %d\n", RED, NC, data->map.longest_map_line);
	print_tab(data->map.tab, data->map.height);
	if (resize_map(data) == 1)
	{
		printf("Error: Map is not correctly resized\n");
		return (0);
	}
	print_tab(data->map.tab, data->map.height);
	// check_each_line_len(data);
	return (1);
}
