/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/12/21 18:36:21 by lestrada         ###   ########.fr       */
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

char *get_next_line(int file)
{
	char *line;
	static char *save;

	// if (file == -1)
	//	return (-1);
	save = read_file(file, save);
	line = make_line(&save);
	return (line);
}

char *read_file(int file, char *save)
{
	char *str;
	char *new_content = NULL;
	int size_str;
	static int flag_last_round;

	if (!save)
		save = (char *)ft_calloc(sizeof(char), 1);
	if (!flag_last_round)
		flag_last_round = 0;
	str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	new_content = ft_strchr(save, '\n');
	while (new_content == NULL)
	{
		size_str = read(file, str, BUFFER_SIZE);
		if (size_str <= 0)
		{
			free(str);
			return(make_last_line(save,flag_last_round));
		}
		str[size_str] = '\0'; // super necesario, para limpiar el final del buffer cuando haga el join
		new_content = ft_strchr(str, '\n');
		save = ft_strjoin(save, str);
	}
	free(str);
	return (save);
}

char *make_line(char **save)
{
	char *line;
	char *save_aux = NULL;

	line = (char *)ft_calloc(1, 1);
	save_aux = ft_strchr(*save, '\n');
	if (save_aux == NULL)
		return (0); //?¿ hay que quitarlo ?¿
	line = ft_substr(*save, 0, (int)ft_strlen(*save) - (int)ft_strlen(save_aux) + 1);
	*save = ft_substr(save_aux, 1, (int)ft_strlen(save_aux));
	return (line);
}

char *make_last_line(char *save, int flag_last_round)
{
	flag_last_round++;
	if (save != (void *)0 && flag_last_round == 1)
	{
		save = ft_strjoin(save, "\n");
		flag_last_round++;
		return (save);
	}
	// save = NULL;
	free(save);
	return (save);
}
