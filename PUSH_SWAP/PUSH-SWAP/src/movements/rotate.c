/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:18:59 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	operation_ra(t_stack **stack, t_oplst **oplst)
{
	rotate(stack);
	add_op(oplst, RA);
}

void	operation_rb(t_stack **stack, t_oplst **oplst)
{
	rotate(stack);
	add_op(oplst, RB);
}

void	operation_rr(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	rotate(stack_a);
	rotate(stack_b);
	add_op(oplst, RR);
}
