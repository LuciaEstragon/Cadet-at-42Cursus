/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:26:15 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/27 12:56:23 by lestrada         ###   ########.fr       */
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
	static char	*save = NULL;

	if (file < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(file, save);
	if (!save)
		return (NULL);
	if (!*save)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = make_line(&save);
	return (line);
}

static char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new;

	if (!save || !tmp)
		return (NULL);
	new = ft_strjoin(save, tmp);
	free(save);
	return (new);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*read_file(int file, char *save)
{
	char	*str;
	int		size_str;

	if (!save)
		save = (char *)ft_calloc(sizeof(char), 1);
	str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str || !save)
		return (free(str), free(save), NULL);
	while (!ft_strchr(save, '\n'))
	{
		size_str = read(file, str, BUFFER_SIZE);
		if (size_str < 0)
			return (free(str), free(save), NULL);
		else if (size_str == 0)
			break ;
		str[size_str] = '\0';
		save = ft_free_strjoin(save, str);
		if (!save)
			return (free(str), NULL);
	}
	free(str);
	return (save);
}

char	*make_line(char **save)
{
	char	*line;
	char	*save_aux;
	char	*temp;
	int		len;

	if (!*save || (*save)[0] == '\0')
		return (NULL);
	save_aux = ft_strchr(*save, '\n');
	if (save_aux == NULL)
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (line);
	}
	len = save_aux - *save + 1;
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *save, len + 1);
	temp = ft_strdup(save_aux + 1);
	free(*save);
	*save = temp;
	return (line);
}
