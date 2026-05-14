#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_stream_management.py                          ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06          by lestrada        #+#    #+#             #
#   Updated: 2026/05/10          by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #


#!/usr/bin/env python3
import sys

def main():
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
        print(f"[STDERR] Error opening file '{filename}': {e}", file=sys.stderr)
        sys.exit(1)
    except PermissionError as e:
        print(f"[STDERR] Error opening file '{filename}': {e}", file=sys.stderr)
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
    new_filename = sys.stdin.readline().rstrip('\n')

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
            print(f"[STDERR] Error opening file '{new_filename}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)

if __name__ == "__main__":
    main()


