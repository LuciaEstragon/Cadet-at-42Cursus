/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:18:34 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	operation_rra(t_stack **stack, t_oplst **oplst)
{
	reverse_rotate(stack);
	add_op(oplst, RRA);
}

void	operation_rrb(t_stack **stack, t_oplst **oplst)
{
	reverse_rotate(stack);
	add_op(oplst, RRB);
}

void	operation_rrr(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	add_op(oplst, RRR);
}
