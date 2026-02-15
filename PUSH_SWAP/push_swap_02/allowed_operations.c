/*Los **movimientos permitidos** son los siguientes:

**SWAP (s)** : intercambia el primer numero de la pila con el segundo numero de la pila.

**PUSH (p)** : pasa el primer numero de la pila a a la primera posicion de la pila b.

**ROTATE (r)** : el primer numero de la pila pasa a ser el último.

**REVERSE (rr)** : el último numero de la pila pasa a ser el primero. 
*/

#include "allowed_operations.h"

/*SWAP*/

/*   /SWAP + FACIL/
void sa(t_stack **stack)
{
    t_stack *vagon1;
    t_stack *vagon2;

    // 1. Verificamos que haya al menos dos nodos para intercambiar
    if (!stack || !*stack || !(*stack)->next)
        return;

    // 2. Identificamos los dos primeros vagones
    vagon1 = *stack;
    vagon2 = vagon1->next;

    // 3. El vagon1 ahora debe engancharse a lo que venía después del vagon2 (el vagon3)
    vagon1->next = vagon2->next;

    // 4. El vagon2 ahora debe tener al vagon1 como su siguiente
    vagon2->next = vagon1;

    // 5. La cabeza de la pila (el control) ahora debe apuntar al vagon2
    *stack = vagon2;

        write(1, "sa\n", 3);
}*/

void sa(t_stack **stack)
{
    t_stack *temp;

    // Verificación mínima: ¿Hay al menos dos nodos?
    if (!stack || !*stack || !(*stack)->next)
        return;

    // 1. temp guarda el vagon2
    temp = (*stack)->next;

    // 2. El vagon1 apunta a donde apuntaba el vagon2 (el vagon3)
    (*stack)->next = temp->next;

    // 3. El vagon2 (temp) apunta ahora al vagon1 (*stack)
    temp->next = *stack;

    // 4. La cabeza de la pila ahora es el vagon2 (temp)
    *stack = temp;
    write(1, "sa\n", 3);
}

/*ROTATE*/
/*
void ra(t_stack **stack)
{
    t_stack *vagon1;
    t_stack *vagon2;
    t_stack *temp;

    // 1. Verificamos que haya al menos dos nodos para intercambiar
    if (!stack || !*stack || !(*stack)->next)
        return;

    // 2. Identificamos los dos primeros vagones
    vagon1 = *stack;
    vagon2 = vagon1->next;
    while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = vagon1;
    vagon1->next = NULL;
    *stack = vagon2;

    write(1, "ra\n", 3);
}
*/
void ra(t_stack **stack)
{
	t_stack	*vagon1;
	t_stack	*ultimo;

	// 1. Necesitamos al menos dos nodos para que el movimiento tenga sentido
	if (!stack || !*stack || !(*stack)->next)
		return;

	// 2. Guardamos el vagon1 y actualizamos la cabeza de la pila al vagon2
	vagon1 = *stack;
	*stack = (*stack)->next;

	// 3. El vagon1 ahora pasará a ser el último, así que su next debe ser NULL
	vagon1->next = NULL;

	// 4. Buscamos cuál es el vagon que está actualmente al final
	ultimo = *stack;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;

	// 5. Enganchamos el vagon1 al final de la fila
	ultimo->next = vagon1;
     write(1, "ra\n", 3);
}


void rra(t_stack **stack)
{
    t_stack *penultimo;
    t_stack *ultimo;

    // 1. Verificamos que haya al menos dos nodos
    if (!stack || !*stack || !(*stack)->next)
        return;

    penultimo = NULL;
    ultimo = *stack;

    // 2. Recorremos hasta que 'ultimo' llegue al final
    // 'penultimo' se quedará un paso atrás
    while (ultimo->next != NULL)
    {
        penultimo = ultimo;
        ultimo = ultimo->next;
    }

    // 3. El penúltimo ahora será el final, así que debe apuntar a NULL
    penultimo->next = NULL;

    // 4. El vagon que era el último ahora apunta al que era el primero
    ultimo->next = *stack;

    // 5. La cabeza de la pila ahora es el vagon que acabamos de traer del final
    *stack = ultimo;
         write(1, "rra\n", 3);
}
