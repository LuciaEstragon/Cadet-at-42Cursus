/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2025/11/26 12:42:46 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
var_type va_arg(va_list arg_ptr, var_type);
void va_copy(va_list dest, va_list src);
void va_end(va_list arg_ptr);
void va_start(va_list arg_ptr, variable_name);
void va_start(arg_ptr); 
*/

/* 
LIB
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
void	ft_putnbr(int nb)
{
	char	c;

	c = '0';
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}



static void	funcion_conversiones(char const *s, va_list arg)
{
	int	var_type_d;
	//char	var_type_c;
	//char	*var_type_s;

	var_type_d = 0;
	if(*s == ' ')
		write(1, "% ", 2);

	if(*s == 'd')
	{
		var_type_d = va_arg(arg, int);
		ft_putnbr(var_type_d);
		
	}
	/*if(*s == 'c')
	{
		var_type_c = va_arg(arg, char);
		ft_putchar(var_type_c);
	}
	*/
	/*if(*s == 's')
		var_type_s = va_arg(arg_ptr, char *);
		*/
}
int ft_printf(char const *s, ...)
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

int main(void)
{
	ft_printf("Hola Mundo \n");
	//printf("\n");
	ft_printf("Hola Mundo 5 \n");
	//printf("\n");
	ft_printf("Hola % Mundo % dnada \n");
	//printf("\n");
	/*char	letter;
	letter = 'L';
	ft_printf("Hola Mundo %c", letter);
	printf("\n");*/
	int	numero;
	numero = 55483;
	ft_printf("Hola Mundo %d", numero);
	printf("\n");
	printf("FIN \n");
	return (0);
     
}
