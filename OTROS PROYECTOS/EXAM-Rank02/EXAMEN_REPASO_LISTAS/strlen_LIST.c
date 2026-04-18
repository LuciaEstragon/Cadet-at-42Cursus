//strlen version lista  // como avanzar en una lista
int list_len(t_list *lista) 
{
    int len = 0;
    while (lista->next)
    {
        lista = lista->next;
        len++;
    }
    return (len);
}
