/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:41 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 19:19:36 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		ft_putstr_fd(map->tab[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_map_texture(t_texture *texture)
{
	int	i;

	i = 0;
	while (texture->tab[i])
	{
		ft_putstr_fd(texture->tab[i], 1);
		i++;
	}
	// ft_putchar_fd('\n', 1);
}