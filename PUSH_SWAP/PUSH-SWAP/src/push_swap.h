/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/04/08 22:38:57 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

// pilas - las listas con los numeros
typedef struct s_stack
{
	int				value;// valor numero = contenido de la lista
	int				id;// posicion que ocupa en la lista
	struct s_stack	*next;// apunta al nodo siguiente
}	t_stack;

// estructura para guardar los movimientos
typedef struct s_oplist
{
	int				op;
	struct s_oplist	*nx;
}	t_oplst;

// check_error//
t_stack	*check_and_save(int argc, char **argv);
// check_error//
void	indexize(t_stack *stack);
// operation_stack//
void	ft_stkadd_end(t_stack **lst, int valor);
t_stack	*ft_stknew(int content);
void	print_stack(t_stack *list);
void	clear_stack(t_stack **stack);
int		stack_length(t_stack *stack);
// sorting_algorithms//
void	sort(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	sort_three(t_stack **stack_a, t_oplst **oplst);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	big_sort(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
// operation_list//
void	print_oplst(t_oplst *list);
void	clear_oplst(t_oplst **list);
void	add_op(t_oplst **list, int op_nb);
void	operation_sa(t_stack **stack, t_oplst **oplst);
void	operation_sb(t_stack **stack, t_oplst **oplst);
void	operation_ss(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	operation_ra(t_stack **stack, t_oplst **oplst);
void	operation_rb(t_stack **stack, t_oplst **oplst);
void	operation_rr(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	operation_rra(t_stack **stack, t_oplst **oplst);
void	operation_rrb(t_stack **stack, t_oplst **oplst);
void	operation_rrr(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	operation_pa(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
void	operation_pb(t_stack **stack_a, t_stack **stack_b, t_oplst **oplst);
// movements//
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **orig, t_stack **dest);
// OTHER//
int		ft_sqrrt(int nb);

#endif
