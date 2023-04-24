/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:41 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/17 13:11:28 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	parse_error(t_data *data, char *msg)
{
	close(data->fd);
	if (data->map.tab)
		free_double_tab(data->map.tab, (size_t)data->map.height);
	free_texture(data);
	printf("%s%sError:%s %s\n", RED, BOLD, NC, msg);
	exit(1);
}

void	print_tab(char **tab, int tab_length)
{
	int	i;

	i = 0;
	while (i < tab_length)
	{
		ft_putstr_fd(tab[i], 1);
		i++;
	}
}

void	print_texture(t_data *data)
{
	int i;

	i = 0;
	while (&data->texture[i])
	{
		printf("i = %d\npath = %s ; id = %s ; addr = %s\n", i, data->texture[i].path, \
		data->texture[i].id, \
		data->texture[i].ad);
		i++;
	}
}

void	read_free_all_gnl(char *tmp, int fd)
{
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

void	free_params(char **tab)
{
	size_t	idx;

	idx = 0;
	while (idx < 6)
	{
		free(tab[idx]);
		idx++;
	}
}

void	free_double_tab(char **tab, size_t len)
{
	(void)len;
	size_t	idx;

	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	if (tab)
		free(tab);
}

void	free_double_tab_len(char **tab, size_t len)
{
	// (void)len;
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (tab && tab[idx])
			free(tab[idx]);
		idx++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}