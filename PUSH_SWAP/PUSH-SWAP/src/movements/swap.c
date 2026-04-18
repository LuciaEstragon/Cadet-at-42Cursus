/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:18:55 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	operation_sa(t_stack **stack, t_oplst **oplst)
{
	swap(stack);
	add_op(oplst, SA);
}

void	operation_sb(t_stack **stack, t_oplst **oplst)
{
	swap(stack);
	add_op(oplst, SB);
}

void	operation_ss(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	swap(stack_a);
	swap(stack_b);
	add_op(oplst, SS);
}
