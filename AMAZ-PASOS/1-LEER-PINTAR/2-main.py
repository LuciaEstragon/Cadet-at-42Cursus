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

def draw_0():
    return ["    ", "    ", "    "]
def draw_1():
    return ["####", "    ", "    "]
def draw_2():
    return ["   #", "   #", "   #"]
def draw_3():
    return ["####", "   #", "   #"]
def draw_4():
    return ["    ", "    ", "####"]
def draw_5():
    return ["####", "   #", "####"]
def draw_6():
    return ["   #", "   #", "####"]
def draw_7():
    return ["####", "#  #", "####"]
def draw_8():
    return ["#   ", "#   ", "#   "]
def draw_9():
    return ["####", "#   ", "#   "]
def draw_A():
    return ["#  #", "#  #", "#  #"]
def draw_B():
    return ["####", "#  #", "#  #"]
def draw_C():
    return ["#   ", "#   ", "####"]
def draw_D():
    return ["####", "#   ", "####"]
def draw_F():
    return ["####", "#  #", "####"]

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
    
    # print(draw_maze)
    """
    print()
    for elem_row in draw_maze:
        for elem_col in elem_row:  # todos los elementos de la fila
            print(elem_col)        # los elementos de cada fila, por columna -- esto tambien es una matriz
            print()
        print("row")
    """
    """
    print()
    for elem_row in draw_maze:
        for elem_col in elem_row: 
            casilla = elem_col
            print("1--->")
            print(casilla[0])
            print("  2--->")
            print(casilla[1])
            print("  3--->")
            print(casilla[2])
        
        print("row")
    """

    # print(draw_maze)
    casilla = []
    print()
    for elem_row in draw_maze:
        for elem_col in elem_row:  # todos los elementos de la fila
            casilla += elem_col    # los elementos de cada fila, por columna -- esto tambien es una matriz
        print(casilla[0: :3])
        print(casilla[1: :3])
        print(casilla[2: :3])
        casilla = []

    



if __name__ == "__main__":
    display("951539153953\nEBABE8128532\n96A8416A845A\nC3A83816A936\n96842A852AC2\nC5455646C45C")
