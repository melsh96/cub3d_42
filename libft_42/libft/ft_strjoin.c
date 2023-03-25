/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:54:34 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:25:29 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*str;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	str = res;
	while (*s1 != '\0')
		*res++ = *s1++;
	while (*s2 != '\0')
		*res++ = *s2++;
	*res = 0;
	return (str);
}

// #include <stdio.h>

// int main()
// {
//     char const *s1 = "Hello";
//     char const *s2 = " Yellow";
//     char *res;
//     res = ft_strjoin(s1, s2);
//     printf("%s\n", res);
//     return (0);
// }