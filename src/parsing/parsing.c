/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:59 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/29 18:09:05 by meshahrv         ###   ########.fr       */
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

int	parse_files(char *av)
{
	int		fd;
	int		read_line;
	char	buf[1];

	if (file_extension(av, ".cub") == 1)
	{
		parse_error("Wrong file extension");
		return (0);
	}
	fd = open(av, __O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		printf("%s%sError:%s Can't open file\n", RED, BOLD, NC);
		return (0);
	}
	read_line = read(fd, buf, 1);
	if (read_line <= 0)
	{
		if (read_line == 0)
			printf("%s%sError:%s The file is empty\n", RED, BOLD, NC);
		else if (read_line < 0)
			printf("%s%sError:%s Wrong file\n", RED, BOLD, NC);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
