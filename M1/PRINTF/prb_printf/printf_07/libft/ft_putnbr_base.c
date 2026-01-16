/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:25:02 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/28 15:37:35 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


/* NO FUNCIONA*/
int	ft_putnbr_base(int nb, int base)
{
	char	c;
	int		count;

	c = '0';
	count = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		count++;
	}
	if (nb > base -1)
		count += ft_putnbr_base(nb / base, base);
	c = (nb % base) + '0';
	write(1, &c, 1);
	return (count);
}
