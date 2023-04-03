/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/03 13:39:03 by cchapon          ###   ########.fr       */
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

	if (ac != 2)
		parse_error("Wrong number of arguments");
	init_map(&data);
	parse_files(&data, av[1]);
	get_textures(&data, av[1]);
	get_map(&data);
	free_double_tab(data.map.tab, (size_t)data.map.height);
	free_params(data.texture.tab);
	close (data.fd);
	return (0);
}
