/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:10:03 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:24:25 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 1;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((*str1 == *str2) && (i++ < n))
	{
		str1++;
		str2++;
	}
	return ((int)(*str1 - *str2));
}

// #include <stdio.h>

// int ft_memcmp(const void *s1, const void *s2, unsigned int n)
// {
//     unsigned int i;
//     const char *ss1;
//     const char *ss2;

//     i = 0;
//     ss1 = s1;
//     ss2 = s2;
//     while ((ss1[i] || ss2[i]) && i < n)
//     {
//         if (ss1[i] != ss2[i])
//             return (ss1[i] - ss2[i]);
//         i++;
//     }
//     return (0);
// }

// int main(void)
// {
//     char str[] = "foo bar baz";
//     char str2[] = "foo bar baz";
//     printf("%d", ft_memcmp(str, str2, 5));
//     return (0);
// }
