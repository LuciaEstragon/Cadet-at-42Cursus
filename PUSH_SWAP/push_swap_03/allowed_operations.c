/*Los **movimientos permitidos** son los siguientes:

**SWAP (s)** : intercambia el primer numero de la pila con el segundo numero de la pila.

**PUSH (p)** : pasa el primer numero de la pila a a la primera posicion de la pila b.

**ROTATE (r)** : el primer numero de la pila pasa a ser el último.

**REVERSE (rr)** : el último numero de la pila pasa a ser el primero. 
*/

#include "allowed_operations.h"

/*SWAP*/
void swap(t_stack **stack)
{
    t_stack *nodo1;
    t_stack *nodo2;

    if (!stack || !*stack || !(*stack)->next)
        return;
    nodo1 = *stack;
    nodo2 = nodo1->next;
    nodo1->next = nodo2->next;
    nodo2->next = nodo1;
    *stack = nodo2;
    write(1, "swap\n", 5);
}
/*ROTATE*/
void rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *nodo1;
    t_stack *nodo2;

    if (!stack || !*stack || !(*stack)->next)
        return;
    nodo1 = *stack;
    nodo2 = nodo1->next;
    *stack =  nodo2;
    nodo1->next = NULL;
    last = *stack;
	while (last->next != NULL)
		last = last->next;
    last->next = nodo1;

    write(1, "rotate\n", 7);
}
/*REVERSE*/
void reverse(t_stack **stack)
{
	t_stack	*nodo1;
    t_stack	*pre_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	nodo1 = *stack;
    last = *stack;
	while (last->next != NULL)
    {
        pre_last = last;
        last = last->next;
    }
    pre_last->next = NULL;
    last->next = nodo1;
    *stack = last;
    write(1, "reverse\n", 8);
}
/*PUSH*/
void push(t_stack **orig, t_stack **dest)
{
    t_stack *orig_nodo1;
    t_stack *dest_nodo1;
    t_stack *orig_nodo2;
    t_stack *dest_nodo2;

    if (!orig || !*orig || !(*orig)->next)
        return;
    orig_nodo1 = *orig;
    dest_nodo1 = *dest;
    orig_nodo2 = orig_nodo1->next;
    *orig = orig_nodo2;
    orig_nodo1->next = dest_nodo1;
    *dest = orig_nodo1;
    write(1, "push\n", 5);
}


/*
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    t_stack *stack_a = NULL; // ¡Importante inicializar a NULL!
    t_stack *stack_b = NULL; // ¡Importante inicializar a NULL!
    int i = 1;

    while (argv[i])
    {
        // Convertimos el argumento a entero (
        int num = ft_atoi(argv[i]); 
        
        // Creamos el nodo y lo añadimos a la pila
        //t_stack *nuevo = ft_lstnew(num);
        ft_lstadd_end(&stack_a, num);
        
        i++;
    }

    // print_stack(stack_a);
    // swap(&stack_a);
    // write(1, "                                     \n", 1);
    // print_stack(stack_a);
    // rotate(&stack_a);
    // write(1, "                                     \n", 1);
    // print_stack(stack_a);
    // reverse(&stack_a);
    // write(1, "                                     \n", 1);
    // print_stack(stack_a);

    print_stack(stack_b);
    print_stack(stack_a);
    push(&stack_a, &stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    // Aquí deberías añadir una función para liberar la memoria (free)
    return (0);
}

*/