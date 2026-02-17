/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/16 19:13:20 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEX_UP "0123456789ABCDEF"
#define HEX_DOWN "0123456789abcdef"
#define DEC "0123456789"

static int	function_types(char const *s, va_list arg)
{
	unsigned long long	ptr;

	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'c')
		return (ft_putchar((char) va_arg(arg, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (*s == 'u')
		return (ft_putnbr_pos(va_arg(arg, unsigned int)));
	if (*s == 'x')
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), HEX_DOWN)));
	if (*s == 'X')
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), HEX_UP)));
	if (*s == 'p')
	{
		ptr = va_arg(arg, unsigned long long);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		write(1, "0x", 2);
		return (ft_putstr_free(ft_itoa_base_ptr(ptr, HEX_DOWN)) + 2);
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		count;
	va_list	arg_ptr;

	count = 0;
	va_start(arg_ptr, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			count = count + function_types(s, arg_ptr);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, s, 1) != 1)
				return (-1);
			count++;
		}
		s++;
	}
	va_end(arg_ptr);
	return (count);
}
