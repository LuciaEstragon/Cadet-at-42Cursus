/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:38:01 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/01 17:12:36 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int	letra = 'S';
	int	digit = 564;

	if (ft_isalpha(letra))
		write(1, "si", 2);
	else
		write(1, "no", 2);
	if (ft_isdigit(digit))
		write(1, "SI", 2);
	else
		write(1, "NO", 2);

	if (ft_isalnum(letra))
		write(1, "Si", 2);
	else
		write(1, "No", 2);
	if (ft_isprint(digit))
		write(1, "sI", 2);
	else
		write(1, "nO", 2);
		
	if (ft_isascii(digit))
		write(1, "SI", 2);
	else
		write(1, "NO", 2);
		
	write(1, &letra, 2);
	letra  = ft_toupper(letra);
	write(1, &letra, 2);
	letra = ft_tolower(letra);
	write(1, &letra, 2);
	return (0);
}

