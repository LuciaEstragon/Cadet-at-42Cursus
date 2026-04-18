/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:35:40 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crea un nuevo nudo a la lista
t_stack	*ft_stknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

// Añadir nodo al final de la lista
void	ft_stkadd_end(t_stack **lst, int valor)
{
	t_stack	*new_nodo;
	t_stack	*temp;

	new_nodo = ft_stknew(valor);
	if (*lst == NULL)
	{
		*lst = new_nodo;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_nodo;
	}
}

// Imprime la pila recorriéndola
void	print_stack(t_stack *list)
{
	while (list)
	{
		ft_printf("[%d] ", list->value);
		ft_printf("(%d) -> ", list->id);
		list = list->next;
	}
	write(1, "\n", 1);
}

// Liberar memoria
void	clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	stack_length(t_stack *stack)
{
	int	lenght;

	lenght = 0;
	while (stack != NULL)
	{
		lenght++;
		stack = stack->next;
	}
	return (lenght);
}
