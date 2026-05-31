# ejercicio Py3
'''
# Ambos hacen exactamente lo mismo
comunes = set(lista_A).intersection(set(lista_B))
comunes = set(lista_A) & set(lista_B)
# Ambos juntan todo sin repetir
todos = set(lista_A).union(set(lista_B))
todos = set(lista_A) | set(lista_B)

NOTA!!!
sin esta estructura -> "sorted(list(set(" el seed no hace ni puto caso
'''

import sys
import random

from config_params import ConfigParams

# TOP_LEFT_CORNER = ["9", "B", "D"] # comunes_top-left = set(UPPER_WALL).intersection(set(LEFT_WALL))
# TOP_RIGHT_CORNER = ["3", "7", "B"]
# BOTTOM_LEFT_CORNER = ["C", "D", "E"]
# BOTTOM_RIGHT_CORNER = ["6", "7", "E"]
UPPER_WALL = ["1", "3", "5", "7", "9", "B", "D"]
LOWER_WALL = ["4", "5", "6", "7", "C", "D", "E"]
LEFT_WALL = ["8", "9", "A", "B", "C", "D", "E"]
RIGHT_WALL = ["2", "3", "6", "7", "A", "B", "E"]
NUM_42 = "F"

class Maze (ConfigParams):
    def get_input_file(self):
        try:
            f_out = open(self.out_file, 'w')
            write_lines = [''.join(row) + '\n' for row in self.generate_maze]
            f_out.writelines(write_lines) # este metodo solo escribe lineas completas, no matrizes.
            f_out.close()
        except PermissionError as e:
            print("[STDERR] Error opening file "
                  f"'{new_filename}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)

    def generate(self):
        if self.seed is not None: # si existe semilla, todos los metodos que utilices con random se quedan con un algoritmo fijo. Asi que son reproducibles.
            random.seed(self.seed)

        print("genero un laberinto")
        row_max = self.height
        col_max = self.width
        maze = [[] for _ in range(row_max)] # self.generate_maze
        middle = (int(col_max/2), int(row_max/2))

        for row in range(row_max):
            for col in range(col_max):
                if row == 0 or col == 0 or row == row_max-1 or col == col_max-1: # muro exterior
                    choice = ""
                    if row == 0: # arriba
                        if col == 0: # arriba_izq
                            choice = random.choice(sorted(list(set(UPPER_WALL) & set(LEFT_WALL)))) # estructura para el seed "sorted(list(set("
                        elif col == col_max-1: # arriba_der
                            choice = random.choice(sorted(list(set(UPPER_WALL).intersection(set(RIGHT_WALL)))))
                        else:
                            choice = random.choice(UPPER_WALL)
                    elif col == 0: # izquierda
                        if row == row_max-1: # abajo_izq
                            choice = random.choice(sorted(list(set(LOWER_WALL).intersection(set(LEFT_WALL)))))
                        else:
                            choice = random.choice(LEFT_WALL)
                    elif col == col_max-1: # derecha
                        if row == row_max-1: # abajo_der
                            choice = random.choice(sorted(list(set(LOWER_WALL).intersection(set(RIGHT_WALL)))))
                        else: 
                            choice = random.choice(RIGHT_WALL)
                    elif row == row_max-1: # abajo
                            choice = random.choice(LOWER_WALL)
                    
                    maze[row].append(choice)
            
                elif row == (self.start[1]) and col == (self.start[0]):
                    maze[row].append("@") # print("@")
                elif row == (self.finish[1]) and col == (self.finish[0]):
                    maze[row].append("X") # print("X")
                elif any([ # -- coordenadas del 42 -- # falta un if el tamaño_lab (w,h) > (7,9)
                    # ---4---  
                    row == (middle[1]-2) and col == (middle[0]-3),
                    row == (middle[1]-1) and col == (middle[0]-3),
                    row == (middle[1]-0) and col == (middle[0]-3),            
                    row == (middle[1]-0) and col == (middle[0]-2),
                    row == (middle[1]-0) and col == (middle[0]-1),
                    row == (middle[1]+1) and col == (middle[0]-1),
                    row == (middle[1]+2) and col == (middle[0]-1),
                    # ---2---  
                    row == (middle[1]-2) and col == (middle[0]+1),
                    row == (middle[1]-2) and col == (middle[0]+2),
                    row == (middle[1]-2) and col == (middle[0]+3),
                    row == (middle[1]-1) and col == (middle[0]+3),
                    row == (middle[1]-0) and col == (middle[0]+3),
                    row == (middle[1]-0) and col == (middle[0]+2),
                    row == (middle[1]-0) and col == (middle[0]+1),
                    row == (middle[1]+1) and col == (middle[0]+1),
                    row == (middle[1]+2) and col == (middle[0]+1),
                    row == (middle[1]+2) and col == (middle[0]+2),
                    row == (middle[1]+2) and col == (middle[0]+3)               
                ]):
                    maze[row].append("F") # print("#")
                else:
                    maze[row].append("·") # print("·")

        self.generate_maze = maze

        for row, row_max in enumerate(self.generate_maze):
            for tline in self.generate_maze[row]:
                print(tline, end='')
            print()
