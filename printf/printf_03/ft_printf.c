/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/05 18:40:48 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	funcion_conversiones(char const *s, va_list arg)
{
	int		var_type_d;
	char	var_type_c;
	char	*var_type_s;
	char	*hex;

	var_type_d = 0;
	if (*s == '%')
		write(1, "%", 1);
	if (*s == 'd' || *s == 'i')
	{
		var_type_d = va_arg(arg, int);
		ft_putnbr(var_type_d);
	}//float f = (float) va_arg(argptr, double);
	if (*s == 'c')
	{
		var_type_c = (char) va_arg(arg, int);
		ft_putchar(var_type_c);
	}
	if (*s == 's')
	{
		var_type_s = va_arg(arg, char *);
		ft_putstr(var_type_s);
	}
	if (*s == 'u')
	{
		var_type_d = va_arg(arg, int);
		if (var_type_d < 0)
			var_type_d = -var_type_d;
		ft_putnbr(var_type_d);
	}
	if (*s == 'x')
	{
		var_type_d = va_arg(arg, int);
		hex = ft_itoa_base(var_type_d, 16);
		ft_putstr(hex);
	}
	if (*s == 'X')
	{
		var_type_d = va_arg(arg, int);
		hex = ft_itoa_base(var_type_d, 16);
		//hacer con el mapi o el iteri y el toupper
		ft_putstr(hex);
	}
	if (*s == 'p')
	{
		var_type_d = va_arg(arg, int);
		hex = ft_itoa_base(var_type_d, 16);
		write(1, "00", 2);
		ft_putstr(hex);
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	arg_ptr;
	va_list	args_copy;

	va_start(arg_ptr, s);
	va_copy(args_copy, arg_ptr);

	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			funcion_conversiones(s, args_copy);
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

	ft_printf("ALL_MIO \n i10=%d, i10=%i, \n numd=%d, numf=%d, numd=%i, numf=%i, \n und=%u, i10=%u, hex=%x, HEX=%X \n", i10, i10, numd, numf, numd, numf, und, i10, hex, HEX);
    printf("\n");
    	printf("ALL_TXT \n i10=%d, i10=%i, \n numd=%d, numf=%d, numd=%i, numf=%i, \n und=%u, i10=%u, hex=%x, HEX=%X \n", i10, i10, numd, numf, numd, numf, und, i10, hex, HEX);
    printf("\n");
    (/)
	return (0);
     
}*/

