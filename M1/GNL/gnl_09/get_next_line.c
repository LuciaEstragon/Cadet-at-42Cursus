/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/01/17 19:38:27 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	  cojo desde la direccion de save(ind_maximo_linea) y la vuelvo 
	  a guardar en save.
	  Ejemplo: hola que tal?\n yo bien graci-
	  line= hola que tal?
	  save= yo bien graci-
		* si no hubiera encontrado el salto de linea = strlen(linea)==
		strlen(save) => no copiar nada en save ya es todo

*/

char	*get_next_line(int file)
{
	char		*line;
	static char	*save;

	if (file < 0 || BUFFER_SIZE <= 0)
		return (0);
	printf("HOLITA \n \n \n");
	save = NULL;
	save = read_file(file, save);
	line = make_line(&save);
	return (line);
}

//mientras no encuentres un salto de linea, sigue leyendo el fichero.
char	*read_file(int file, char *save)
{
	ssize_t bytesLeidos;
	char *buffer_leido;
	char *new_str;

	bytesLeidos = 0;
	//new_str = NULL;
	buffer_leido = NULL;
	if(save)
		new_str=save;
	printf("save 1 = %s/n /n", save);
	printf("strchr = %s", ft_strchr(new_str, '\n'));
			printf("HOLA \n \n");
	buffer_leido = malloc(BUFFER_SIZE + 1);
		if (!buffer_leido) return NULL;
	while  (!ft_strchr(new_str, '\n') && bytesLeidos >= 0)
	{
		printf("HOLA \n \n");
		bytesLeidos = read(file, buffer_leido, BUFFER_SIZE);
		buffer_leido[bytesLeidos] = '\0'; //importante!

		printf("buffer_leido = %s", buffer_leido);
		printf("\n \n");

		new_str = ft_strjoin(new_str, buffer_leido);
		//new_str = new_str + buffer_leido;
		printf("new_str = %s", new_str);
		printf("\n \n");

		free(buffer_leido);		
	}
	save = new_str;
	printf("save 2 = %s", save);

		printf("HOLA \n \n");
	//free(new_str);
	return (save);
}


//cuando crea una linea devuelve la linea y cirra la funcion. Se tiene que guardar el valos nuevo de save.  
//¡CUIDADO! si el buffer de save se tiene que limpiar entero antes de llenarse de nuevo; si no save podria contener basura acumulada de una lectura anterior mas larga
// save = 12345/n789. save = 78945 (en este ejemplo save guardo basura anterior)
char	*make_line(char **save)
{
	char *line;

	line = ft_strchr(*save, '\n');
	printf("line = %s", line);
	//printf("save = %s", save);
	return (line);
}

