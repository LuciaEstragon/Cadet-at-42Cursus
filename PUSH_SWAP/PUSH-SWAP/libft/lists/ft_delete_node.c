/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:35:26 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 21:24:10 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_node(t_list **node)
{
	t_list	*current;
	t_list	*next;

	current = *node;
	next = current->next;
	free(current);
	*node = next;
}
