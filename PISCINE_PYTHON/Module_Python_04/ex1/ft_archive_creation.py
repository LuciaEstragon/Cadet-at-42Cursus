#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_archive_creation.py                           ::+::    :+:    :+:   #
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
        print("Usage: ft_archive_creation.py <file>")
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
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)
    except PermissionError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)

    # Transform data: add '#' at the end of each line
    transformed_lines = []
    for line in lines:
        # Remove trailing newline, add '#', then add newline back
        line = line.rstrip('\n')
        transformed_lines.append(line + '#\n')

    print("\nTransform data:\n")
    for tline in transformed_lines:
        print(tline, end='')
    print()

    # Ask for output filename
    new_filename = input("Enter new file name (or empty): ").strip()
    if new_filename == "":
        print("Not saving data.")
    else:
        try:
            f_out = open(new_filename, 'w')
            f_out.writelines(transformed_lines)
            f_out.close()
            print(f"Saving data to '{new_filename}'")
            print(f"Data saved in file '{new_filename}'.")
        except Exception as e:
            print(f"Error saving to '{new_filename}': {e}")

if __name__ == "__main__":
    main()
