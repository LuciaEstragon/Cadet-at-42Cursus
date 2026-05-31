#!/usr/bin/env python3
import random

# PASO 1 - crear una matriz llena de '·' con start y finish
# PASO 2 - escoger casilla para mi ubicacion actual
# PASO 3 - moverme a nuevas posiciones

# PASO 1
# leo de config
# parseo

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

# PASO 2 - cojo mi casilla actual, consulo a mis vecinos, creo candidatos y crear mis muros
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
# si el vecino tiene una direccion negativa => esa pared es muro
for vecino in vecinos:
    if vecino[0] < 0 or vecino[1] < 0: # en la posicion (0,1) de mi vecino estan la coordenadas de su casilla
        candidatos[vecino[3]] = 1 # en la posicion 3 esta el bit que me afecta a mi, en la posicion 4 esta su bit
            # RECORDAR: ameising -> 0 S E N (3=O, 2=S, 1=E, 0=N)- abierto 0, cerrado 1
print(candidatos)

# si el vecino ya ha sido visitado su bit tiene una info para mi
for vecino in vecinos:
    if vecino[0] < 0 or vecino[1] < 0: # en la posicion (0,1) de mi vecino estan la coordenadas de su casilla
        continue
    valor_vecino_visitado = maze[vecino[0]][vecino[1]]
    if valor_vecino_visitado == '·': # NO HE PASADO POR AQUI
        continue
    num_vecino = int(valor_vecino_visitado, 16) # la letra de ese vecino, me la pasas a num int
    bit_val = (num_vecino >> vecino[2]) & 1 # extraigo el bit de la posicion 3, que es la que tiene valor para mi
    candidatos[vecino[3]] = bit_val
            # RECORDAR: ameising -> 0 S E N (3=O, 2=S, 1=E, 0=N)- abierto 0, cerrado 1
print(candidatos)

# todos los numeros que en binario cumplan mi candidato
def cumple(num):
    count = 0
    for pos, valor in enumerate(candidatos):
        print(f"pos{pos}, valor{valor}")
        if(valor!=0 or valor!=1):
            count+=1
        if valor==0:
            valor=1
        elif valor==1:
            valor=0
        if ((num >> pos) & 1) == valor:
            count+=1
    if count == 4:
        return True
    return False

hex_numeros = list(range(16))        # 0..15
hex_numeros_sin_F = [n for n in hex_numeros if n != 15]  # excluir F (15)
casillas_candidatas = [n for n in hex_numeros_sin_F if cumple(n)]
print(casillas_candidatas)
nuevo_valor = random.choice(casillas_candidatas)
print(nuevo_valor)

# asigno el valor de ese muro a mi posicion actual
maze[row][col] = format(nuevo_valor, 'X')
print(maze[row][col])

# PASO 3 - moverme a nuevas posiciones
def puedo_moverme(vecino):
    # mi casilla actual tiene un 0 (pared abierta) por la direccion de mi vecino True, si tiene un 1(cerrado) False
    # si el valor de mi vecino es != de '·' es que esta ocupado => respodo False, pero contabilizo +1 en caminos vifurcados que son el mismo
    # RECORDAR: ameising -> 0 S E N (3=O, 2=S, 1=E, 0=N)- abierto 0, cerrado 1
    casilla_actual = maze[row][col] 
    num_actual = int(casilla_actual, 16) # la letra de mi casilla, me la pasas a num int
    bit_val = (num_actual >> vecino[3]) & 1 #index==0=NORTE,  #index==1=ESTE ....
    print(bit_val)
    if bit_val == 0: # abierto
        valor_vecino_visitado = maze[vecino[0]][vecino[1]]
        if valor_vecino_visitado == "·":
            return True
        else:
            total_vifurcaciones += 1 # caminos que se encuentras +1
    return False # esta cerrado

arbol_pos_actuales = [()]
for vecino in vecinos:
    if puedo_moverme(vecino) == True:
        casilla_siguientes_visitar = (vecino[0], vecino[1])
        arbol_pos_actuales.append(casilla_siguientes_visitar)
print(arbol_pos_actuales)


################################################
# repetir la movida
row = start[0]
col = start[1]
pos_actual = (row, col)
arbol_pos_actuales =[(pos_actual)]
for pos_actuales in arbol_pos_actuales:
    # de cada pos actual busca sus vecinos
    # de hay escoges una casilla actual que cumpla los requisitos de sus vecinos
    # escoges posiciones nuevas en las que te vas a mover
    print(pos_actuales)
