/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:19:58 by meshahrv          #+#    #+#             */
/*   Updated: 2023/01/02 17:21:41 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/ft_printf.h"

int	check_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_printfchar(va_arg(ap, int));
	else if (c == 's')
		count = ft_printfstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'p')
		count = ft_putptr(va_arg(ap, unsigned long));
	else if (c == 'u')
		count = ft_putnbr_u(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = ft_putptr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = ft_putptr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count = ft_printfchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		chr;
	va_list	ap;
	int		i;

	i = 0;
	chr = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			chr += check_format(format[i + 1], ap);
			i++;
		}
		else
			chr += ft_printfchar(format[i]);
		i++;
	}
	va_end(ap);
	return (chr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	nb;

// 	nb = -1;
// 	ft_printf("melo: %x\n", nb);
// 	printf("real printf: %x\n", nb);
// 	return (0);
// }

// int    main(void)
// {
//     void *str = -1;
//     void *n = NULL;

//    printf("melo: %d\n", ft_printf("%p\n %p\n", str, n));
//    printf("vrai: %d\n", printf("%p\n %p\n", str, n));
//     return (0);
// }

// int	main(void)
// {
// 	unsigned int *str = LONG_MAX;

// 	printf("melo: %d\n", ft_printf("%u\n", str));
// 	printf("vrai: %d\n", printf("%u\n", str));
// 	return (0);
// }
