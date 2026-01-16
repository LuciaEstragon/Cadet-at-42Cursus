/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:06:13 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/09 19:11:19 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_free(char *str)
{
	int	len;

	len = ft_putstr(str);
	free(str);
	return (len);
}

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
	if (nb < 0)
	{
		write(1, "(null)", 6);
		return (0);
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (i);
}
