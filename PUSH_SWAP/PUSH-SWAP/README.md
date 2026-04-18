*Este proyecto ha sido creado como parte del currículo de 42 por lestrada.*

# 📦 PUSH_SWAP

## 🌟 Descripcion

Este proyecto consiste en ordenar números de una pila, con el menor numero de movimientos posibles.

Para este ejercicio contamos con dos **pilas**: a y b. Estas pilas son *listas* de numeros. Entran una cantidad X de numeros random desordenados en la pila a, y mediante unos *movimientos permitidos* tenemos que lograr colocar los numeros en la pila a, en orden ascendente:

----------------------------------------------------------------------------------------------------------
```bash
Init a and b:  --> Exec comands --> End a and b
2                                   1
8                                   2
3                                   3
6                                   5
5                                   6
1                                   8
_ _                                 _ _
a b                                 a b
----
```

Los **movimientos permitidos** son los siguientes:

**SWAP (s)** : intercambia el primer numero de la pila con el segundo numero de la pila.

**PUSH (p)** : pasa el primer numero de la pila a a la primera posicion de la pila b.

**ROTATE (r)** : el primer numero de la pila pasa a ser el último.

**REVERSE (rr)** : el último numero de la pila pasa a ser el primero. 

Nota: como tenemos dos pilas, estos comandos son dobles, depende de a que pila se apliquen. Asi tendremos 8 comandos permitidos: **sa** - **sb**, **pa** - **pb**, **ra** - **rb** y **rra** - **rrb**. Comandos extra **rr** - **rrr**.

El objetivo de este proyecto es aprender a trabajar con pilas y con ordenacion de listas. Está planteado como un ejercicio de lógica, que nos permite diseñar un algoritmo que establezca el menor numero de cambios posibles.

## 💢 Instrucciones de uso

Este ejercicio trae consigo un programa para probar y contabilizar los movimientos del push_swap. Funciona asi:

```bash
# 1. Error handling
./push_swap 1 a          # → "Error"
./push_swap 1 2 1        # → "Error"
./push_swap              # → (nada)
./push_swap 1 2 3 4      # → (nada)
./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

# 2. Corrección
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG   # → "OK"
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG   # → "OK"

# 3. Conteo de instrucciones
>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
>ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
1234
>ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
1520
```

**shuf:** Es el comando de "shuffle" (barajar).
**-i 1-5000:** Le dice que elija números en el rango del 1 al 5000 (puedes poner el rango que quieras, mientras sea mayor que 500).
**-n 500:** Le indica que solo queremos 500 números. Al usar shuf, nunca se repiten, lo cual es vital para que tu push_swap no de "Error".
**| tr '\n' ' ':** Los números que genera shuf salen uno por línea (vertical). Este comando cambia los saltos de línea por espacios, para que queden todos en una sola fila horizontal.


## 🔧 Utilidades: Mi algoritmo

He utilizado el algoritmo K-Sort, porque de los que he mirado era el que más entendia y el que más facil de implementar me parecía.

Mi algoritmo lo que va a hacer es llevar al STACK-B los valores que le parezcan bajitos a poderlos ordenar mejor. 
Podria decir que en una lista con numeros desordenados de 0 a 9, los numeros menores a 5 (el punto de pivote) son bajos, y dificiles de poderse quedar ordenados de forma directa en mi stack-A. Por eso los muevo a B, y reparto el problema. Con listas pequeñas esto funciona. En nuestro ejemplo, te quedan:
stack_A: [0-4] en el stack_B:[5-9].
Listas menores de 5 numeros son mas faciles de ordenar, dentro de su propia pila. Pilas de 3 numeros se ordenan de forma inmediata.

Para listas grandes, de muchos numeros desordenados, coger el numero medio como numero de pivote no resuelve el problema.
Loque hace el K-Sort es que coge un pivote dinámico y se mueve dentro de un rango o ventana.

1. El concepto de la "Ventana" (K)
En lugar de mandar a la Stack B solo los números menores a un punto fijo, el K-Sort define una "franja" de números que pueden pasar.
Imagina que tienes 500 números (del 0 al 499). Creamos un pivote que va a ser: big_pivot = √N*√2 = 31.
Recorro la lista. Los menores a 31 pasa a la lista B, pues son numeros demasiado pequeños para ahora. Los mayores se quedan, ra.
La ventana: tengo dos pivotes, el pivote small_pivot va a decidir si el numero que entra es grande respecto a los numeros que quedan en la cola.
Asi, los numeros que entran en el stack_b se van ordenando, de forma que los numeros muy pequeños se colocn en l pila b abjo, y los medianos en la pila b arriba.


2. ¿Cómo se mueve el "Pivote"? (El bucle)
El código recorre la Stack A desde el número 0 hasta el 499. En cada paso:
Mira el número que está arriba en la Stack A.
Si el número es menor o igual al índice actual (i): Significa que es un número "pequeño" que ya debería haber pasado. Lo manda a la Stack B y hace un rb (lo pone al fondo de B).
Si el número está dentro de la ventana (i a i + k): Significa que es un número que toca pasar ahora. Lo manda a la Stack B (se queda arriba).
Si el número es mayor a i + k: Es demasiado grande para ahora. Hace un ra (lo manda al fondo de la Stack A) para volver a verlo más tarde.

