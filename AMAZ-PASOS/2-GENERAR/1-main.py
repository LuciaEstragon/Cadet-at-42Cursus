#!/usr/bin/env python3

# ejercicio Py2 -ex02, ex03 y ex04

import sys

class ConfigParams:
    width = -1
    height = -1
    start = [-1, -1]
    finish = [-1, -1] 
    out_file = "output_maze.txt"
    perfect = -1
    in_file = ""
    generate_maze = [[]] # deberia ser privado

    def __init__(self, filename):
        self.in_file = filename
    
    def get_input_file(self):
        pass

    def generate(self):
        pass

    def parse(self):
        config_file = open(self.in_file, "r")
        line_num = 1
        while line_num:
            line = config_file.readline()
            print(line)
            # ( .... )
            if line.startswith("OUTPUT_FILE="):
                self.out_file = line[12:]
                print(self.out_file)
                if not self.out_file:
                    print("ERROR: failure parsing OUTPUT_FILE's name.")
                line_num = 0
                print("hola")
        config_file.close()
        return True


class Maze (ConfigParams):
    def get_input_file(self):
        try:
            f_out = open(self.out_file, 'w')
            write_lines = [''.join(fila) + '\n' for fila in self.generate_maze]
            f_out.writelines(write_lines) # este metodo solo escribe lineas completas, no matrizes.
            f_out.close()
        except PermissionError as e:
            print("[STDERR] Error opening file "
                  f"'{new_filename}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)
    
    def generate(self):
        self.generate_maze = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        print("genero un laberinto)")
        for tline in self.generate_maze:
            print(tline, end='')


# Check that only one configuration file is given
def main():
    num_args = len(sys.argv) - 1
    if num_args != 1 :
        if num_args < 1 :
            print("ERROR: A configuration file needs to be provided.")
        else:
            print("ERROR: Too many arguments have been given.")
        print("Please, call the script as follows: \"python3", sys.argv[0], "filename\"")
        exit()

    maze = Maze(sys.argv[1])
    if not maze.parse():
        print("ERROR: failure parsing configuration file")
        exit()

    print("Configuration file was parsed successfully")

    print()
    print("Generated new Maze")
    maze.generate()
    maze.get_input_file()


if __name__ == "__main__":
    main()
    