/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:35:26 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/27 09:15:57 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}


// Función que transforma el contenido (a mayúsculas)
void *convertir_mayusculas(void *content)
{
    char *str = (char *)content;
    char *copia = ft_strdup(str);
    char *temp = copia;
    
    if (!copia)
        return (NULL);
        
    while (*temp)
    {
        *temp = ft_toupper(*temp);
        temp++;
    }
    return (copia);
}

// Función que transforma (añade número)
void *numerar_elementos(void *content)
{
    static int contador = 1;
    char *str = (char *)content;
    char *nuevo;
    
    nuevo = malloc(ft_strlen(str) + 20);
    if (!nuevo)
        return (NULL);
        
    ft_sprintf(nuevo, "%d-%s", contador++, str);
    return (nuevo);
}

int main(void)
{
    t_list *lista_original = NULL;
    t_list *lista_transformada = NULL;
    t_list *nodo;
    
    // Crear lista original
    ft_lstadd_back(&lista_original, ft_lstnew(ft_strdup("hola")));
    ft_lstadd_back(&lista_original, ft_lstnew(ft_strdup("mundo")));
    ft_lstadd_back(&lista_original, ft_lstnew(ft_strdup("lista")));
    
    printf("Lista original:\n");
    for (nodo = lista_original; nodo; nodo = nodo->next)
        printf("- %s\n", (char *)nodo->content);
    
    // Crear nueva lista en mayúsculas
    lista_transformada = ft_lstmap(lista_original, convertir_mayusculas, free);
    
    printf("\nLista en mayúsculas:\n");
    for (nodo = lista_transformada; nodo; nodo = nodo->next)
        printf("- %s\n", (char *)nodo->content);
    
    // Probar con otra transformación
    t_list *lista_numerada = ft_lstmap(lista_original, numerar_elementos, free);
    
    printf("\nLista numerada:\n");
    for (nodo = lista_numerada; nodo; nodo = nodo->next)
        printf("- %s\n", (char *)nodo->content);
    
    // Liberar memoria
    ft_lstclear(&lista_original, free);
    ft_lstclear(&lista_transformada, free);
    ft_lstclear(&lista_numerada, free);
    
    return (0);
}
