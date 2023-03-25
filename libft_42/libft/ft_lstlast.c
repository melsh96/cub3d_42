/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:30:53 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:44 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
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
// 	t_list	*lst;
// 	t_list	*last;
// 	int		a;
// 	int		b;

// 	// node1 = malloc(sizeof(t_list));
// 	// node2 = malloc(sizeof(t_list));
// 	a = 1;
// 	b = 2;
// 	node1 = ft_lstnew(&a);
// 	node2 = ft_lstnew(&b);
// 	// node1->content = &a;
// 	// node2->content = &b;
// 	ft_lstadd_back(&node1, node2);
// 	lst = node1;
// 	while (node1)
// 	{
// 		print_node(node1);
// 		node1 = node1->next;
// 	}
// 	printf("NULL\n");
// 	last = ft_lstlast(lst);
// 	print_node(last);
// 	printf("NULL\n");
// 	printf("%i", ft_lstsize(lst));
// 	return (0);
// }
