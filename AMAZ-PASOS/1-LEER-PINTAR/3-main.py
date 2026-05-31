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

def draw_E():
    return ["####", "#  #", "####"]

def draw_F():
    return ["####", "####", "####"]


def display(maze):
    print(maze)

    row = 0
    col = 0
    draw_maze = [[]]
    for dato in maze:
        if dato != '\n':
            if dato == '0':
                draw_maze[row].append(draw_0())
            if dato == '1':
                draw_maze[row].append(draw_1())
            if dato == '2':
                draw_maze[row].append(draw_2())
            if dato == '3':
                draw_maze[row].append(draw_3())
            if dato == '4':
                draw_maze[row].append(draw_4())
            if dato == '5':
                draw_maze[row].append(draw_5())
            if dato == '6':
                draw_maze[row].append(draw_6())
            if dato == '7':
                draw_maze[row].append(draw_7())
            if dato == '8':
                draw_maze[row].append(draw_8())
            if dato == '9':
                draw_maze[row].append(draw_9())
            if dato == 'A':
                draw_maze[row].append(draw_A())
            if dato == 'B':
                draw_maze[row].append(draw_B())
            if dato == 'C':
                draw_maze[row].append(draw_C())
            if dato == 'D':
                draw_maze[row].append(draw_D())
            if dato == 'E':
                draw_maze[row].append(draw_E())
            if dato == 'F':
                draw_maze[row].append(draw_F())
            col += 1
        else:
            draw_maze.append([])
            row += 1
    
    casilla = []
    print()
    for elem_row in draw_maze:
        for elem_col in elem_row:  # todos los elementos de la fila
            casilla += elem_col    # los elementos de cada fila, por columna -- esto tambien es una matriz
        # print(casilla[0: :3])
        # print(casilla[1: :3])
        # print(casilla[2: :3])
        str_casilla =  ""
        for i in range(0, len(casilla), 3):
            str_casilla += casilla[i]
        print(str_casilla)
        str_casilla =  ""
        for i in range(1, len(casilla), 3):
            str_casilla += casilla[i]
        print(str_casilla)
        str_casilla =  ""
        for i in range(2, len(casilla), 3):
            str_casilla += casilla[i]
        print(str_casilla)
        casilla = []


if __name__ == "__main__":
    display("951539153953\nEBABE8128532\n96A8416A845A\nC3A83816A936\n96842A852AC2\nC5455646C45C")
