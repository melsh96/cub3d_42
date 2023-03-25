/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:44:33 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:34 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

// #include <stdio.h>

// void	print_node(t_list *node)
// {
// 	printf("content : %i ->", (*(int *)(node->content)));
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*new;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	node1 = ft_lstnew(&a);
// 	node2 = ft_lstnew(&b);
// 	new->content = &c;
// 	node1->next = node2;
// 	node2->next = NULL;
// 	new->next = NULL;

// 	ft_lstadd_back(&node1, new);
// 	while (node1)
// 	{
// 		print_node(node1);
// 		node1 = node1->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstdelone(new, delete);
// 	return (0);
// }
