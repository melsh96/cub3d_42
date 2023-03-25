/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 01:35:13 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:26:02 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr(s1, i, len + 1 - i);
	return (str);
}

// #include <stdio.h>

// int main()
// {
//     char    *res;
//     char const  *s1;
//     char const  *set; 
//     s1 = "Yello Hello ! Yello";
//     set = "Yelo";
//     res = ft_strtrim(s1, set);
//     printf("%s\n", res);
//     return (0);
// }