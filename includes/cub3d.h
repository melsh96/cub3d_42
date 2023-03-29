/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:40 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/29 15:37:30 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft_42/includes_libft/libft.h"
# include "../libft_42/includes_libft/get_next_line_bonus.h"

# define NC		"\e[0m"
# define RED	"\e[31m"
# define BLUE	"\e[38;5;140m"
# define GREEN	"\e[38;5;150m"
# define BOLD	"\e[1m"

typedef struct s_map
{
	char	*line;
	char	**tab;
	int		width;
	int		height;
}	t_map;

// Main Program
int		main(int ac, char **av);

// Parsing
void	parse_error(char *msg);

// Utils
void	print_map(t_map *map);

#endif
