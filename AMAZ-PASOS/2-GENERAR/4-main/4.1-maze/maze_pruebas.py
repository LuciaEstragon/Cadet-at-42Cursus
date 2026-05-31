import sys
import random

from config_params import ConfigParams

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
       
        self.generate_maze = maze
        self._print_maze(maze)
        row_max = self.height
        row_max = self.width
        maze = [[] for _ in range(row_max)] # self.generate_maze
        middle = (int(col_max/2), int(row_max/2))
        '''
        rows, cols = self.height, self.width
        maze = [['' for _ in range(cols)] for _ in range(rows)]     
        self.generate_walls(maze, rows, cols)
        self.generate_42(maze, (cols//2, rows//2))
        '''
        self.generate_walls(maze, row_max, col_max)
        self.generate_42(maze, middle)
        # una funcion para el resto que me queda
        # self.generate_rest(maze, row_max, col_max, middle)

        # Luego start y finish (sobrescriben)
        maze[self.start[1]][self.start[0]] = '@'
        maze[self.finish[1]][self.finish[0]] = 'X'
        
        self.generate_maze = maze
        self._print_maze(maze)


    def generate_walls(self, maze, rows, cols):
        # Llena toda la matriz con muros exteriores y pasillos interiores provisionales
        for row in range(rows):
            for col in range(cols):
                if self._is_exterior_wall(row, col, rows, cols):
                    maze[row][col] = self._get_wall_char(row, col, rows, cols)

    def generate_42(self, maze, middle):
        # Sobrescribe solo las posiciones de la figura 42 con 'F'
        for (row, col) in self.is_42(middle):
            if 0 <= row < len(maze) and 0 <= col < len(maze[0]):
                maze[row][col] = 'F'


    # -- Funciones auxiliares (dentro de la clase Maze) --

    def _is_exterior_wall(self, row, col, rows, cols):
        return row == 0 or col == 0 or row == rows-1 or col == cols-1

    def _get_wall_char(self, row, col, rows, cols):
        # Definir constantes como UPPER_WALL, LOWER_WALL, LEFT_WALL, RIGHT_WALL
        if row == 0:  # arriba
            if col == 0:
                return random.choice(sorted(set(UPPER_WALL) & set(LEFT_WALL)))
            elif col == cols-1:
                return random.choice(sorted(set(UPPER_WALL) & set(RIGHT_WALL)))
            else:
                return random.choice(UPPER_WALL)
        elif col == 0:  # izquierda
            if row == rows-1:
                return random.choice(sorted(set(LOWER_WALL) & set(LEFT_WALL)))
            else:
                return random.choice(LEFT_WALL)
        elif col == cols-1:  # derecha
            if row == rows-1:
                return random.choice(sorted(set(LOWER_WALL) & set(RIGHT_WALL)))
            else:
                return random.choice(RIGHT_WALL)
        elif row == rows-1:  # abajo
            return random.choice(LOWER_WALL)


    def _is_42(self, middle):
        if any([ # -- coordenadas del 42 -- # falta un if el tamaño_lab (w,h) > (7,9)
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
            return True
        '''
        # Coordenadas relativas al centro (middle[1]=fila_centro, middle[0]=col_centro)
        mc, mr = middle  # (col_centro, fila_centro)
        puntos_42 = [
            (mr-2, mc-3), (mr-1, mc-3), (mr, mc-3),
            (mr, mc-2), (mr, mc-1),
            (mr+1, mc-1), (mr+2, mc-1),
            (mr-2, mc+1), (mr-2, mc+2), (mr-2, mc+3),
            (mr-1, mc+3), (mr, mc+3),
            (mr, mc+2), (mr, mc+1),
            (mr+1, mc+1), (mr+2, mc+1),
            (mr+2, mc+2), (mr+2, mc+3)
        ]
        return (row, col) in puntos_42
        '''

    def _print_maze(self, maze):
        for row, row_max in enumerate(self.generate_maze):
            for tline in self.generate_maze[row]:
                print(tline, end='')
            print()
        '''
        for row in maze:
            print(''.join(row))
        '''