/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/13 20:47:32 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Comprueba los parametros de entrada y si estan correctos crea la lista stack_a.

ENTRADA VALIDA:
./push_swap 1 5 "4 24 7" "10" 6
Cuatro argumentos: controlar con un split + itoa. Check errores entrada.

ERRORES DE ENTRADA A CONTROLAR:
1. No duplicidad de numeros
2. No existan char/str, solo numeros.
3. Numeros no sean mayor que INT_MAX.
NOTAS
1*. si la cadena viene vacia, no es error, pero tiene que salir del programa
2*. si la cadena viene ordenada, no es error, pro tiene que salir del programa
3*. en las funciones is_*() el return 0 es NO, el return 1 es SI.  
	// si es alfa retorno 0

IDEA DE MEJORA:
Podria mejorarse si tambien aceptase ficheros y entrada de texto.
*/

#include "push_swap.h"
#include <limits.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int	is_valid(char *str)
{
	int	num;
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (!(num >= 0 && num <= INT_MAX))
		return (0);
	return (1);
}

int	is_repeat(t_stack *stack, int num)
{
	while (stack)
	{
		if (num == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_ordered(t_stack *stack)
{
	int	num;
	int	flag;

	num = stack->value;
	flag = 1;
	while (stack)
	{
		if (num <= stack->value && flag == 1)
			num = stack->value;
		else
		{
			flag = 0;
			break ;
		}
		stack = stack->next;
	}
	return (flag);
}

void	error(t_stack **stack, char **split)
{
	clear_stack(stack);
	if (split != NULL)
		write(STDERR, "Error\n", 6);
	ft_free_strarray(split);
	exit(0);
}

t_stack	*check_and_save(int argc, char **argv)
{
	t_stack	*temp_stack;
	char	**split_arg;
	int		ind_argc;
	int		i;

	temp_stack = NULL;
	ind_argc = 1;
	while (ind_argc < argc)
	{
		split_arg = ft_split(argv[ind_argc], ' ');
		i = 0;
		while (split_arg[i])
		{
			if (!is_valid(split_arg[i])
				|| is_repeat(temp_stack, ft_atoi(split_arg[i])))
				error(&temp_stack, split_arg);
			ft_stkadd_end(&temp_stack, ft_atoi(split_arg[i]));
			i++;
		}
		ft_free_strarray(split_arg);
		ind_argc++;
	}
	if (is_ordered(temp_stack))
		error(&temp_stack, NULL);
	return (temp_stack);
}
