/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:35:26 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:34:17 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Imprime la pila recorriéndola
void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("[%d] -> ", list->content);
		list = list->next;
	}
	write(1, "\n", 1);
}
// Usamos printf para debug rápido -> ft_printf mejor
//ft_putnmb(list->value);
