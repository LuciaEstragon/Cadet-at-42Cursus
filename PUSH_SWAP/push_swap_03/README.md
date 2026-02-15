*Este proyecto ha sido creado como parte del currículo de 42 por lestrada.*

# 📦 PUSH_SWAP

## 🌟 Descripcion

Este proyecto consiste en ordenar números de una pila, con el menor numero de movimientos posibles.

Para este ejercicio contamos con dos **pilas**: a y b. Estas pilas son *listas* de numeros. Entran una cantidad X de numeros random desordenados en la pila a, y mediante unos *movimientos permitidos* tenemos que lograr colocar los numeros en la pila a, en orden ascendente:

----------------------------------------------------------------------------------------------------------
Init a and b:  --> Exec comands --> End a and b
2                                   1
1                                   2
3                                   3
6                                   5
5                                   6
8                                   8
_ _                                 _ _
a b                                 a b
----

Los **movimientos permitidos** son los siguientes:

**SWAP (s)** : intercambia el primer numero de la pila con el segundo numero de la pila.

**PUSH (p)** : pasa el primer numero de la pila a a la primera posicion de la pila b.

**ROTATE (r)** : el primer numero de la pila pasa a ser el último.

**REVERSE (rr)** : el último numero de la pila pasa a ser el primero. 

Nota: como tenemos dos pilas, estos comandos son dobles, depende de a que pila se apliquen. Asi tendremos 8 comandos permitidos: **sa** - **sb**, **pa** - **pb**, **ra** - **rb** y **rra** - **rrb**.

El objetivo de este proyecto es aprender a trabajar con pilas y con ordenacion de listas. Está planteado como un ejercicio de lógica, que nos permite diseñar un algoritmo que establezca el menor numero de cambios posibles.

## 💢 Instrucciones

Para poder probar el PUSH_SWAP introduce los archivos *get_next_line.h*, *get_next_line.c* y *get_next_line_utils.c* en tu carpeta de proyecto.
No te olvides de crear un archivo "file" con el contenido del que deseas leer las lineas.

### ⬇️ Instalacion

Este ejercicio trae consigo un programa para probar y contabilizar los movimientos del push_swap. Funciona asi:

### 🔧 Utilidades

Forma de probar el push_swap 
>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK


Push_swap Because Swap_push doesn’t feel as natural
>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
>./push_swap 0 one 2 3
Error

## 🚀 Recursos

La complejidad del push_swap recae -...

NOTA: este BUFFER_SIZE lo puedes modificar a la hora de compilar, escribiendo:
```bash
./*EXEC_NAME* BUFFER_SIZE=*NEW_SIZE*
```


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


Hay que tener cuiddo en l forma e la que se alloca memoria, para evitar posibles errores de leaks.


## ✍️ Author 💭 

All projects on this GitHub repository are written by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026.

_Todos los proyectos de este repositorio GitHub han sido escritos por **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026._