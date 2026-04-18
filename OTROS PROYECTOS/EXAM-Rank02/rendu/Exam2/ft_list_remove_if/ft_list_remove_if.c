//INiCIO: ~6:50
//FIN: 7:40
//INTENTOS: me_rindo

//#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    char            *data;
}                   t_list;

int cmp (void* a, void* b)
{
    //if(a == b)
      //  return 0;
    return 1;
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    printf("HOLA\n\n\n");
    t_list *temp = *begin_list;
    if(cmp (temp->data, data_ref))
        printf("BORRAR DATO: %s", temp->data);
}

t_list *newNodo(char* str)
{
    t_list *new_nodo=(t_list*)malloc(sizeof(t_list*));
    new_nodo->data = str;
    new_nodo->next=NULL;
    return(new_nodo);
}
t_list *add(t_list **lista, t_list *nodo)
{
    t_list *temp=*lista;
    if(temp->next != NULL)
        temp=temp->next;
    temp->next=nodo;
    return(temp);
}
void printList(t_list **lista)
{
    t_list *temp=*lista;
    while(temp->next !=NULL)
    {
        printf("[%s]", temp->data);
        temp=temp->next;
    }
}
int main()
{
    t_list *miLista=NULL;
    t_list *nodo = newNodo("hola");
    miLista = add(&miLista, nodo);
        nodo = newNodo("qe");
    miLista = add(&miLista, nodo);
        nodo = newNodo("tal");
    miLista = add(&miLista, nodo);

    printList(&miLista);


    return 0;
}
/*int main()
{
    t_list *miLista ;
    t_list *temp ;
    t_list *temp2 ;
    miLista->data = "hola";
    temp = miLista->next;
    temp->data = "que";
    temp2 = temp->next;
    temp2->data = "tal?";
    temp2->next = NULL;

    printf("[%s]", miLista->data);
    printf("\n\n\n");
    while(miLista->next !=NULL)
    {
        printf("[%s]", temp->data);
        miLista=miLista->next;
    }
    printf("fin\n\n\n");
    char b='b';
    ft_list_remove_if(&miLista, &b, cmp);

    return 0;
}*/