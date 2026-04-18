#include <string.h>
#include <stdio.h>

// Ejemplo: Comparar cadenas de texto
int cmp(void *a, void *b)
{
    return (strcmp((char *)a, (char *)b));
}

#include <stdlib.h>
#include "ft_list.h" // Asegúrate de definir t_list aquí

/*
 * Estructura estándar (t_list.h)
 * typedef struct s_list
 * {
 *     struct s_list *next;
 *     void          *data;
 * } t_list;
 */

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list *current;
    t_list *temp;

    // Si la lista está vacía, no hay nada que eliminar
    if (begin_list == NULL || *begin_list == NULL)
        return;

    current = *begin_list;

    // Comparamos los datos con la referencia
    if (cmp(current->data, data_ref) == 0)
    {
        // Si coinciden, movemos la cabeza de la lista al siguiente nodo
        *begin_list = current->next;
        free(current);
        // Llamada recursiva para seguir comprobando el nuevo "primero"
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        // Si no coinciden, avanzamos al siguiente nodo recursivamente
        ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
    }
}



//INIT 9:55
//FIN 10:59
//TRY FAIL
/*
#include <stdlib.h>
#include "ft_list.h" // Asegúrate de tener la estructura t_list definida

int cmp(void *a, void *b)
{
    // Convertimos los punteros void* a punteros int* para poder leer el valor.
    // Luego desreferenciamos para obtener el valor real.
    int *data_a;
    int *data_b;

    data_a = (int *)a;
    data_b = (int *)b;

    if (*data_a == *data_b)
        return (0); // Son iguales, se elimina
    else
        return (1); // Son diferentes
}


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
        if (begin_list == NULL || *begin_list == NULL)
                return;

        t_list *cur = *begin_list;

        if (cmp(cur->data, data_ref) == 0)
        {
                *begin_list = cur->next;
                free(cur);
                ft_list_remove_if(begin_list, data_ref, cmp);
        }
        else
                ft_list_remove_if(&cur->next, data_ref, cmp);
}
/*

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_list.h"

char *copy(char *s1, char*s2)
{
    int i=0;
    while(s2[i] != '0')
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
    return s1;
}
int	ft_list_size(t_list *begin_list)
{
    int len=1;
    while(begin_list->next != NULL)
    {
        begin_list=begin_list->next;
        len++;
    }
    return len;
}

t_list *new(void *data)
{
    t_list *nodo;
    nodo = (t_list *)malloc(sizeof(t_list *));
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}
void *add(t_list **lista, void *data)
{
    t_list *temp = *lista;
    t_list *nodo = new(data);
    if(*lista==NULL)
        *lista=nodo;
    else
    {
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=nodo;
    }

}
void imprime(t_list **lista)
{
    t_list *temp=*lista;
    while(temp)//(temp->next != NULL)
    {
        printf("[%s]", (char*)temp->data);
        temp=temp->next;
    }
}

int cmp(void *data_ref, void* temp_data)
{
    char *dat = (char*)data_ref;
    char *tem_d = (char*)temp_data;
    int i=0;
    while(tem_d[i])
    {
        if(dat[i] == tem_d[i])
            i++;
        else 
            return 0; //no coincide
    }
    return 1; //coincide
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
        if (begin_list == NULL || *begin_list == NULL)
                return;

        t_list *cur = *begin_list;

        if (cmp(cur->data, data_ref) == 0)
        {
                *begin_list = cur->next;
                free(cur);
                ft_list_remove_if(begin_list, data_ref, cmp);
        }
        else
                ft_list_remove_if(&cur->next, data_ref, cmp);
}
/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp=*begin_list;
    t_list *siguiente= temp->next;
    while(temp)//(temp->next != NULL)
    {
        if(cmp(data_ref, begin_list->data))
        {
            printf("[%s]", (char*)temp->data);
            begin_list = begin_list->next;
        }
        if(cmp(data_ref, siguiente->data))
        {
            printf("[%s]", (char*)temp->data);
            temp->next = siguiente->next;
        }
        temp=temp->next;
        siguiente= temp->next;
    }
}
*/

/*
int main()
{
    t_list *miLista = NULL;
    add(&miLista, "hola");
    add(&miLista, "qe");
    add(&miLista, "tal");
    add(&miLista, "qetal");
    add(&miLista, "qe");

    printf("%d", ft_list_size(miLista));

    imprime(&miLista);
    printf("\n");

    ft_list_remove_if(&miLista, "qe", cmp);
    return 0;
}*/