import sys
import random
from config_params import ConfigParams

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
                    maze[row][col] = self._get_wall_char(row, col, rows, cols)
                else:
                    maze[row][col] = '·'

    def generate_42(self, maze, middle):
        for (row, col) in self._get_42_coords(middle):
            if 0 <= row < len(maze) and 0 <= col < len(maze[0]):
                maze[row][col] = 'F'

    def generate_all(self):
        rows, cols = self.height, self.width
        maze = [['' for _ in range(cols)] for _ in range(rows)]
        self.generate_walls(maze, rows, cols)
        self.generate_42(maze, (cols // 2, rows // 2))
        # Sobrescribir start y finish
        maze[self.start[1]][self.start[0]] = '@'
        maze[self.finish[1]][self.finish[0]] = 'X'
        self.generate_maze = maze
        self._print_maze(maze)

    # Funciones auxiliares
    def _is_exterior_wall(self, row, col, rows, cols):
        return row == 0 or col == 0 or row == rows - 1 or col == cols - 1

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
        for row in maze:
            print(''.join(row))