# GET_NEXT_LINE
*Este proyecto ha sido creado como parte del currículo de 42 por lestrada.*

## 🌟 Descripcion

El objetivo de este proyecto es programar una funcion que devuelva una linea (terminada en \n) leida de un file descriptor.
Este programa permitira leer lineas de informacion de un fichero hasta encontrar un salto de carro "\n". Tambien permite leer parrafos enteros de uno en uno. 

## ⬇️ Instrucciones

Para poder utilizar el GNL introduce los archivos *get_next_line.h*, *get_next_line.c* y *get_next_line_utils.c* en tu carpeta de proyecto.
No te olvides de crear un archivo "file" con el contenido del que deseas leer las lineas

```c
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd = open("file", O_RDONLY);
	while (1)
	{
		char *str = get_next_line(fd); //prueba fd=0
		if (str == NULL)
			break ;
		printf("LINEA: %s\n", str);
		free (str);
	}
	close (fd);
	return (0);
}
//Return: 
> Escribe todas las lineas de tu archivo "file" comenzando por LINEA: 
```

Recuerda que el file_descriptor 0, es decir *fd = 0*, es el propio terminal, por lo que si pedimos al *main* anterior leer desde el fd=0, estaria esperando una entrada de nuestra pantalla, y cuando des al *\n* te escribe la linea por pantalla. Felicidades! Habrias recreado el funcionamiento de laa funcion *scanf();*.

### Utilidades

Create un "file" un poco mas complejo, donde el contenido de cada linea del fichero tinga un informacion relevante, organizada en un formato. 1= a (\n)  2= b (\n) ...
Puedes crearte un main mas complejo, que lea en un bucle while linea por linea, almacenando en una variable la informacion relevnte extraida de la linea.

## 🚀 Recursos

La complejidad del gnl recae en que la funcion *read()* con la siguente estructura: ssize_t read(int fd, void *buf, size_t count); solo admite lecturas de un espacio de BUFFER_SIZE determinado. 
NOTA: este BUFFER_SIZE lo puedes modificar a la hora de compilar, escribiendo:
```bash
./*EXEC_NAME* BUFFER_SIZE=*NEW_SIZE*
```


Si corremos este main, donde utilizamos a pelo la funcion read(), veremos diferencias notables de funcionamiento de un gnl vs read:
```c
# include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("file", O_RDONLY);
	while (1)
	{
		char str[5];
		int byte = read(fd,str,5);
		if (byte<=0)
			break ;
		printf("LINEA: %s\n", str);
	}
	close (fd);
	return (0);
}
```


Por lo tanto, para ficheros donde sus lineas son de tamaños desiguales, no podemos leer hasta el final de una linea usando el mismo tamaño de BUFFER_SIZE.
Lo que vamos a crear es la funcion *GNL-get_next_line* para crear una estructura _char *line_ despues de que tras la lectura del fichero encuentre un *\n*.
NOTA: Este _separador_ podria ser otro tipo de char, por ejemplo, que te devuelva hasta el primer *'.'*. (*#define END_LINE '\n'*)


Este programa es interesante por lo que implica tener **variables estaticas**. Este tipo de variable conservan su contenido, y no mueren cuando se cierre la llave de la llamada a la funcion a la que pertenecen. No son variables globales, aunque ambas persisten toda la vida del programa, no tienen la misma visibilidad: la variable global es visible para todo el programa, y la variable static solo en la funcion en la que es llamada. 
 En mi programa mi variable estatica es la siguiente, definida dentro de la funcion char *get_next_line(int file);
```c
 static char	*save = NULL;
```
 
En mi  programa tambien tengo una **macro** o **directiva de  preprocesamiento**:
```c
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
```
Las macros no tienen tipo de dato, a diferencia de una variable normal. Cuando escribes #define PI 3.14, el compilador no sabe que es un número flotante. Simplemente, antes de compilar, el preprocesador busca la palabra PI en todo tu código y la reemplaza textualmente por 3.14.
Por eso, las macros (#define) no ocupan espacio en memoria, y no tienen dirección de memoria. Al ser un "buscar y reemplazar" de texto, el valor se inserta directamente en el código donde se usa (como un literal o "hardcoded"). Los **#define** son utiles para guardar magic_numbers: numeros que metes a capon pero que tienen un sentido en el progrma, como un offset, una calibracion...

El **ifndef** permite definirla desde el compilador, escribiendo: -D BUFFER_SIZE=*NEW_SIZE*, a la hora de compilar.

En este proyecto ha sido crucial entender bien cuando debes liberar la memoria de cada _string_ usado. 
!! IMPORTANTE : al ser una variable static siempre existe, asi que aunque la liberes, el puntero que apunta al espacio que ocupa esa variable save siempre existe y apunta a algo, aunque cierres la funcion. Por esta razon, se debe inicializar a NULL despues de liberarla.
```c
if (!*save)
{
	free(save);
	save = NULL;  //importante!
	return (NULL);
}
```

 

### Funcionamiento

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


Hay que tener cuidado en la forma e la que se alloca memoria, para evitar posibles errores de leaks.


## ✍️ Author 💭

All projects on this GitHub repository are written by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). Febrero 2026.

_Todos los proyectos de este repositorio GitHub han sido escritos por **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). February 2026._
