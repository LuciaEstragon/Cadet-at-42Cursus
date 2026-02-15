#include "libft_redo.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>


// Crea un nuevo nudo a la lista
t_stack  *ft_lstnew(int content)
{
    t_stack  *new_node;

    new_node = (t_stack*)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = content;
    new_node->next = NULL;
    return (new_node);
}

// Añade el nodo al principio (Lógica de Pila / Stack)
void    ft_lstadd_front(t_stack **lst, t_stack *new_node)
{

    if (!lst || !new_node)
        return;
    new_node->next = *lst;
    *lst = new_node;
}

// Añadir nodo al final de la lista
void ft_lstadd_end(t_stack** lst, int valor) 
{
    t_stack* new_nodo = ft_lstnew(valor);
    if (*lst == NULL) {
        *lst = new_nodo;
    } else {
        t_stack* temp = *lst;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_nodo;
    }
}


// Imprime la pila recorriéndola
void print_stack(t_stack *list)
{
    while(list)
    {
        printf("[%d] -> ", list->value);
        //ft_putnmb(list->value); // Usamos printf para debug rápido
        list = list->next;
    }
    write(1, "\n", 1);
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

    imprime_stack(stack_a);

    // Aquí deberías añadir una función para liberar la memoria (free)
    return (0);
}*/