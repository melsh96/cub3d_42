/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 17:00:49 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// ^Main Program
/*
- Init structure
- Check nbr or args
- Ckeck file
- Check map 
*/

int	main(int ac, char **av)
{
	t_data	data;

	init_map(&data);
	if (ac != 2)
		parse_error("Wrong number of arguments");
	if (!parse_files(&data, av[1]))
		return (1);
	get_textures(&data);
	// if (!get_map(&data, av[1]))
	// 	return (1);
	return (0);
}
