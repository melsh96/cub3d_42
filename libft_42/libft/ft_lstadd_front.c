/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:37:14 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:26 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// void	print_node(t_list *list)
// {
// 	printf("content : %i ->", (*(int *)(list->content)));
// 	while (list)
// 	{
// 		print_node(list);
// 		list = list->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node;
// 	t_list	*new_node;
// 	int		a;
// 	int		b;
// 	int		c;

// 	head = malloc(sizeof(t_list));
// 	node = malloc(sizeof(t_list));
// 	new_node = malloc(sizeof(t_list));
// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	head->content = &a;
// 	node->content = &b;
// 	new_node->content = &c;
// 	head->next = node;
// 	node->next = NULL;
// 	new_node->next = NULL;
// 	ft_lstadd_front(&head, new_node);
// 	return (0);
// }
