/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dictionary_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:23:15 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/29 23:36:19 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_dictionary_content.h"
#include <stdio.h>

int	str_len(char *nmb)
{
	int	len;

	len = 0;
	while (nmb[len] != '\0')
		len++;
	return (len);
}

void	no_printable_num(char *nmb, char *dictionary)
{
	char	*digit;
	int		ind;
	char	*a;
	char	*b;

	b = "";
	digit = malloc(sizeof(int) * str_len(nmb));
	// digit[0] = nmb[0];
	// if (digit[0] != '1')
	// {
	// 	b = &nmb[0];
	// 	digit[0] = '1';
	// }
	a = "0";
	ind = 1;
	while (ind < str_len(nmb))
	{
		digit[ind] = *a;
		ind++;
	}
	// find_numb(b, dictionary);
	// write(1, " ", 1);
	find_numb(digit, dictionary);
	write(1, " ", 1);
	find_numb(&nmb[1], dictionary);
}
