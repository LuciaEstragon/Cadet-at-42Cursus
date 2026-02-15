#ifndef LIBFT_REDO_H
# define LIBFT_REDO_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct      s_list
{
    int             value;  // valor numero = contenido de la lista
    int             id;     // posicion que ocupa en la lista
    struct s_list   *next;  // apunta al nodo siguiente
}                   t_stack;


///// libft_basic.c /////
void ft_putstr(char *str);
void ft_putnmb(int nmb);
int ft_atoi(char *str); // ascii to int
char *ft_itoa(int nmb); // int to ascii

///// libft_lists.c /////
t_stack  *ft_lstnew(int content);
void    ft_lstadd_front(t_stack **lst, t_stack *new_node);
void ft_lstadd_end(t_stack** lst, int valor);
void print_stack(t_stack *list);

#endif
