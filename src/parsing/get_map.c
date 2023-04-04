/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/04 17:34:42 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_biggest_line(t_data *data)
{
	int	i;
	// int	j;
	int	longest_line;

	i = 0;
	longest_line = ft_strlen(data->map.tab[i]) - 1;
	// dprintf(2, "longest_line = %d\n", longest_line);
	while (i < data->map.height)
	{
		dprintf(2, "longest_line = %d\n", longest_line);
		if (longest_line < (int)ft_strlen(data->map.tab[i]))
			longest_line = ft_strlen(data->map.tab[i]) - 1;
		i++;
	}
	return (longest_line);
}

// int	check_chars(char *line)
// {
// 	int i;
	
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (!(line[i] == ' ' || line[i] == '1' || line[i] == '0' \
// 			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\n'))
// 		{
// 			printf("Error: Wrong Chars\n");
// 			return (0);
// 		}
// 		if (line[i + 1] == '\n')
// 		{
// 			if (line[i] == '1' || line[i] == ' ')
// 			{
// 				dprintf(2, "c'est un 1 ou un espace\n");
// 				return (1);
// 			}
// 			else
// 			{
// 				dprintf(2, "c'est un autre char\n");
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	check_line_chars(char *line)
{
	int i;

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
	data->map.tab = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	while (i < data->map.height + 1)
	{
		data->map.tab[i] = 0;
		i++;
	}
	i = 0;
	while (new_line)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			return (1);
		if (line[0] != '\n')
			break;
		free(line);
	}
	// ft_bzero(data->map.tab[i], data->map.height + 1);
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
		// printf("line[%d] has good chars\n", i);
		printf("line = %s", line);
		// if (line != NULL)
		// free(line);
		data->map.tab[i] = line;
		line = NULL;
		i++;
	}
	data->map.tab[i] = 0;
	// free(line);
	return (0);
}

// void	skip_new_line_before_map();

int	get_map(t_data *data)
{
	
	if (is_right_chars(data) == 1)
	{
		printf("Error: Wrong Chars\n");
		return (0);
	}
	print_tab(data->map.tab, data->map.height);
	return (1);
}

// void	get_map(t_data *data)
// {
// 	int		i;
	
// 	if (data->map.height <= 0)
// 		parse_error("Fail to read file");
// 	data->map.tab = (char **)malloc(sizeof(char *) * data->map.height + 1);
// 	if (!data->map.tab)
// 		return ;
// 	i = 0;
// 	while (i < data->map.height)
// 	{
// 		data->map.tab[i] = get_next_line(data->fd);
// 		if (data->map.tab[i] == NULL)
// 			break ;
// 		if (is_map_line(data->map.tab[i]) != 1)
// 		{
// 			free(data->map.tab[i]);
// 			data->map.tab[i] = NULL;
// 			i--;
// 		}
// 		// if (ft_strncmp(data->map.tab[i], "\n", 2))
// 		// 	data->map.tab[i] = NULL;
// 		// else if (check_chars(data->map.tab[i]) == 0)
// 		// {
// 		// 	free_double_tab(data->map.tab, data->map.height);
// 		// 	close(data->fd);
// 		// 	parse_error("Wrong character");
// 		// }
// 		i++;
// 	}
// 	print_tab(data->map.tab, data->map.height);

// 	// check_chars(data->map.tab[i]);
// 	// close(data->fd);
// 	// print_tab(data->map.tab, data->map.height);
// 	data->map.width = get_biggest_line(data);
// 	// if (data->map.width)
// 	// {
// 	// 	//TODO : resize all the lines to have the same length as the longest_line
// 	// }
// }
