/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:41 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 19:14:10 by meshahrv         ###   ########.fr       */
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

void	print_texture(t_data *data)
{
	int	i;

	i = 0;
	while (&data->texture[i])
	{
		printf("i = %d\npath = %s ; id = %s ; \
		addr = %s\n", i, data->texture[i].path, \
		data->texture[i].id, \
		data->texture[i].ad);
		i++;
	}
}
