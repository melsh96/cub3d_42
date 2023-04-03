/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:59 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/03 15:24:37 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_error(char *msg)
{
	printf("%s%sError:%s %s\n", RED, BOLD, NC, msg);
	exit(1);
}

int	file_extension(char *av, char *c)
{
	int	len;

	len = ft_strlen(av) - 1;
	if (len < 4)
		return (1);
	if (ft_strncmp(av + (len - 3), c, 5) != 0)
		return (1);
	return (0);
}

int is_map_line (char *line)
{
	int	i;

	i = 0;
	if (line[0] == '1')
		return (1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int	parse_files(t_data *data, char *av)
{
	char	*line;
	
	if (file_extension(av, ".cub") == 1)
		parse_error("Wrong file extension");
	data->fd = open(av, __O_DIRECTORY);
	if (data->fd >= 0)
		return (close(data->fd), 1);
	data->fd = open(av, O_RDONLY);
	if (data->fd <= 0)
		parse_error("Can't open file\n");
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break;
		if (is_map_line(line) == 1)
			data->map.height++;
		//data->file_length++;
		free(line);
	}
	close(data->fd);
	return (1);
}