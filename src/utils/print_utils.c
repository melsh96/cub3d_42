/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:41 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/10 16:38:21 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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