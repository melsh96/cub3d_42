/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:40:55 by meshahrv          #+#    #+#             */
/*   Updated: 2023/02/14 17:58:18 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "libft.h"

void	*garbage_alloc(t_list **garb_list, int size);
void	set_garb_lst(t_list **garb_list, void *alloc);

#endif
