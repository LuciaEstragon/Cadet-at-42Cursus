#!/usr/bin/env python3
import random

# PASO 1 - crear una matriz llena de '·' con start y finish
width = 5
height = 5
start = (0,0)
finish = (4,4)
maze = [[None] * width for _ in range(height)]

for i in range(height):
    for j in range(width):
        if i == start[0] and j == start[1]:
            maze[i][j] = '@'
        elif i == finish[0] and j == finish[1]:
            maze[i][j] = '*'
        else:    
            maze[i][j] = '·'

for i in range(height):
    for j in range(width):
        print(maze[i][j], end="")
    print()

# PASO 2 - cojo mi casilla actual, consulto a mis vecinos, creo candidatos y crear mis muros
row = start[0]
col = start[1]
pos_actual = (row, col)
vecinos = [
    (row-1, col, 2, 0),  # norte: vecino sur (bit2) -> actual norte (bit0)
    (row, col+1, 3, 1),  # este: vecino oeste (bit3) -> actual este (bit1)
    (row+1, col, 0, 2),  # sur: vecino norte (bit0) -> actual sur (bit2)
    (row, col-1, 1, 3)   # oeste: vecino este (bit1) -> actual oeste (bit3)
]
print(pos_actual)
print(vecinos)
candidatos = ['X','X','X','X'] # mi casilla actual-N E S O, los bits del numero de muros de alrededor: binarioo 0,1,X

# NUEVA ESTRUCTURA: descompongo la tupla en variables con nombre vecino =coor_row,coord_col,bit_vecino, bit_actual)]
for (nr, nc, bit_vec, bit_act) in vecinos:
    # si el vecino tiene una direccion negativa o se pasa del max => esa pared es muro 
    if nr < 0 or nc < 0 or nr >= width or nc >= height: # uso nr y nc en lugar de vecino[0], vecino[1]
        candidatos[bit_act] = 1 # uso bit_act en lugar de vecino[3]
    # si el vecino ya ha sido visitado su bit tiene una info para mi
    valor_vecino_visitado = maze[nr][nc] # uso nr, nc
    if valor_vecino_visitado == '·': # NO HE PASADO POR AQUI
        continue
    num_vecino = int(valor_vecino_visitado, 16) # la letra de ese vecino, me la pasas a num int
    bit_val = (num_vecino >> bit_vec) & 1 # uso bit_vec en lugar de vecino[2]
    candidatos[bit_act] = bit_val # uso bit_act en lugar de vecino[3]

print(candidatos)

# NUEVA ESTRUCTURA para cumple() usando diccionario obligatorios como en la version generate anterior, que era mas limpio
obligatorios = {}
for (nr, nc, bit_vec, bit_act) in vecinos:
    # Verificar si el vecino está dentro de los límites
    if nr < 0 or nc < 0 or nr >= width or nc >= height:
        obligatorios[bit_act] = 1
    else:
        valor_vecino_visitado = maze[nr][nc]
        if valor_vecino_visitado != '·' and valor_vecino_visitado != '@' and valor_vecino_visitado != '*':
            num_vecino = int(valor_vecino_visitado, 16)
            bit_val = (num_vecino >> bit_vec) & 1
            obligatorios[bit_act] = bit_val

if not obligatorios:
    # Si no hay obligatorios, todos los números son válidos excepto el 15
    def cumple(num):
        return num != 15
else:
    def cumple(num):
        for pos, valor in obligatorios.items():
            if ((num >> pos) & 1) != valor:
                return False
        return True

hex_numeros = list(range(16))        # 0..15
hex_numeros_sin_F = [n for n in hex_numeros if n != 15]  # excluir F (15)
casillas_candidatas = [n for n in hex_numeros_sin_F if cumple(n)]
print(casillas_candidatas)

if casillas_candidatas:  # Verificar que no esté vacío
    nuevo_valor = random.choice(casillas_candidatas)
    print(nuevo_valor)
    # asigno el valor de ese muro a mi posicion actual
    maze[row][col] = format(nuevo_valor, 'X')
    print(maze[row][col])
else:
    print("No hay candidatos válidos")

# PASO 3 - moverme a nuevas posiciones
total_vifurcaciones = 0  # Inicializar contador

def puedo_moverme(nr, nc, bit_vec, bit_act):  # Cambio parámetros para usar nr, nc, bit_act
    # mi casilla actual tiene un 0 (pared abierta) por la direccion de mi vecino True, si tiene un 1(cerrado) False
    casilla_actual = maze[row][col] 
    num_actual = int(casilla_actual, 16)
    bit_val = (num_actual >> bit_act) & 1  # uso bit_act
    print(bit_val)
    if bit_val == 0: # abierto
        valor_vecino_visitado = maze[nr][nc]  # uso nr, nc
        if valor_vecino_visitado == "·":
            return True
        else:
            total_vifurcaciones += 1 # caminos que se encuentran +1
    return False # esta cerrado

arbol_pos_actuales = [()]
for (nr, nc, bit_vec, bit_act) in vecinos:  # Descompongo la tupla
    if puedo_moverme(nr, nc, bit_vec, bit_act) == True:
        casilla_siguientes_visitar = (nr, nc)
        arbol_pos_actuales.append(casilla_siguientes_visitar)
print(arbol_pos_actuales)

# repetir la movida
row = start[0]
col = start[1]
pos_actual = (row, col)
arbol_pos_actuales = [(pos_actual)]
for pos_actuales in arbol_pos_actuales:
    # de cada pos actual busca sus vecinos
    print(pos_actuales)