#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_different_errors.py                           ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06 by lestrada                 #+#    #+#             #
#   Updated: 2026/05/10 by lestrada                ###   ########.es       #
#                                                                          #
# ************************************************************************ #

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")  # ValueError
    elif operation_number == 1:
        1 / 0       # ZeroDivisionError
    elif operation_number == 2:
        open("/non/existent/file")  # FileNotFoundError
    elif operation_number == 3:
        "texto" + 5  # TypeError
    else:
        return


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===\n")
    for op in range(5):  # 0,1,2,3,4
        print(f"Testing operation {op}...")
        try:
            garden_operations(op)
            print("Operation completed successfully")
        except (ValueError, ZeroDivisionError, FileNotFoundError,
                TypeError) as e:
            print(f"Caught {type(e).__name__}: {e}")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
