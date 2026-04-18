/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 21:54:22 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_sqrrt(int nb)
{
	int	res;

	res = 1;
	while (res * res <= nb)
	{
		res ++;
	}
	return (res - 1);
}

int	ft_pow(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
