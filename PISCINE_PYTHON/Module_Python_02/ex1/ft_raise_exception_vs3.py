#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_raise_exception.py                            ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06 by lestrada                 #+#    #+#             #
#   Updated: 2026/05/10 by lestrada                ###   ########.es       #
#                                                                          #
# ************************************************************************ #


def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)  # puede lanzar ValueError
    if temp < 0 or temp > 40:
        raise IndexError(f"{temp}°C está fuera del rango permitido (0-40)")
    return temp

def test_temperature() -> None:
    tests = ["25", "abc", "100", "-50"]
    for value in tests:
        print(f"Input data is '{value}'")
        try:
            temp = input_temperature(value)
            print(f"Temperatura válida: {temp}°C")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
        print()

    print("All tests completed - program didn't crash!")

if __name__ == "__main__":
    test_temperature()