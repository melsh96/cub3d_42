/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:41:11 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:24:37 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;	
// 	str = ft_strdup("Start Stop");
// 	printf("%s\n", str);

// same as memcpy
// ft_memmove(str, str + 6, 4);
// printf("%s\n", str);

// let's move art at the begining of the string
// 	ft_memcpy(str, str + 2, 3);
// 	printf("ft_memcpy : %s\n", str);
// 	ft_memmove(str, str + 2, 3);
// 	printf("ft_memmove : %s\n", str);
// 	memmove(str, str + 2, 3);
// 	printf("memmove : %s\n", str);

// 	return (0);
// }