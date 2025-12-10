/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/12/10 18:51:46 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"


/*
GET_NEXT_LINE
1) leo un determinado numero de caracteres del fichero (BUFFER_SIZE)
	read_line(file, save);
	1- leo de fichero BUFFER_SIZE caracteres
	2- lo almaceno en str.
	3- lo sumo a save (si save no tenia nada es de tamaño 1)

2) crear una linea
	make_line(save);
	1- veo el contenido de todo lo que he guardado hasta que encuentro /n
	  si lo encuentro: hasta aqui es mi nueva linea, lo demas lo guardo
	  si no lo encuentro: se me va a devolver save entero
	2- todo lo que no este guardado en line va a ser para guardar
	  cojo desde la direccion de save(ind_maximo_linea) y la vuelvo a guardar en save.
	  Ejemplo: hola que tal?\n yo bien graci- 
	  line= hola que tal?
	  save= yo bien graci-
		* si no hubiera encontrado el salto de linea = strlen(linea)==strlen(save)  => no copiar nada en save ya es todo


*/
 
char	*get_next_line(int file)
{
	char		*line;
	static char	*save;

	//if (file == -1)
	//	return (-1);
	save = read_file(file, save);
	line = make_line(save);
	return (line);
}

char *read_file(int file, char *save)
{
	char	*str;
	int		size_str;

	if (!save)
		save = (char *)ft_calloc(sizeof(char), 1);
	str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	size_str = read(file, str, BUFFER_SIZE);
	if (size_str < 0)
		return (NULL);
	save = ft_strjoin(save, str);
	return (save);
}

char	*make_line(char *save)
{
	char	*line;

	//line = (char *)ft_calloc(1, 1);
	line = ft_strchr(save, '\n');
	save = ft_substr(save, (int)ft_strlen(line), (int)ft_strlen(save));
	return (line);
}
