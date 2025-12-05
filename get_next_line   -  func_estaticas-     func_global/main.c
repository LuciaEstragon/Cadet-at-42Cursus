/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:16:29 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/05 13:17:31 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *file_name;
	char dictionary[16500];

	file_name = "./numbers_CLAVE";
	if (handle_file_content(file_name, dictionary) == -1)
		write(2, "Dict Error\n", 12);
	else
		write(1, "fichero abierto\n", 17);
	write(1, "HOLA MUNDO\n", 17);
	find_numb(dictionary);
	printf("ADIOS");
	return (0);
}
