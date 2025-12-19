/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:16:29 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/16 11:19:39 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*file_name;
	int		file_ref;
	char	*mi_texto;
	//char mi_texto[BUFFER_SIZE];
	int	index = 0;

	//write(1, "HOLA MUNDO\n", 12);
	mi_texto = "fin";
	//printf("hola Mundo \n\n");
	file_name = "./text1.txt";
	file_ref = open(file_name, O_RDONLY);
	if (file_ref == -1)
		return (-1);
	while(index != 5)
	{
		mi_texto = get_next_line(file_ref);
		//printf("FILE LINE: %d TEXT: %s", index, mi_texto);
		index++;
		mi_texto = NULL;
	}
	printf("\n \n \n");
	printf("FILE - Hay %d lineas, y el texto es este: \n%s\n", index, mi_texto);
	return (0);
}
