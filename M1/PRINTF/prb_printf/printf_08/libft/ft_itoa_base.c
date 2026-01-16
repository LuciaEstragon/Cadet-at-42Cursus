/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:05 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/08 11:32:38 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	digit_count(long long nb, int base);

//convertir un número entero (int) en una cadena de texto (char *)
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
}

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
