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
	int file_ref;
	//char dictionary[16500];

	file_name = "./numbers_CLAVE";
	file_ref = open(file_name, O_RDONLY);
	if (file_ref == -1)
		return (-1);
	get_next_line(file_ref);
	write(1, "HOLA MUNDO\n", 12);
	//find_numb(dictionary);
	//printf("ADIOS");
	return (0);
}
