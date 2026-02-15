//Todo lo que necesito para crear la pila a
//#include "libft_stack.h"
typedef struct      s_list
{
    struct s_list   *next;  // nodo de union, es una pila
    int             *valor; //valor del numero // void *data;
    int             id;     //posicion que ocupa
}                   stack;

/*stack new_node(char *data)
{
    stack* list;
    list = (char*)malloc(sizeof(stack));
    list->value = ft_atoi(data);
    list->next = NULL;
    retun(list);
}*/

// crea un nodo nuevo, si la lista no esta empezada la crea
stack  *ft_lstnew(void *content)
{
        stack  *new_node;

        new_node = malloc(sizeof(stack));
        if (!new_node)
                return (NULL);
        new_node->value = content;
        new_node->next = NULL;
        return (new_node);
}

// añade nodos nuevos a la lista
void    ft_lstadd_front(stack **lst, stack *data_new)
{
        if (!data_new)
                return ;
        if(!lst)
            lst = ft_lstnew(data_new);
        new->next = *lst;
        *lst = data_new;
}
/*
stack **add_node(stack **list, stack *data)
{
    if(!list)
    {
        list = ft_lstnew(data);
        return (*list);
    }

    //avanzo la lista hasta el final
    while(list)
        list = lest->next;
    // añado
    data->next = *list;
    *list  = data;  
    
    return(*list);
}*/
stack *create_stack(char *arg)
{
    stack *list;
    int i=0;
    while(arg[i])
    {
        ft_lstadd_front(list,arg[i]);
        i++;
    }
    return(list);
}
void imprime_stack(stack *list)
{
    while(list)
    {
        //char* str = ft_itoa(list->valor);
        //ft_putstr(str);
        int a=list->valor;
        ft_putnmb(a);
        list = list->next;
    }
}

// --PROBAR TODAS LAS FUNCIONES DE util_stack -> necesito libft_basic.h--
int main(int argc, char** argv)
{
    if(argc<2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i=1;
    stack *stack_a;
    stack *stack_b;
    while(argv[i])
    {
        stack_a = create_stack(argv[i]);
        i++;
    }
    imprime_stack(stack_a);

    return(0);
}
