#!/usr/bin/env python3


import sys

def main() -> None:
    # Recibe Argumentos -- Py3-ex0
    args = sys.argv
    prog_name = args[0]
    list_args = args[1:]
    num_args = len(list_args)

    print("== Welcome to A-MAZE-ING ==")
    print(f"Program name: {prog_name}")

    if num_args != 1:
        print("Error: Incorrect argument: Give TXT file!")
        sys.exit(1)
    
    # Abre fichero -- Py4 - ex0
    filename = sys.argv[1]

    try:
        f = open(filename, 'r')
        maze = f.read()
        f.close()
    except FileNotFoundError as e:
        print(f"Error opening file '{filename}': {e}")
    except PermissionError as e:
        print(f"File permissions error '{filename}': {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")
   
    # Dibuja
    display(maze)

def draw_F():
    return "####\n#  #\n####\n"


def display(maze):
    print(maze)

    row = 0
    col = 0
    draw_maze = [[]]
    for dato in maze:
        if dato != '\n':
            if dato == 'F':
                draw_maze[row].append(draw_F())
            else:
                draw_maze[row].append(draw_F())
            col += 1
        else:
            draw_maze.append([])
            row += 1
    
    print(draw_maze)
    print()
    """
    for elem_row in draw_maze:
        for elem_col in elem_row: 
            print(elem_col)
    """



if __name__ == "__main__":
    display("951539153953\nEBABE8128532\n96A8416A845A\nC3A83816A936\n96842A852AC2\nC5455646C45C")
