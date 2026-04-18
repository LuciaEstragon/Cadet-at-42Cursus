/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:35:26 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/13 20:41:46 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	ind;
	int		neg;
	int		res;

	ind = 0;
	while (str[ind] != '\0'
		&& ((str[ind] == ' ') || (str[ind] == '\f') || (str[ind] == '\n')
			|| (str[ind] == '\r') || (str[ind] == '\t') || (str[ind] == '\v')))
		ind++;
	neg = 1;
	if (str[ind] != '\0' && ((str[ind] == '+') || (str[ind] == '-')))
	{
		if (str[ind] == '-')
			neg = -1;
		ind++;
	}
	res = 0;
	while (ind < (ft_strlen(str)) && ft_isdigit(str[ind]))
	{
		res = res * 10 + str[ind] - '0';
		ind++;
	}
	res = res * neg;
	return (res);
}
/*
LEG - nota de lestrada - FALLO

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	ind;
	int		neg;
	int		res;

	ind = 0;
	while (str[ind] != '\0'
		&& ((str[ind] == ' ') || (str[ind] == '\f') || (str[ind] == '\n')
			|| (str[ind] == '\r') || (str[ind] == '\t') || (str[ind] == '\v')))
		ind++;
	neg = 1;
	if (str[ind] != '\0' && ((str[ind] == '+') || (str[ind] == '-')))
	{
		if (str[ind] == '-')
			neg = -1;
		ind++;
	}
	res = 0;
	while (ind < (ft_strlen(str)) && ft_isdigit(str[ind]))
	{
		res = res * 10 + str[ind] - '0';
		ind++;
	}
	res = res * neg;
	return (res);
}

int main()
{
    printf("%d", ft_atoi("2147483649"));

    return 0;
}
	
FALLO: a partir del 48 no imprime bien
int main()
{
    printf("%d", ft_atoi("2147483648")); // FAIL

    return 0;
}
*/
