/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 00:37:43 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:26:07 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	src_len;

	i = -1;
	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (!len || src_len <= start)
		return (ft_strdup(""));
	if (len < src_len - start)
		dest = malloc(sizeof(char) * (len + 1));
	else
		dest = malloc(sizeof(char) * (src_len - start + 1));
	if (dest == NULL)
		return (NULL);
	if (start < src_len)
	{
		while (++i < len && s[start + i] != '\0')
			dest[i] = s[start + i];
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
//     char const	*str = "substr function Implementation";
//     char	*res;

//     res = ft_substr(str, 24, 15);
// 	printf("%s\n", res);
// 	return (0);
// }

// int main()
// {
//     char src[] = "substr function Implementation";
//     int m = 7;
//     int n = 12;
//     char* dest = ft_substr(src, m, n);
//     printf("%s\n", dest);
//     return 0;
// }