/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/05 20:02:00 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	function_types(char const *s, va_list arg)
{
	char	*hex;
	int		ret_c;

	ret_c = 0;
	if (*s == '%')
		ret_c = ft_putchar('%');
	if (*s == 'd' || *s == 'i')
		ret_c = ft_putnbr(va_arg(arg, int));
	if (*s == 'c')
		ret_c = ft_putchar((char) va_arg(arg, int));
	if (*s == 's')
		ret_c = ft_putstr(va_arg(arg, char *));
	if (*s == 'u')
		ret_c = ft_putnbr(va_arg(arg, unsigned int));
	if (*s == 'x')
	{
		hex = ft_itoa_base(va_arg(arg, int), 16);
		ret_c = ft_putstr(hex);
	}
	if (*s == 'p')
	{
		hex = ft_itoa_base(va_arg(arg, int), 16);
		write(1, "0x", 2);
		ret_c += 2;
		ret_c = ft_putstr(hex);
	}
	return (ret_c);
}
/*
	if (*s == 'X')
	{
		hex = ft_itoa_base(va_arg(arg, int), 16);
		//hacer con el mapi o el iteri y el toupper
		ft_putstr(hex);
	}
*/

int	ft_printf(char const *s, ...)
{
	int		count;
	va_list	arg_ptr;
	va_list	args_copy;

	count = 0;
	va_start(arg_ptr, s);
	va_copy(args_copy, arg_ptr);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			count = function_types(s, args_copy);
		}
		else
			write(1, s, 1);
		s++;
	}
	va_end(arg_ptr);
	va_end(args_copy);
	return (0);
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
