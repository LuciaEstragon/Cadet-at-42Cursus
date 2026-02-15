#include "allowed_operations.h"

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
        // Convertimos el argumento a entero
        int num = ft_atoi(argv[i]); 
        
        // Creamos el nodo y lo añadimos a la pila
        //t_stack *nuevo = ft_lstnew(num);
        ft_lstadd_end(&stack_a, num);
        
        i++;
    }

    // ALGORITMO //

    // Aquí deberías añadir una función para liberar la memoria (free)
    return (0);
}
