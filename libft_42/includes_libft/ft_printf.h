/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:18:21 by meshahrv          #+#    #+#             */
/*   Updated: 2023/01/02 17:22:56 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printflen(char *str);
int	ft_printf(const char *format, ...);
int	ft_printfchar(char c);
int	ft_printfstr(char *str);
int	ft_putptr(unsigned long int str);
int	ft_putptr_base(unsigned long int nb, char *base);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr_u(unsigned int n);

#endif