Cada ejercicio introduce una estructura de datos diferente:

Ex0: sys.argv (lista)   -> gestion de argumentos recibidos por consola

Ex1: listas y manejo de errores

Ex2: tuplas

Ex3: conjuntos (sets) y operaciones

Ex4: diccionarios

Ex5: generadores

Ex6: comprensiones




Ex0 : 
import sys

prueba
    Entra: ./ft_command_quest.py "hello world" 42
    Responde cuantos parametros de entrada hay

Ex1 :
import sys

prueba
    Entra: ./ft_score_analytics.py 1500 2300 1800 2100 1950
    Sale: un analisis de datos
          si metes algo raro, no importa no lo lee - con un try except, se queda con lo bueno, lo otro no -- METODOS DE LISTAS --
           append() - para añadir al final (tengo otros en indra)
           sum()
           len()
           max()
           min()

Ex2 : 
import math

prueba
    Programa pide las coord - estan tipadas, tiene un if para que entren 3 coord separadas por comas  (x, y, z) -- .split(',')  -- no pueden ser letras
    Calcula distancia

Ex3 :
import random
    creamos 4 jugadores (con un for)
    a esos jugadores le añadimos logros random: random.randint(3, 10) y random.sample(ALL_ACHIEVEMENTS, num)
    set.union() y set.intersection(*players)

a = {1, 2, 3, 5}
b = {3, 4, 5}
c = {5, 6}
resultado = a.union(*players)
print(resultado)  # {1, 2, 3, 4, 5, 6}
comunes = set.intersection(*players)
print(comunes)  # {5} Tiene que estar en todos

 zip vs enum
 
nombres = ["Ana", "Luis", "Eva"]
for i, nombre in enumerate(nombres, start=1):
    print(i, nombre)
# 1 Ana
# 2 Luis
# 3 Eva	

nombres = ["Ana", "Luis", "Eva"]
edades = [25, 30, 28]
for nombre, edad in zip(nombres, edades):
    print(nombre, edad)
# Ana 25
# Luis 30
# Eva 28


Ex 4:
prueb
    Entra:  ft_inventory_system.py sword:1 potion:5 shield:2 armor:3 helmet:1 sword:2 hello key:value
    



SE PUEDE HACER MAS EXTRUCURADO ?¿?


Ex5:

utilizar generadores: yield -- lo normal seria haber creado una  lista y enviar la lista en un return
                            -- el yield va enviando a la lista, pero no es un return, porque no se sale del bucle

def generar_pares(n)
    for i in range(n)
        if i%2 == 0
            yield i
    
def generar_pares(n)
    lista_pares = []
    for i in range(n)
        if i%2 == 0
            lista_pares.append(i)
        return lista_pares

pares = generar_pares(20) # esto es una lista
for num in pares:
    print(num)




def main() -> None:
    original_names = ["aRagorn", "Legolas", "GIMLI", "Frodo", "sam", "GANDALF"]
    print("Original names:", original_names)

    # All uppercase
    names_upper = [name.upper() for name in original_names]
    print("All uppercase:", names_upper)

    # Only those already uppercase in original
    already_upper = [name for name in original_names if name.isupper()]
    print("Already uppercase (original):", already_upper)

    # Dictionary name -> random score
    scores = {name.upper(): random.randint(50, 200) for name in original_names}
    print("\nScores dictionary:", scores)

    avg_score = sum(scores.values()) / len(scores)
    print(f"Average score: {avg_score:.2f}")

    # High performers
    high_performers = {
        name: score for name, score in scores.items() if score > avg_score
    }
    print("High performers (above average):", high_performers)

