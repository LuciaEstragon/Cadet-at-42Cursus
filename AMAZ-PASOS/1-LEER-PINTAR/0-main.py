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
        content = f.read()
        f.close()
        print()
        print(content, end='')
        print()
        print(f"File '{filename}' closed.")
    except FileNotFoundError as e:
        print(f"Error opening file '{filename}': {e}")
    except PermissionError as e:
        print(f"File permissions error '{filename}': {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")
   
    # Dibuja
    print(content)

if __name__ == "__main__":
    main()
