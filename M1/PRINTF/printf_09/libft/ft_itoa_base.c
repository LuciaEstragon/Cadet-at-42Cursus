/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:05 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/09 11:53:47 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ITOA = convertir un número entero (int) en una cadena de texto (char *)
#include <stdlib.h>
#include <stdio.h>

static int	digit_count(long long nb, int base);


/* METODO ANTIGUO (le pasas base como un int y no como un char)
char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*digits;
	int		len_nmb;
	long long	nb;

	digits = "0123456789abcdef";
	nb = n;
	if (nb < 0 && base == 16)
		nb = 4294967295 + nb + 1;
	len_nmb = digit_count(nb, base);
	str = (char *)calloc((len_nmb + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0 && base == 10)
	{
		str[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		len_nmb--;
		str[len_nmb] = digits[nb % base];
		nb = nb / base;
	}
	return (str);
}*/


/* FUNCIONA PERO TIENE 28 LINEAS*/
char	*ft_itoa_base(int n, char *base_set)
{
	char		*str;
	int			len_nmb;
	int			base;
	long long	nb;

	base = 0;
	while (base_set[base])
		base++;
	nb = n;
	if (nb < 0 && base == 16)
		nb = (unsigned int)n;
	len_nmb = digit_count(nb, base);
	str = (char *)calloc((len_nmb + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0 && base == 10)
	{
		str[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		str[0] = base_set[0];
	while (nb != 0)
	{
		str[--len_nmb] = base_set[nb % base];
		nb = nb / base;
	}
	return (str);
}

/*ITOA NUEVO CON 22 lineas, PERO NO CUMPLE NORMINETTE - Ternarios*/
/*char	*ft_itoa_base(int n, char *base_set)
{
	char		*str;
	int			len;
	int			base;
	long long	nb;

	base = 0;
	while (base_set[base])
		base++;
	nb = (base == 16) ? (unsigned int)n : (long long)n;
	len = digit_count(nb, base);
	if (!(str = (char *)calloc((len + 1), sizeof(char))))
		return (NULL);
	if (nb == 0)
		str[0] = base_set[0];
	if (nb < 0 && base == 10 && (str[0] = '-'))
		nb = -nb;
	while (nb != 0)
	{
		str[--len] = base_set[nb % base];
		nb /= base;
	}
	return (str);
}*/
// char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

static int	digit_count(long long nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count = 1;
	while (nb != 0)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}
