/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:38:26 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_rot_cost(t_stack *stack, int nb)
{
	int	cost;

	cost = 0;
	while (stack && stack->id != nb)
	{
		stack = stack->next;
		cost++;
	}
	return (cost);
}

int	get_rev_rot_cost(t_stack *stack, int nb)
{
	return (stack_length(stack) - get_rot_cost(stack, nb));
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	int	small_pivot;
	int	big_pivot;

	small_pivot = 0;
	big_pivot = ft_sqrrt(stack_length(*stack_a)) * 1.4;
	while (*stack_a)
	{
		if ((*stack_a)->id <= small_pivot)
		{
			operation_pb(stack_a, stack_b, oplst);
			if (stack_length(*stack_b) > 1)
				operation_rb(stack_b, oplst);
			small_pivot ++;
		}
		else if ((*stack_a)->id <= small_pivot + big_pivot)
		{
			operation_pb(stack_a, stack_b, oplst);
			small_pivot ++;
		}
		else
			operation_ra(stack_a, oplst);
	}
}

void	return_to_a(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	int	rot_cost;
	int	rev_rot_cost;

	while (stack_length(*stack_b))
	{
		rot_cost = get_rot_cost(*stack_b, stack_length(*stack_b));
		rev_rot_cost = get_rev_rot_cost(*stack_b, stack_length(*stack_b));
		if (rot_cost <= rev_rot_cost)
		{
			while ((*stack_b)->id != stack_length(*stack_b))
				operation_rb(stack_b, oplst);
			operation_pa(stack_a, stack_b, oplst);
		}
		else
		{
			while ((*stack_b)->id != stack_length(*stack_b))
				operation_rrb(stack_b, oplst);
			operation_pa(stack_a, stack_b, oplst);
		}
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	push_to_b(stack_a, stack_b, oplst);
	return_to_a(stack_a, stack_b, oplst);
}
