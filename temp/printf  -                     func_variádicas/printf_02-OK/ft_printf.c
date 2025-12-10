/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/05 15:45:42 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

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
static void	funcion_conversiones(char const *s, va_list arg)
{
	int	var_type_d;
	char	var_type_c;
	char	*var_type_s;
	char	*hex;

	var_type_d = 0;
	if(*s == '%')
		write(1, "%", 1);
	if(*s == 'd' || *s == 'i')
	{
		var_type_d = va_arg(arg, int);
		ft_putnbr(var_type_d);
		
	}//float f = (float) va_arg(argptr, double);
	if(*s == 'c')
	{
		var_type_c = (char) va_arg(arg, int);
		ft_putchar(var_type_c);
	}
	
	if(*s == 's')
	{
		var_type_s = va_arg(arg, char *);
		ft_putstr(var_type_s);
	}
	
	if(*s == 'u')
	{
		var_type_d = va_arg(arg, int);
		if (var_type_d < 0)
			var_type_d = -var_type_d;
		ft_putnbr(var_type_d);
	}
	
	if(*s == 'x')
	{
		var_type_d = va_arg(arg, int);
		hex = ft_itoa_base(var_type_d, 16);
		ft_putstr(hex);
	}
	
	if(*s == 'X')
	{
		var_type_d = va_arg(arg, int);
		hex = ft_itoa_base(var_type_d, 16);
		//hacer con el mapi o el iteri y el toupper
		ft_putstr(hex);
	}
	//FALTA %p
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
			write(1, s, 1);  // ft_putstr(s);
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
	/*
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
    */
	return (0);
     
}

#include <stdio.h>

/*
Tipos enteros
int: Entero de tamaño predeterminado, generalmente de 32 bits.
short o short int: Entero de 16 bits, para un rango menor.
long o long int: Entero con un rango más amplio que int.
long long: Entero con aún mayor rango.
char: Aunque se usa principalmente para caracteres, también puede considerarse un tipo entero pequeño (generalmente de 8 bits).

Calificadores signed y unsigned:
signed: Permite valores tanto positivos como negativos (es el comportamiento por defecto para int, short y long).
unsigned: Permite solo valores no negativos, duplicando así el rango positivo del tipo (por ejemplo, unsigned int tiene un rango mayor que int positivo). 

Tipos de punto flotante
float: Punto flotante de precisión simple.
double: Punto flotante de precisión doble, con mayor rango y precisión que float.
long double: Punto flotante de precisión extendida, con aún mayor rango y precisión. 
*/
/*
int main()
{
    double num = -345.678;
    float numf = -345.678;
    int i10 = -345.678;
    unsigned int und = 345.678;
    int hex = 345678;
    int HEX = -345678;
    char let = 'a';
    char *str = "HolaMundo";

    printf("Hello World  num=%d, numf=%d %% \n", num, numf);
    printf("Hello World i10=%d, num=%d, numf=%d, und=%d, hex=%d, HEX=%d \n", i10, num, numf, und, hex, HEX);
    printf("\n");
    
    printf("Hello World  num=%x, numf=%X %% \n", hex, HEX);
    printf("Hello World i10=%x, num=%x, numf=%x, und=%x, hex=%x, HEX=%x \n", i10, num, numf, und, hex, HEX);
    printf("Hello World i10=%X, num=%X, numf=%X, und=%X, hex=%X, HEX=%X \n", i10, num, numf, und, hex, HEX);
    printf("\n");
    
    printf("Hello World  i10=%u, und=%u %% \n", i10, und);
    printf("Hello World i10=%u, num=%u, numf=%u, und=%u, hex=%u, HEX=%u \n", i10, num, numf, und, hex, HEX);
    printf("\n");
    
    return 0;
}*/
