#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;


/*
typedef struct      s_list
{
    int             content;  // valor numero = contenido de la lista
    struct s_list   *next;  // apunta al nodo siguiente
} t_list;

lista   *[1er_nodo (=estructura)]   -- apunta al 1 nodo  -> dentro de ese nodo al ser una estructura necesito un puntero
nodo    *[ estructura(valo+*next)]  -- apunta a una estructura
    -> una lista un conjunto de nodos, pero dentro los nodos apuntan a cosas

        NODO t_list* [valor + next]
        LISTA t_list* [ [nodo] [nodo] [nodo] [nodo] ... ]

main {
  t_list *mi_lista;  // la lista apunta donde esta el primer nodo
  t_list *nodo;      // el nodo apunta donde esta el valor
  nodo = crear_nodo(valor);
  add_list(&mi_lista, valor);
}
void add_list(t_list **la_lista, t_list *nuevo_nodo)
t_list *crear_nodo(int valor)
*/

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para añadir al final de la lista
void añadirNodo(Nodo** cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    printf("Lista actual: ");
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("[%d] -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Liberar memoria para evitar fugas (buena práctica)
void liberarLista(Nodo* cabeza) {
    Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

//Recorro la lista e imprimo el 4 valor
void imprimir_position_N(Nodo* cabeza, int pos) {
    printf("Lista actual: ");
    Nodo* temp = cabeza;
    int ind_pos = 0;
    while (pos!=ind_pos) {
        temp = temp->siguiente;
        ind_pos++;
    }
    printf("position %d = [%d] ", pos, temp->dato);
}

void añadirNodo_position_N(Nodo** cabeza, int valor, int pos) {
    Nodo* nuevo = crearNodo(valor);
    
    // CASO 1: Insertar en la posición 0 (nueva cabeza)
    if (pos == 0) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        return;
    }

    Nodo* anterior = *cabeza;
    int i = 0;

    // Recorremos hasta encontrar el nodo justo ANTES de la posición deseada
    // También verificamos que no nos salgamos del límite de la lista
    while (anterior != NULL && i < pos - 1) {
        anterior = anterior->siguiente;
        i++;
    }

    // Si anterior es NULL, la posición estaba fuera de rango
    if (anterior == NULL) {
        printf("Error: La posición %d está fuera de rango.\n", pos);
        free(nuevo); // Importante liberar si no se usa
        return;
    }

    // CASO 2: Insertar en medio o al final
    // "Cosemos" el nuevo nodo:
    nuevo->siguiente = anterior->siguiente;
    anterior->siguiente = nuevo;
}

// Función de comparación: devuelve 1 si 'a' es mayor que 'b'
int cmp(int a, int b) {
    return (a > b);
}

Nodo *ordenarLista2(Nodo *lst, int (*cmp)(int, int)) {
    if (lst == NULL) return NULL;

    int tmp_dato;
    int hubo_intercambio = 1;
    Nodo *actual;
    Nodo *cabeza_original = lst; // Guardamos el inicio para el return

    // Usamos un bucle tipo "bubble sort"
    while (hubo_intercambio) {
        hubo_intercambio = 0;
        actual = cabeza_original;

        while (actual != NULL && actual->siguiente != NULL) {
            // Si el actual es mayor que el siguiente (según tu función cmp)
            if (cmp(actual->dato, actual->siguiente->dato)) {
                // Intercambiamos solo los datos (más simple que mover nodos)
                tmp_dato = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = tmp_dato;
                
                hubo_intercambio = 1; // Marcamos que hubo un cambio
            }
            actual = actual->siguiente;
        }
    }
    return cabeza_original;
}


// --- Funciones auxiliares para el Main ---
/*
t_list	*new_node(int data) {
	t_list *node = malloc(sizeof(t_list));
	if (!node) return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *lst) {
	while (lst) {
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}*/

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    Nodo* miLista = NULL;

    // Recorremos los argumentos desde el índice 1
    // argv[0] es el nombre del programa
    for (int i = 1; i < argc; i++) {
        int valor = atoi(argv[i]); // Convertimos string a entero
        añadirNodo(&miLista, valor);
    }

    imprimirLista(miLista);
    imprimir_position_N(miLista, 3);
    printf("\n");
    añadirNodo_position_N(&miLista, 42, 3);
    imprimirLista(miLista);
    printf("\n");
    miLista = ordenarLista2(miLista, cmp);
    imprimirLista(miLista);
    printf("\n");
    liberarLista(miLista);

    return 0;
}