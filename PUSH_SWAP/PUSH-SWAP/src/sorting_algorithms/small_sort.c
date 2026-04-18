/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:19:45 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack **stack_a, t_oplst **oplst)
{
	if ((*stack_a)->id == 1 && (*stack_a)->next->id == 2)
		return ;
	if ((*stack_a)->id == 1 && (*stack_a)->next->id == 3)
	{
		operation_sa(stack_a, oplst);
		operation_ra(stack_a, oplst);
	}
	else if ((*stack_a)->id == 2 && (*stack_a)->next->id == 1)
		operation_sa(stack_a, oplst);
	else if ((*stack_a)->id == 2 && (*stack_a)->next->id == 3)
		operation_rra(stack_a, oplst);
	else if ((*stack_a)->id == 3 && (*stack_a)->next->id == 2)
	{
		operation_sa(stack_a, oplst);
		operation_rra(stack_a, oplst);
	}
	else if ((*stack_a)->id == 3 && (*stack_a)->next->id == 1)
		operation_ra(stack_a, oplst);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	while (stack_length(*stack_a) > 3)
	{
		if ((*stack_a)->id > 3)
			operation_pb(stack_a, stack_b, oplst);
		else
			operation_ra(stack_a, oplst);
	}
	sort_three(stack_a, oplst);
	if ((*stack_b)->id == 5)
		operation_rb(stack_b, oplst);
	while (*stack_b)
	{
		operation_pa(stack_a, stack_b, oplst);
		operation_ra(stack_a, oplst);
	}
}
