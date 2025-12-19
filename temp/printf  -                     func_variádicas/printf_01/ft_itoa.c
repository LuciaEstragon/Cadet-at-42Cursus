/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 07:56:07 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/22 17:26:01 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		digit_count(int nb, int base);

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*digits;
	int		len_nmb;
	long	nb;

	digits = "0123456789ABCDEF";
	nb = n;
	len_nmb = digit_count(nb, base);
	str = (char *)calloc((len_nmb + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
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

int	digit_count(int nb, int base)
{
	int		count;

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

int main()
{
	int num1 = 12345;
	int num2 = -54321;
	int num3 = 0;

	printf("Base 10: %s\n", ft_itoa_base(num1, 10));  // Salida: 12345
	printf("Base 16: %s\n", ft_itoa_base(num1, 16));  // Salida: 3039
	printf("Base 2: %s\n", ft_itoa_base(num1, 2));    // Salida: 11000000111001

	printf("Base 10 (negativo): %s\n", ft_itoa_base(num2, 10));  // Salida: -54321
	printf("Base 16 (negativo): %s\n", ft_itoa_base(num2, 16));  // Salida: -D431

	printf("Base 10 (cero): %s\n", ft_itoa_base(num3, 10));   // Salida: 0
	
	return 0;
}

