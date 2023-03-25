/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:46:26 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:22 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new;
	else
		last_node->next = new;
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

// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	new = malloc(sizeof(t_list));
// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	node1->content = &a;
// 	node2->content = &b;
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
// 	return (0);
// }