Cada vez que un numero pasa a la lista b, el samll_pivote avanza uno, y el big_pivote se recalcula.
Asi pues, voy moviendo el pivote hacia arriba. 


3. El resultado: Forma de "K" o Reloj de Arena
Al terminar este proceso, la Stack B no está ordenada, pero está "pre-ordenada" por trozos:
Los números más grandes están en los extremos (arriba y abajo).
Los números más pequeños del rango están en el medio.
Visto en un visualizador, parece una K o un reloj de arena.

4. ¿Por qué es eficiente?
La magia del K-Sort es que ahorra muchos movimientos de rotación. Al permitir que pase cualquier número dentro de un rango (en lugar de buscar uno solo), el programa no pierde tiempo girando la pila A buscando un número específico.

5. La recuperación (De B a A)
Una vez que todo está en B con esa forma de "K", el código busca el número más grande de B, lo sube a la superficie y lo pasa a A. Como los números ya están "más o menos" cerca de su posición final, el coste es bajísimo.


## 📝 INTERESANTE: NOTA - PUNTOS DE MEJORA:

Para poder ver los Algoritmos de ordenacion de forma visual tenemos varias paginas:
Visualgo: **https://visualgo.net/en**
Push-swap Visualizer de saadloukili: **https://saadloukili.github.io/Push-Swap-Visualizer/index.html**

Mencion al GitHub de Luna, que me inspiro y me ayudo  hacer el k-short.
**https://github.com/luna7111/push_swap/tree/main**

Mi push_swap es bastante ineficiente con cadenas casi-casi ordenadas. 
Con listas pequeñas o pocos numeros a ordenar tampoco es muy eficiente.
```bash
./push_swap 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 20 18 0
./push_swap 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 0 1 2
```

Otro punto de mejora seria optimizar los metodos para el pintado del oplist, y al ser una lista normal, los metodos sobran, ya que se deberían reutilizar los definidos dentro de la libft.


## 🚀 Recursos: Organizacion del programa

Es importante la estructura de los ficheros.

```bash
libft
├── Makefile
├── libft.a
├── libft.h
└── [todos-los-archivos-libft-en-sbucarpetas]

Makefile
push_swap
README.md

src
├── check_error
│   └── check_error.c
├── movements
│   ├── allowed_operations.c
│   ├── push.c
│   ├── reverse_rotate.c
│   ├── rotate.c
│   └── swap.c
├── push_swap.c
├── push_swap.h
├── sorting_algorithms
│   ├── ksort.c
│   ├── small_sort.c
│   └── sort.c
├── util_oplist
│   ├── operation_oplist.c
│   └── print.c
└── util_stack
    ├── indexize.c
    └── operation_stack.c
```

He decidido meter la libft completa, integrando todos los proyectos que hemos ido haciendo hasta ahora.
Lo decidí asi para poder usar mis propias funciones sin que la estructura de ficheros me quedara demasiado larga y fea.
De la libft utilizo: ft_printf, ft_split, ft_math, ft_atoi, ft_free_strarray, ft_isalpha y muchas de las funciones de las listas.

Para la estructura de los STACKS:
```c
typedef struct s_stack
{
	int				value;  // valor numero = contenido de la lista
	int				id;     // posicion que ocupa en la lista
	struct s_stack	*next;  // apunta al nodo siguiente
}	t_stack;
```

Lo que hace mi push_swap.c es:

1. Recojo los numeros que me pases por terminal. Me da igual como los introduzcas, los pareseo, los evaluo, y compruebo 3 errores (si son nummeros, si no se repiten, si no estan ordenados). Creo el stack_a (operation_stack.c) o, si falla algo, limpio el stack_a y termina el programa.
2. Con indexice.c voy a rellenar el campo stack->id, rellenandolo con la posicion que ocuparia en la lista si estuviera ordenado.
3. Por otro lado, voy a crear los movimientos permitidos (allowed_operations.c), que va a ser la forma de actuar e intercambiar numeros entre listas. 
4. Una vez que la lista esta definida y las operaciones creadas, voy a empezar la ordenacion, con mis algoritmos(sorting_algorithms). Lo que voy a hacer es un k-sort. Cuando se decida que se va a hacer con el numero, pasa por las funviones movements.c, que van a dejar una "huella" de trazado en la lista oplist. Esta lista de trazado es la que pide el ejercicio del push_swap.
5. Cuando llegue a pasar todos los numeros del stack_a menos 3 a stack_b, ordena estos úlimos números y vuelve a pasar todo ordenado definitivamente de stack_b a stack_a.
6. Por últmo solo dibujo el trazado de oplist. Para pintar oplist tengo varias funciones debido a un arreglo.

## ✍️ Author 💭 

All projects on this GitHub repository are written by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). April 2026.

_Todos los proyectos de este repositorio GitHub han sido escritos por **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). Abril 2026._
