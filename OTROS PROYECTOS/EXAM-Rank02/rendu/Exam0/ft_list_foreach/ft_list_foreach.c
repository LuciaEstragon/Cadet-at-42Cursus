//lo he memorizado - finish 14:10 - 14:16
//hacer un main con pruebas14:51

#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *list_ptr = begin_list;

    while(list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr=list_ptr->next;
    }
}

t_list *new(void *dato)
{
    t_list *nodo = (t_list *)malloc(sizeof(t_list));
    if(!nodo) return(NULL);
    nodo->data = dato;
    nodo->next = NULL; 
    return (nodo);
}
void puts(void *s)
{
    char *str =(char*)s;
    int i=0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
void add(t_list **lista, t_list *nodo)
{
    t_list *temp = *lista;
    if(*lista == NULL) *lista=nodo;
    else
    {
        while(temp->next != NULL)
            temp= temp->next;
        temp->next = nodo;
    }
}

void    print(t_list *begin_list)
{
    t_list *list_ptr = begin_list;

    while(list_ptr)
    {
        puts(list_ptr->data);
        list_ptr=list_ptr->next;
    }
}
int main(int argc, char** argv)
{
    if(argc<2)
        return 0;
    int i=1;
    t_list *miLista = NULL;
    t_list *newNodo;
    while(argv[i])
    {
        newNodo = new(argv[i]);
        //print(miLista);
        add(&miLista, newNodo);
        //print(miLista);
        //puts(argv[i]);
        i++;
    }
    ft_list_foreach(miLista, puts);
    return (0);
}