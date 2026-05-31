

def draw_0():
    return ["    ", "    ", "    "]

def draw_1():
    return ["1111", "    ", "    "]

def draw_2():
    return ["   2", "   2", "   2"]

def draw_3():
    return ["3333", "   3", "   3"]

def draw_4():
    return ["    ", "    ", "4444"]

def draw_5():
    return ["5555", "   5", "5555"]

def draw_6():
    return ["   6", "   6", "6666"]

def draw_7():
    return ["7777", "   7", "7777"]

def draw_8():
    return ["8   ", "8   ", "8   "]

def draw_9():
    return ["9999", "9   ", "9   "]

def draw_A():
    return ["A  A", "A  A", "A  A"]

def draw_B():
    return ["BBBB", "B  B", "B  B"]

def draw_C():
    return ["C   ", "C   ", "CCCC"]

def draw_D():
    return ["DDDD", "D   ", "DDDD"]

def draw_E():
    return ["E  E", "E  E", "EEEE"]

def draw_F():
    return ["FFFF", "F  F", "FFFF"]


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
            '''
            else:
                draw_maze[row].append(draw_F())
            '''
            col += 1
        else:
            draw_maze.append([])
            row += 1
    
    casilla = []
    print()
    for i, elem_row in enumerate(draw_maze):
        for elem_col in elem_row:  # todos los elementos de la fila
            casilla += elem_col    # los elementos de cada fila, por columna -- esto tambien es una matriz

        # para quitar el muro que sobra entre arriba y abajo
        # para quitar el muro que sobra entre izq y der
        if i == 0:
            str_casilla =  ""
            str_casilla_check = ""
            for i in range(0, len(casilla), 3):
                str_casilla = casilla[i]
                if i == len(casilla)-3:
                    str_casilla_check += str_casilla
                else:
                    str_casilla_check += str_casilla[0:-1:]
            print(str_casilla_check)

        str_casilla =  ""
        str_casilla_check = ""
        for i in range(1, len(casilla), 3):
            str_casilla = casilla[i]
            if i == len(casilla)-2:
                str_casilla_check += str_casilla
            else: 
                str_casilla_check += str_casilla[0:-1:]
        print(str_casilla_check)

        str_casilla =  ""
        str_casilla_check = ""
        for i in range(2, len(casilla), 3):
            str_casilla = casilla[i]
            if i == len(casilla)-1:
                str_casilla_check += str_casilla
            else: 
                str_casilla_check += str_casilla[0:-1:]
        print(str_casilla_check)
        casilla = []
        
if __name__ == "__main__":
    main()
