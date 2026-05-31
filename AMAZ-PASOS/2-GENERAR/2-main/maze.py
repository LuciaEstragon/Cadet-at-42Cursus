# ejercicio Py2 -ex02, ex03 y ex04

import sys

from config_params import ConfigParams

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
                    maze[row].append("#") # print("#")
                elif row == (self.start[1]) and col == (self.start[0]):
                    maze[row].append("@") # print("@")
                elif row == (self.finish[1]) and col == (self.finish[0]):
                    maze[row].append("X") # print("X")
                elif row == (middle[1]) and col == (middle[0]):
                    maze[row].append("C") # CENTRO DEL MAZE
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
                    maze[row].append("#") # print("#")
                else:
                    maze[row].append("·") # print("·")

        self.generate_maze = maze

        for row, row_max in enumerate(self.generate_maze):
            for tline in self.generate_maze[row]:
                print(tline, end='')
            print()
