/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 21:54:59 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	operation_pa(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	push(stack_b, stack_a);
	add_op(oplst, PA);
}

void	operation_pb(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	push(stack_a, stack_b);
	add_op(oplst, PB);
}
