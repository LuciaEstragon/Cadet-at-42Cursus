/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dictionary_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:16 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/29 20:50:01 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_dictionary_content.h"

void	find_numb(char *nmb, char *dictionary)
{
	int	ind;
	int	ind_nmb;
	int	flag;

	ind = 1;
	ind_nmb = 0;
	flag = 0;
	while (dictionary[ind] != '\0')
	{
		while (dictionary[ind] == nmb[ind_nmb])
		{
			ind_nmb++;
			ind++;
			if (nmb[ind_nmb] == '\0' && dictionary[ind] == ':'
				&& dictionary[ind - 1 - ind_nmb] == '\n')
				flag = print_numb(ind, dictionary);
		}
		ind++;
		ind_nmb = 0;
	}
	if (!flag)
		no_printable_num(nmb, dictionary);
}

int	print_numb(int save_ind, char *dictionary)
{
	int		ind;
	char	letter;

	ind = save_ind + 2;
	letter = 'c';
	while (dictionary[ind] != '\n')
	{
		letter = dictionary[ind];
		write(1, &letter, 1);
		ind++;
	}
	return (1);
}
