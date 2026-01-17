# GNL -> get_next_line() function 

**#include "get_next_line.h"**
**char *get_next_line(int fd);**

## 🌟 Description

El GNL se trata de una funcion capaz de leer hasta el salto de linea. Esto te permite leer lineas de informcion completas o parrafos completos.

La dificultad del proyecto reside en que el formato para leer de un 'file descriptor' fd, con la funcion read(); tenemos que determinar un tamaño de buffer de lectura.

```c
char buffer[1024];
int fd = open("archivo.txt", O_RDONLY);
// Lee hasta 1024 bytes
ssize_t bytesLeidos = read(fd, buffer, sizeof(buffer));
fd.close();
```

## ⬇️ Instructions - How to use that

Para utilizar el get_next_line en tu proyecto, create un main similar a este. Tiene que incluir en la cabecera nuestra libreria 'get_next_line.h'

```c
#include "get_next_line.h"

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
```

 El programa se compilará de la siguiente forma:
```bash
$ cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <files>.c
```
donde BUFFER_SIZE es el tamaño de longitud del buffer de lectura para la funcion read()

## 🚀 Resource - Explicacion sobre las funciones a utilizar




## ✍️ Author 💭

**ft_printf()** is written and maintained by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026.