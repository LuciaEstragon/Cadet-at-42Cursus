/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:34:32 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/18 10:20:37 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	//char	mensaje[12];
	int	vector[10] = { 4, 3, 2, 1, 4, 5, 6, 7, 1, 1 };
	int	*tab;

	tab = &vector[0];
	//tab = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ft_sort_int_tab(tab, 10);

/*
	while (*tab != '\0')
	{
		int num_char;
		num_char = *tab + '0';
		write(1, &num_char, 1);
		tab++;
	}
*/
	int ind=0;
	while (ind<10)
	{
		char num_char;
                num_char = tab[ind] + '0';
                write(1, &num_char, 1);
		ind++;
	}
	return (0);
}
