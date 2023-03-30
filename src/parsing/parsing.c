/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:59 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 18:20:43 by meshahrv         ###   ########.fr       */
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

int	parse_files(t_data *data, char *av)
{
	int		read_line;
	char	buf[1];

	if (file_extension(av, ".cub") == 1)
	{
		parse_error("Wrong file extension");
		return (0);
	}
	data->fd = open(av, __O_DIRECTORY);
	if (data->fd >= 0)
		return (close(data->fd), 1);
	data->fd = open(av, O_RDONLY);
	if (data->fd <= 0)
	{
		printf("%s%sError:%s Can't open file\n", RED, BOLD, NC);
		return (0);
	}
	read_line = read(data->fd, buf, 1);
	if (read_line <= 0)
	{
		printf("%s%sError:%s Wrong file\n", RED, BOLD, NC);
		close(data->fd);
		return (0);
	}
	return (1);
}

void	check_textures(t_data *data, char *line)
{
	(void)data;
	// int	i;
	// verifier id + path

	
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
	 //put mlx to image sur le path line + 3
	 // si ca plante, fre (line) return error
		dprintf(2, "line = %s", line + 3);
	}
	
	// si ligne vide : vider la ligne
	// si caractere invlide : vider ligner + return error
	// int	i;

	// data->textures->count = 0;
	// i = 0;
}
void	get_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->texture.tab[i] = get_next_line(data->fd);
		if (!data->texture.tab[i])
		{
			close(data->fd);
			return ;
		}
		dprintf(2, "first line = %s", data->texture.tab[i]);
		if (data->texture.tab[i][0] == '\n')
			free(data->texture.tab[i]);
		else
		{
			check_textures(data, data->texture.tab[i]);
			i++;
		}
	}
}
