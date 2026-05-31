import sys
import random
from config_params import ConfigParams
from display import display

UPPER_WALL = ["1", "3", "5", "7", "9", "B", "D"]
LOWER_WALL = ["4", "5", "6", "7", "C", "D", "E"]
LEFT_WALL = ["8", "9", "A", "B", "C", "D", "E"]
RIGHT_WALL = ["2", "3", "6", "7", "A", "B", "E"]
NUM_42 = "F"

class Maze(ConfigParams):
    def get_input_file(self):
        try:
            with open(self.out_file, 'w') as f_out:
                write_lines = [''.join(row) + '\n' for row in self.generate_maze]
                f_out.writelines(write_lines)
        except PermissionError as e:
            print(f"[STDERR] Error opening file '{self.out_file}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)

    def generate_walls(self, maze, rows, cols):
        for row in range(rows):
            for col in range(cols):
                if self._is_exterior_wall(row, col, rows, cols):
                    maze[row][col] = self._get_wall_neighbor(maze, row, col, rows, cols) # self._get_wall_char(row, col, rows, cols)
                else:
                    maze[row][col] = '·'

    def generate_42(self, maze, middle):
        for (row, col) in self._get_42_coords(middle):
            if 0 <= row < len(maze) and 0 <= col < len(maze[0]):
                maze[row][col] = 'F'
    

    def generate_rest(self, maze, rows, cols):
        """
        Asigna valores hexadecimales (0..E, excluyendo F) a las celdas interiores.
        Basado en los vecinos ya definidos (bordes y figura 42).
        """
        hex_numeros = list(range(16))        # 0..15
        hex_numeros_sin_F = [n for n in hex_numeros if n != 15]  # excluir F (15)
        coords_42 = set(self._get_42_coords((cols // 2, rows // 2)))

        while True:
            asignado = False
            for row in range(0, rows - 1):
                for col in range(0, cols - 1):
                    if maze[row][col] != '·': # casillas vacias aun
                        #print(f"Pinto un . en {row} {col}")
                        continue
                    if rows > 9 and cols > 7:
                        if (row, col) in coords_42:
                            continue  

                    vecinos = [
                        (row-1, col, 2, 0),  # norte: vecino sur (bit2) -> actual norte (bit0)
                        (row, col+1, 3, 1),  # este: vecino oeste (bit3) -> actual este (bit1)
                        (row+1, col, 0, 2),  # sur: vecino norte (bit0) -> actual sur (bit2)
                        (row, col-1, 1, 3)   # oeste: vecino este (bit1) -> actual oeste (bit3)
                    ]
                    print(f"los vecinos de {row} {col} son {vecinos} ")
                    
                    obligatorios = {}
                    for (nr, nc, bit_vec, bit_act) in vecinos:
                        if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                            continue
                        print(f"nr{nr}, nc{nc}, bit_vec{bit_vec}, bit_act{bit_act}")
                        valor_vecino = maze[nr][nc]
                        print(f"valor_vecino= {valor_vecino}")
                        # Ignorar celdas no asignadas o start/finish (aún no puestos)
                        if valor_vecino in ('·', '@', 'X'):
                            continue
                        try:
                            num_vecino = int(valor_vecino, 16)
                        except ValueError:
                            print("ERROR - vecinos")
                            continue
                        bit_val = (num_vecino >> bit_vec) & 1
                        obligatorios[bit_act] = bit_val
                        print(f"Obligatorios={obligatorios}")

                    if not obligatorios:
                        print("NO SON OBLIGATORIOS")
                        continue

                    def cumple(num):
                        for pos, valor in obligatorios.items():
                            if ((num >> pos) & 1) != valor:
                                return False
                        return True

                    # Usar solo números que no sean 15 (F)
                    candidatos = [n for n in hex_numeros_sin_F if cumple(n)]
                    print(f"candidatos: {candidatos} \n\n")
                    if not candidatos:
                        candidatos = [0]   # valor por defecto (todas las paredes abiertas)
                    nuevo_valor = random.choice(candidatos)
                    maze[row][col] = format(nuevo_valor, 'X')
                    print(f"Maz={maze[row][col]}")
                    asignado = True

            if not asignado:
                break
   
    def generate_all(self):
        rows, cols = self.height, self.width
        maze = [['' for _ in range(cols)] for _ in range(rows)]
        self.generate_walls(maze, rows, cols)
        if self.width > 9 and self.height > 7:
            self.generate_42(maze, (cols // 2, rows // 2))
        self.generate_rest(maze, rows, cols)   # <--- añadir esta línea
        # Sobrescribir start y finish
        # maze[self.start[1]][self.start[0]] = '@'
        # maze[self.finish[1]][self.finish[0]] = 'X'
        self.generate_maze = maze
        self._print_maze(maze)

    # Funciones auxiliares
    def _is_exterior_wall(self, row, col, rows, cols):
        return row == 0 or col == 0 or row == rows - 1 or col == cols - 1

    '''
    def _get_wall_char(self, row, col, rows, cols):
        if row == 0:  # arriba
            if col == 0:
                return random.choice(sorted(set(UPPER_WALL) & set(LEFT_WALL)))
            elif col == cols - 1:
                return random.choice(sorted(set(UPPER_WALL) & set(RIGHT_WALL)))
            else:
                return random.choice(UPPER_WALL)
        elif col == 0:  # izquierda
            if row == rows - 1:
                return random.choice(sorted(set(LOWER_WALL) & set(LEFT_WALL)))
            else:
                return random.choice(LEFT_WALL)
        elif col == cols - 1:  # derecha
            if row == rows - 1:
                return random.choice(sorted(set(LOWER_WALL) & set(RIGHT_WALL)))
            else:
                return random.choice(RIGHT_WALL)
        elif row == rows - 1:  # abajo
            return random.choice(LOWER_WALL)
    '''
    def _get_wall_neighbor(self, maze, row, col, rows, cols):
        # Esquina superior izquierda (0,0) - No tiene vecinos previos
        if row == 0 and col == 0:
            opciones = set(UPPER_WALL) & set(LEFT_WALL)
            return random.choice(sorted(opciones))

        elif row == 0:  # Fila superior (mira a su vecino izquierdo)
            val_izq = maze[row][col - 1]
            bit_este_izq = (int(val_izq, 16) >> 1) & 1  # Bit 1 (Este) del vecino izquierdo
            
            # El actual DEBE tener en su Bit 3 (Oeste) el mismo valor
            if col == cols - 1:  # Esquina superior derecha
                base = set(UPPER_WALL) & set(RIGHT_WALL)
            else:                # Resto de la pared superior
                base = set(UPPER_WALL)
                
            # Filtramos: el bit 3 (Oeste) del candidato debe ser igual al bit 1 (Este) del de la izquierda
            candidatos = [h for h in base if ((int(h, 16) >> 3) & 1) == bit_este_izq]
            return random.choice(candidatos) if candidatos else "0"

        elif col == 0:  # Pared izquierda (mira a su vecino de arriba)
            val_arr = maze[row - 1][col]
            bit_sur_arr = (int(val_arr, 16) >> 2) & 1  # Bit 2 (Sur) del vecino de arriba
            
            # El actual DEBE tener en su Bit 0 (Norte) el mismo valor
            if row == rows - 1:  # Esquina inferior izquierda
                base = set(LOWER_WALL) & set(LEFT_WALL)
            else:                # Resto de la pared izquierda
                base = set(LEFT_WALL)
                
            candidatos = [h for h in base if (int(h, 16) & 1) == bit_sur_arr] # Bit 0 (Norte)
            return random.choice(candidatos) if candidatos else "0"

        elif col == cols - 1:  # Pared derecha (mira a su vecino de arriba)
            val_arr = maze[row - 1][col]
            bit_sur_arr = (int(val_arr, 16) >> 2) & 1
            
            if row == rows - 1:  # Esquina inferior derecha
                base = set(LOWER_WALL) & set(RIGHT_WALL)
            else:
                base = set(RIGHT_WALL)
                
            candidatos = [h for h in base if (int(h, 16) & 1) == bit_sur_arr]
            return random.choice(candidatos) if candidatos else "0"

        elif row == rows - 1:  # Pared inferior (mira a su vecino izquierdo)
            val_izq = maze[row][col - 1]
            bit_este_izq = (int(val_izq, 16) >> 1) & 1
            
            base = set(LOWER_WALL)
            candidatos = [h for h in base if ((int(h, 16) >> 3) & 1) == bit_este_izq]
            return random.choice(candidatos) if candidatos else "0"

    def _is_start(self, row, col):
        return row == self.start[1] and col == self.start[0]

    def _is_finish(self, row, col):
        return row == self.finish[1] and col == self.finish[0]

    def _get_42_coords(self, middle):
        mc, mr = middle  # (col_centro, fila_centro)
        return [
            (mr - 2, mc - 3), (mr - 1, mc - 3), (mr, mc - 3),
            (mr, mc - 2), (mr, mc - 1),
            (mr + 1, mc - 1), (mr + 2, mc - 1),
            (mr - 2, mc + 1), (mr - 2, mc + 2), (mr - 2, mc + 3),
            (mr - 1, mc + 3), (mr, mc + 3),
            (mr, mc + 2), (mr, mc + 1),
            (mr + 1, mc + 1), (mr + 2, mc + 1),
            (mr + 2, mc + 2), (mr + 2, mc + 3)
        ]

    def _is_42(self, row, col, middle):
        return (row, col) in self._get_42_coords(middle)

    def _print_maze(self, maze):
        '''
        for row in maze:
            print(''.join(row))
            printable_maze=''.join(row)
        '''

        ''' --> esto viene de a version 3
        for row, row_max in enumerate(self.generate_maze):
            for tline in self.generate_maze[row]:
                print(tline, end='')
            print()
            printable_maze += ''.join(row) + '\n'
        display(printable_maze)
        '''

        printable_maze = ""
        for row_idx, row in enumerate(maze):
            for col_idx, cell in enumerate(row):
                print(cell, end='')
            print()  
            printable_maze += ''.join(row) + '\n'

        # Muestra el laberinto completo (opcional)
        print("\nLaberinto completo como cadena:")
        print(printable_maze)

        display(printable_maze)