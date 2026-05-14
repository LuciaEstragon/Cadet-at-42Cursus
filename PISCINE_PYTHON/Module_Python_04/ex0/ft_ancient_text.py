#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_ancient_text.py                               ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06          by lestrada        #+#    #+#             #
#   Updated: 2026/05/10          by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #


import sys


def main():
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        sys.exit(1)

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

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
        print(f"Error opening file '{filename}': {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")


if __name__ == "__main__":
    main()

