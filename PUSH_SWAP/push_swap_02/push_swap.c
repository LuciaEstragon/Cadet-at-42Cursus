#include "allowed_operations.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    t_stack *stack_a = NULL; // ¡Importante inicializar a NULL!
    int i = 1;

    while (argv[i])
    {
        // Convertimos el argumento a entero (puedes usar tu ft_atoi)
        int num = ft_atoi(argv[i]); 
        
        // Creamos el nodo y lo añadimos a la pila
        //t_stack *nuevo = ft_lstnew(num);
        ft_lstadd_end(&stack_a, num);
        
        i++;
    }

    print_stack(stack_a);
    //sa(&stack_a);
    //write(1, "\n", 1);
    //print_stack(stack_a);
    //ra(&stack_a);
    //write(1, "\n", 1);
    //print_stack(stack_a);
    rra(&stack_a);
    write(1, "\n", 1);
    print_stack(stack_a);

    // Aquí deberías añadir una función para liberar la memoria (free)
    return (0);
}


int main0(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    t_stack *stack_a = NULL; // ¡Importante inicializar a NULL!
    int i = 1;

    while (argv[i])
    {
        // Convertimos el argumento a entero (puedes usar tu ft_atoi)
        int num = ft_atoi(argv[i]); 
        
        // Creamos el nodo y lo añadimos a la pila
        //t_stack *nuevo = ft_lstnew(num);
        ft_lstadd_end(&stack_a, num);
        
        i++;
    }

    print_stack(stack_a);

    // Aquí deberías añadir una función para liberar la memoria (free)
    return (0);
}