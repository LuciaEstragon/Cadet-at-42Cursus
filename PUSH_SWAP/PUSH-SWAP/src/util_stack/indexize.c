/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:29:33 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Pone un indice de la posicion real que ocupa en el stack cada valor
stack = [1, 5, 18, 6, 40, 2, 23]
stack_ordenado = [1, 2, 5, 6, 18, 23, 40]
                  |  |  |  |   |   |   |
indice_pos:  (id) 1  2  3  4   5   6   7
*/

#include <push_swap.h>

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*biggest_node(t_stack *stack)
{
	t_stack	*biggest;

	biggest = stack;
	while (stack != NULL)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*smallest_node(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	while (stack != NULL)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

//metodo de ordenacion
void	indexize(t_stack *stack)
{
	int		index;
	t_stack	*last_node;
	t_stack	*next_node;
	t_stack	*cursor;

	last_node = smallest_node(stack);
	last_node->id = 1;
	index = 2;
	while (last_node->value < biggest_node(stack)->value)
	{
		cursor = stack;
		next_node = biggest_node(stack);
		while (cursor != NULL)
		{
			if (cursor->value < next_node->value
				&& cursor->value > last_node->value)
				next_node = cursor;
			cursor = cursor->next;
		}
		next_node->id = index;
		last_node = next_node;
		index ++;
	}
}
