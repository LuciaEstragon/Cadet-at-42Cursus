#!/usr/bin/env python3


import sys


def main() -> None:
    # Recibe argumentos - lee fichero - genera fichero nuevo -- Py3-ex2 ->> Linea 50 cambia
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        sys.exit(1)

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        f = open(filename, 'r')
        lines = f.readlines()
        f.close()
        print()
        for line in lines:
            print(line, end='')
        print()
        print(f"File '{filename}' closed.")
    except FileNotFoundError as e:
        print("[STDERR] Error opening file"
              f"'{filename}': {e}", file=sys.stderr)
        sys.exit(1)
    except PermissionError as e:
        print("[STDERR] Error opening file"
              f"'{filename}': {e}", file=sys.stderr)
        sys.exit(1)

    # Transform data
    transformed_lines = []
    for line in lines:
        line = line.rstrip('\n')
        transformed_lines.append(line + '#\n')

    print("\nTransform data:\n")
    for tline in transformed_lines:
        print(tline, end='')
    print()

    # Read input without input() - using sys.stdin
    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    new_filename = lines[0] # Linea 50 cambia -> sys.stdin.readline().rstrip('\n')

    if new_filename == "":
        print("Not saving data.")
    else:
        try:
            f_out = open(new_filename, 'w')
            f_out.writelines(transformed_lines)
            f_out.close()
            print(f"Saving data to '{new_filename}'")
            print(f"Data saved in file '{new_filename}'.")
        except PermissionError as e:
            print("[STDERR] Error opening file "
                  f"'{new_filename}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)


if __name__ == "__main__":
    main()