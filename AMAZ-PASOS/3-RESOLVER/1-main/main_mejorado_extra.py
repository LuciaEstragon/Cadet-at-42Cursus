#!/usr/bin/env python3
import random
from collections import deque

# ---------- PARÁMETROS ----------
width = 5
height = 5
start = (0, 0)
finish = (4, 4)

# ---------- INICIALIZAR LABERINTO ----------
maze = [[None] * width for _ in range(height)]
for i in range(height):
    for j in range(width):
        if (i, j) == start:
            maze[i][j] = '@'
        elif (i, j) == finish:
            maze[i][j] = '*'
        else:
            maze[i][j] = '·'

# ---------- FUNCIONES AUXILIARES ----------
def obtener_vecinos(row, col):
    """Devuelve lista de tuplas (nr, nc, bit_vecino, bit_actual) para cada dirección"""
    return [
        (row-1, col, 2, 0),   # norte
        (row, col+1, 3, 1),   # este
        (row+1, col, 0, 2),   # sur
        (row, col-1, 1, 3)    # oeste
    ]

def calcular_obligatorios(row, col):
    """Construye diccionario {bit_actual: valor_requerido} según vecinos ya visitados"""
    obligatorios = {}
    for (nr, nc, bit_vec, bit_act) in obtener_vecinos(row, col):
        # Vecino fuera del mapa -> pared cerrada (1)
        if nr < 0 or nc < 0 or nr >= height or nc >= width:
            obligatorios[bit_act] = 1
        else:
            contenido = maze[nr][nc]
            # Solo nos interesan vecinos que ya tengan un número asignado (hex)
            if contenido not in ('·', '@', '*'):
                num_vecino = int(contenido, 16)
                bit_val = (num_vecino >> bit_vec) & 1
                obligatorios[bit_act] = bit_val
    return obligatorios

def cumple(num, obligatorios):
    """Verifica si num cumple todas las restricciones del diccionario"""
    for pos, valor in obligatorios.items():
        if ((num >> pos) & 1) != valor:
            return False
    return True

def elegir_numero(row, col):
    """Elige un número aleatorio (0..14) que cumpla las restricciones de los vecinos"""
    obligatorios = calcular_obligatorios(row, col)
    candidatos = [n for n in range(16) if n != 15 and cumple(n, obligatorios)]
    if not candidatos:
        # Si no hay candidatos (caso raro), devolvemos 0 (todas las paredes abiertas)
        return 0
    return random.choice(candidatos)

def posibles_movimientos(row, col):
    """Devuelve lista de vecinos a los que podemos movernos según el número de la celda actual"""
    movimientos = []
    numero_actual = int(maze[row][col], 16)  # asumimos que la celda ya tiene número
    for (nr, nc, bit_vec, bit_act) in obtener_vecinos(row, col):
        # Verificar si el bit correspondiente está abierto (0)
        if ((numero_actual >> bit_act) & 1) == 0:
            # Asegurarse que el vecino está dentro del mapa y no es '*' (meta)
            if 0 <= nr < height and 0 <= nc < width and maze[nr][nc] == '·':
                movimientos.append((nr, nc))
    return movimientos

# ---------- BUCLE PRINCIPAL: RECORRIDO BFS ----------
# Usamos una cola con las posiciones pendientes de procesar
cola = deque()
cola.append(start)

# Marcamos el inicio como procesado (aunque aún no tiene número, lo trataremos aparte)
# Pero la celda start ya tiene '@', no se le asignará número hasta el final (opcional).
# En tu algoritmo original, la celda start recibía un número después de analizar vecinos.
# Para mantener coherencia, vamos a tratar todas las celdas '·' y la start la saltamos.

# Sin embargo, la celda start debe ser la primera en recibir un número.
# Vamos a procesar la start manualmente antes del bucle.

# Procesar la celda de inicio
row, col = start
vecinos_inicio = obtener_vecinos(row, col)
# Calcular obligatorios para start
obligatorios_start = calcular_obligatorios(row, col)
# Elegir número
num_start = elegir_numero(row, col)
maze[row][col] = format(num_start, 'X')  # asignamos número hexadecimal
print(f"Casilla inicio ({row},{col}) = {maze[row][col]}")

# Añadir a la cola los vecinos a los que podemos movernos desde start
for (nr, nc, _, _) in obtener_vecinos(row, col):
    if ((num_start >> vecinos_inicio[0][3]) & 1) == 0:  # comprobar bit norte? Mejor usar posibles_movimientos
        pass
# Usamos la función auxiliar:
for mov in posibles_movimientos(row, col):
    if mov not in cola:
        cola.append(mov)

# Ahora bucle principal: mientras haya celdas pendientes
while cola:
    row, col = cola.popleft()
    # Si ya no es '·' (podría haber sido asignada por otro camino) la saltamos
    if maze[row][col] != '·':
        continue
    
    # 1. Calcular número para esta celda según sus vecinos
    num_celda = elegir_numero(row, col)
    maze[row][col] = format(num_celda, 'X')
    print(f"Casilla ({row},{col}) = {maze[row][col]}")
    
    # 2. Determinar hacia qué vecinos podemos movernos (bits abiertos)
    for nr, nc in posibles_movimientos(row, col):
        if (nr, nc) == finish:
            # Llegamos a la meta, pero no la procesamos como '·', solo registramos
            print(f"¡Se puede llegar a la meta desde ({row},{col})!")
            continue
        if maze[nr][nc] == '·' and (nr, nc) not in cola:
            cola.append((nr, nc))

# ---------- MOSTRAR RESULTADO FINAL ----------
print("\nLABERINTO GENERADO:")
for i in range(height):
    for j in range(width):
        print(maze[i][j], end=" ")
    print()