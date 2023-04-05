/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/05 18:35:14 by cchapon          ###   ########.fr       */
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

void free_texture_tab(t_data *data)
{
	int	i;
	i = 0;
	while (i < 6)
	{
		
		free(data->texture[i].path);
		free(data->texture[i].id);
		free(data->texture[i].addr);
		i++;
	}
}

int	destroy_cub(t_data *data)
{
	free_double_tab(data->map.tab, (size_t)data->map.height);
	//free_texture_tab(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	close (data->fd);
	free(data->mlx);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		parse_error("Wrong number of arguments");
	init_map(&data);
	parse_files(&data, av[1]);
	get_textures(&data, av[1]);
	get_map(&data);
	init_data(&data);
	int i = 0;
	while (i < 6)
	{
		printf("%d : path= %s, id= %s, addr= %s\n", i, data.texture[i].path, data.texture[i].id, data.texture[i].addr);
		i++;
	}

	return (0);
}
