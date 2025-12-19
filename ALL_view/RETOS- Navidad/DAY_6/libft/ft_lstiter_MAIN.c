/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:35:26 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/27 09:16:24 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

#include "libft.h"
#include <stdio.h>

// Función que modifica el contenido (añade prefijo)
void añadir_prefijo(void *content)
{
    char *str = (char *)content;
    char *nuevo = malloc(ft_strlen(str) + 10);
    if (!nuevo)
        return;
    ft_strlcpy(nuevo, "Prefijo-", 9);
    ft_strlcat(nuevo, str, ft_strlen(str) + 10);
    free(content);
    *(char **)content = nuevo;
}

// Función que solo imprime el contenido
void imprimir_contenido(void *content)
{
    printf("Contenido: %s\n", (char *)content);
}

int main(void)
{
    t_list *lista = NULL;
    t_list *nodo1;
    t_list *nodo2;
    t_list *nodo3;
    
    // Crear lista: "uno" -> "dos" -> "tres" -> NULL
    nodo1 = ft_lstnew(ft_strdup("uno"));
    nodo2 = ft_lstnew(ft_strdup("dos"));  
    nodo3 = ft_lstnew(ft_strdup("tres"));
    
    ft_lstadd_back(&lista, nodo1);
    ft_lstadd_back(&lista, nodo2);
    ft_lstadd_back(&lista, nodo3);
    
    printf("Lista original:\n");
    ft_lstiter(lista, imprimir_contenido);
    
    printf("\nAplicando prefijo:\n");
    ft_lstiter(lista, añadir_prefijo);
    ft_lstiter(lista, imprimir_contenido);
    
    // Liberar memoria
    ft_lstclear(&lista, free);
    return (0);
}
