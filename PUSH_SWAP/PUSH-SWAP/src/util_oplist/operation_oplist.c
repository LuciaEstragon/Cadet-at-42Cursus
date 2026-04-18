/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_oplist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:20:55 by ldel-val          #+#    #+#             */
/*   Updated: 2026/04/08 22:37:23 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_oplst	*last_op(t_oplst *list)
{
	if (!list)
		return (NULL);
	while (list->nx)
		list = list->nx;
	return (list);
}

t_oplst	*new_op(int op_nb)
{
	t_oplst	*node;

	node = (t_oplst *)malloc(sizeof(t_oplst));
	if (!node)
		return (NULL);
	node->op = op_nb;
	node->nx = NULL;
	return (node);
}

void	add_op(t_oplst **list, int op_nb)
{
	t_oplst	*node;

	node = new_op(op_nb);
	if (!node)
		return ;
	if (!*list)
	{
		node->nx = *list;
		*list = node;
	}
	else
		last_op(*list)->nx = node;
}

void	del_op(t_oplst **operation)
{
	t_oplst	*nx;

	nx = (*operation)->nx;
	free(*operation);
	*operation = nx;
}

void	clear_oplst(t_oplst **list)
{
	while (*list != NULL)
		del_op(list);
}
