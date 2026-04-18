/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:19 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/18 10:21:31 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	aux;
	int	index;

	index = 0;
	while (index < size -1)
	{
		if (tab[index] > tab[index + 1])
		{
			aux = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = aux;
			index = 0;
		}
		else
			index++;
	}
}
