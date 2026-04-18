/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/13 20:47:25 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst)
{
	int	length;

	length = stack_length(*stack_a);
	if (length <= 3)
		sort_three(stack_a, oplst);
	else if (length <= 5)
		sort_five(stack_a, stack_b, oplst);
	else
		big_sort(stack_a, stack_b, oplst);
}
