/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:16:29 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/17 14:14:05 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* MAIN ANTIGUO */
/*
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
*/

int main(int argc, char *argv[]) {
    int fd;
    char *linea; // Variable para almacenar la línea leída

    // 1. Verificar si se proporcionó un archivo como argumento
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nombre_del_archivo>\n", argv[0]);
        return (1); // Salir con error si no hay argumento
    }

    // 2. Abrir el archivo en modo lectura (O_RDONLY)
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo"); // Muestra el error del sistema
        return (1);
    }

    printf("--- Iniciando lectura de %s ---\n", argv[1]);

    // 3. Bucle principal para leer línea por línea
    // GNL devuelve NULL cuando ha terminado de leer el archivo (EOF)
    while ((linea = get_next_line(fd)) != NULL) {
        printf(">> %s", linea); // Imprime la línea leída (ya incluye el '\n' si lo tiene)
        free(linea); // ¡Importante! Libera la memoria asignada por GNL
        linea = NULL; // Buena práctica: poner a NULL después de free
    }

    printf("\n--- Fin de la lectura ---\n");

    // 4. Cerrar el descriptor de archivo
    close(fd);

    return (0); // Salir con éxito
}
