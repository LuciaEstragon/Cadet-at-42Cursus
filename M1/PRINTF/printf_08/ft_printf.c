/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/08 13:20:52 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static char	wrapper_tolower(unsigned int i, char *c)
{
	(void)i;
	if (c)
		c = (char)ft_tolower((int)*c);
	return (c);
}*/


// Wrapper para ft_strmapi (retorna el char modificado)
char wrapper_upper_mapi(unsigned int i, char c) {
    (void)i; // Evita el warning de variable no usada
    return (char)ft_toupper((unsigned char)c);
}    // CON ESTO SALE, PERO FALTA HACER FREE_MAPI
// Wrapper para ft_striteri (modifica por puntero)
/*void wrapper_upper_iteri(unsigned int i, char *c) {
    (void)i;
    if (c)
        *c = (char)ft_toupper((unsigned char)*c);
}*/


static int	ft_putstr_free(char *str)
{
	int	len;

	len = ft_putstr(str);
	free(str);
	return (len);
}

static int	function_types(char const *s, va_list arg)
{
	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'd' || *s == 'i')
		//return(ft_putnbr(va_arg(arg, int))); --FUNCIONA
		//return (ft_putnbr_base(va_arg(arg, int), 10)); --FUNCIONA
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), 10)));
	if (*s == 'c')
		return (ft_putchar((char) va_arg(arg, int))); 
	if (*s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*s == 'u')
		return (ft_putnbr_pos(va_arg(arg, unsigned int))); //--variante del put_nmb
	if (*s == 'x')
		//return (ft_putnbr_base(va_arg(arg, int), 16)); --NO FUNCIONA
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), 16)));
	if (*s == 'X'){
		//return (ft_putnbr_base(va_arg(arg, int), 16)); --NO FuNCIoNA
		char *str_itoa = ft_itoa_base(va_arg(arg, int), 16);
		char *str_mapi = ft_strmapi(str_itoa, wrapper_upper_mapi);
		free(str_itoa);
		return (ft_putstr_free(str_mapi));
	}
	if (*s == 'p')
	{
		write(1, "0x", 2);
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), 16)) + 2);
	}
	return (0);
}
// char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

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
	printf("%d\n",ft_printf(" %s %s ", "Hola", " Mundo"));
	ft_printf(" %s %s ", "H", "O");
	
	ft_printf("%d  ", 10);
	ft_printf("%d \n", -52);
	printf("%d\n", ft_printf("%d", 0));
	
    ft_printf("%x, %X \n", 10, 10);
    ft_printf("%x, %X \n", -5, -5);
    ft_printf("%x, %X \n", 15, 15);
    ft_printf("%x, %X \n", -15, -15);
    ft_printf("%x, %X \n", 16, 16);
    ft_printf("%x, %X \n", -16, -16);
    return 0;
}*/

