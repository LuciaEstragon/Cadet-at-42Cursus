/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/19 20:12:54 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wrapper_toupper(unsigned int i, char *c)
{
	(void)i;
	if (c)
		*c = (char)ft_toupper((int)*c);
	return (c);
}

static int	function_types(char const *s, va_list arg)
{
	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (*s == 'c')
		return (ft_putchar((char) va_arg(arg, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*s == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (*s == 'x')
		return (ft_putstr(ft_itoa_base(va_arg(arg, int), 16)));
	if (*s == 'X')
		return (ft_putstr(ft_itoa_base(va_arg(arg, int), 16)));
		 //ft_strmapi(ft_itoa_base(va_arg(arg, int), 16), &wrapper_toupper)));
	if (*s == 'p')
	{
		write(1, "0x", 2);
		return (ft_putstr(ft_itoa_base(va_arg(arg, int), 16)) + 2);
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
/*
int main(void)
{
	ft_printf("Hola Mundo \n");
	//printf("\n");
	ft_printf("Hola Mundo 5 \n");
	//printf("\n");
	ft_printf("Hola % Mundo % dnada \n");
	//printf("\n");
	(/)char	letter;
	letter = 'L';
	ft_printf("Hola Mundo %c", letter);
	printf("\n");(/)
	int	numero;
	numero = 55483;
	ft_printf("Hola Mundo %d", numero);
	printf("\n");
	char	letter;
	letter = 'L';
	ft_printf("Hola Mundo %c", letter);
	printf("\n");
	char	*msg;
	msg = "Lucia";
	ft_printf("Hola Mundo %s", msg);
	printf("\n");
	ft_printf("Hola Mundo %d y 5 y % y %c jkskue %s", numero, letter, msg);
	printf("FIN \n");
	(/)
	double numd = -345.678;
	float numf = -345.678;
	int i10 = -345678;
	unsigned int und = 345678;
	int hex = 345678;
	int HEX = 345678;

	ft_printf("ALL_MIO \n i10=%d, i10=%i, \n numd=%d, numf=%d, numd=%i, numf=%i,
	\n und=%u, i10=%u, hex=%x, HEX=%X \n", i10, i10, numd, numf, numd, numf,
	und, i10, hex, HEX);
    printf("\n");
    printf("ALL_TXT \n i10=%d, i10=%i, \n numd=%d, numf=%d, numd=%i, numf=%i,
	\n und=%u, i10=%u, hex=%x, HEX=%X \n", i10, i10, numd, numf, numd, numf, 
	und, i10, hex, HEX);
    printf("\n");
    (/)
	return (0);
     
}*/
