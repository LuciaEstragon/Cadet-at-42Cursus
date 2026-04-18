/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:39:37 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Los **movimientos permitidos** son los siguientes:

SWAP: intercambia el primer numero de la pila con el segundo numero de la pila.
PUSH: pasa el primer numero de la pila a a la primera posicion de la pila b.
ROTATE: el primer numero de la pila pasa a ser el último.
REVERSE: el último numero de la pila pasa a ser el primero.
*/

#include <push_swap.h>

/*SWAP*/
void	swap(t_stack **stack)
{
	t_stack	*nodo1;
	t_stack	*nodo2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	nodo1 = *stack;
	nodo2 = nodo1->next;
	nodo1->next = nodo2->next;
	nodo2->next = nodo1;
	*stack = nodo2;
}

/*ROTATE*/
void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*nodo1;
	t_stack	*nodo2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	nodo1 = *stack;
	nodo2 = nodo1->next;
	*stack = nodo2;
	nodo1->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = nodo1;
}

/*REVERSE*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*nodo1;
	t_stack	*pre_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	nodo1 = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = nodo1;
	*stack = last;
}

/*PUSH*/
void	push(t_stack **orig, t_stack **dest)
{
	t_stack	*buffer;

	if (*orig == NULL)
		return ;
	buffer = *orig;
	*orig = (*orig)->next;
	buffer->next = *dest;
	*dest = buffer;
}
