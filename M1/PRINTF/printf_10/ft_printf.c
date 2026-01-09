/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:28 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/09 15:30:43 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	ft_putstr_free(char *str)
{
	int	len;

	len = ft_putstr(str);
	free(str);
	return (len);
}

static int	digit_count(unsigned long long nb, int base)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb != 0)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}

char	*ft_itoa_base_ptr(unsigned long long nb, char *base_set)
{
	char	*str;
	int		len_nmb;
	int		base;

	base = 16;
	len_nmb = digit_count(nb, base);
	str = (char *)calloc((len_nmb + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
	{
		str[0] = base_set[0];
		return (str);
	}
	// Llenamos la cadena de atrás hacia adelante
	while (nb != 0)
	{
		len_nmb--; // Decrementamos antes de asignar
		str[len_nmb] = base_set[nb % base];
		nb = nb / base;
	}
	return (str);
}


static int	function_types(char const *s, va_list arg)
{
	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'd' || *s == 'i')
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), "0123456789")));
	if (*s == 'c')
		return (ft_putchar((char) va_arg(arg, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*s == 'u')
		return (ft_putnbr_pos(va_arg(arg, unsigned int)));
	if (*s == 'x')
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), "0123456789abcdef")));
	if (*s == 'X')
		return (ft_putstr_free(ft_itoa_base(va_arg(arg, int), "0123456789ABCDEF")));
	/*if (*s == 'p')
	{
		if(va_arg(arg, int) == 0)
			return (ft_putstr_free(ft_strdup("(nil)")));
		write(1, "0x", 2);
		return (ft_putstr_free(ft_itoa_base_ptr(va_arg(arg, unsigned long long), "0123456789abcdef")) + 2);
	}*/
	if (*s == 'p')
	{
	    unsigned long long ptr = va_arg(arg, unsigned long long); // Solo una llamada

    	if (ptr == 0)
    	    return (ft_putstr_free(ft_strdup("(nil)")));
    	write(1, "0x", 2);
    	return (ft_putstr_free(ft_itoa_base_ptr(ptr, "0123456789abcdef")) + 2);
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

