/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:08:49 by meshahrv          #+#    #+#             */
/*   Updated: 2023/01/02 17:22:27 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/ft_printf.h"

int	ft_printflen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printfstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	else
	{
		i += ft_printfstr("0x");
		i += ft_putptr_base(n, "0123456789abcdef");
	}
	return (i);
}
