/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:42:16 by meshahrv          #+#    #+#             */
/*   Updated: 2023/01/02 17:18:47 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/garbage.h"

void	set_garb_lst(t_list **garb_list, void *alloc)
{
	if (garb_list == NULL)
		*garb_list = ft_lstnew(alloc);
	else
		ft_lstadd_back(garb_list, ft_lstnew(alloc));
}

void	*garbage_alloc(t_list **garb_list, int size)
{
	void	*alloc;

	alloc = ft_calloc(1, size);
	if (!alloc)
		return (NULL);
	set_garb_lst(garb_list, alloc);
	return (alloc);
}
/* ---------- TEST ---------- 
typedef struct test
{
	int a;
	char *b;
	float c;
}	t_test;

int main(void)
{
	t_list	*g_lst;
	t_test	*test;
	

	g_lst = NULL;
	test = NULL;
	test = (t_test *)garbage_alloc(&g_lst, sizeof(t_test));
	// print_node(g_lst);
	test->a = 10;
	test->b = garbage_alloc(&g_lst, sizeof(char) * strlen("test"));
	test->c = 1.2;
	ft_lstclear(&g_lst, &free);
}
  ---------- END ----------*/