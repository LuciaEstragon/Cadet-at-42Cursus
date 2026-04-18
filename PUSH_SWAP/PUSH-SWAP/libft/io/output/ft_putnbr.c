/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:25:02 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 21:39:28 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int nb)
{
	char	c;
	int		i;

	c = '0';
	i = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
		return (i);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		i++;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (i);
}

int	ft_putnbr_pos(unsigned int nb)
{
	char	c;
	int		i;

	c = '0';
	i = 1;
	if (nb > 9)
		i += ft_putnbr_pos(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (i);
}
