/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/13 20:15:28 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_oplst	*oplst;

	stack_a = NULL;
	stack_b = NULL;
	oplst = NULL;
	if (argc < 2)
		return (0);
	stack_a = check_and_save(argc, argv);
	indexize(stack_a);
	sort(&stack_a, &stack_b, &oplst);
	clear_stack(&stack_a);
	print_oplst(oplst);
	clear_oplst(&oplst);
	return (0);
}
/*
Si necesito comprobar cosas:
	print_stack(stack_a); // LEG
Asi veo que lleva el stack en cada momento
*/

/*
# 1. Error handling
./push_swap 1 a          # → "Error"
./push_swap 1 2 1        # → "Error"
./push_swap              # → (nada)
./push_swap 1 2 3 4      # → (nada)

# 2. Corrección
ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG   # → "OK"

# 3. Conteo de instrucciones
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l   # → debe ser ≤ 12
ARG="100 números aleatorios"; ./push_swap $ARG | wc -l   # → debe ser < 1500
*/
