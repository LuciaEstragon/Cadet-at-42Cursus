/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:19 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/17 20:37:25 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	small_index;
	int	aux;
	int	index;

	index = 0;
	small_index = tab[index];
	while (index <= size)
	{
		if (tab[index] < small_index)
			small_index = tab[index];
		index++;
	}
	index = 0;
	do
	{
		if (tab[index] > tab[index + 1])
		{
			aux = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = aux;
			index++;
		}
	} while (tab[index] != small_index);
}
