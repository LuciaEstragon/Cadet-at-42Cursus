#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_first_exception.py                            ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06 09:30:00 by lestrada        #+#    #+#             #
#   Updated: 2026/05/10 09:30:00 by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #


def input_temperature(temp_str: str) -> float:
    '''
    Funcion que recibe un string como entrada, lo convierte a numero entero
    y devuelve como numero entero.
    Funcion analoga al atoi() de c en python, pero:
        - en python no existe desbordamiento por INT_MAX
        - el casteo te permite cambiar de type automaticamente
        - no tienes que preocupare de gestionar el signo o espacios
    '''    
    try:
        # Intentamos la conversión
        temperature = float(temp_str)
        return temperature
    
    except ValueError:
        # Se ejecuta si temp_str no se puede convertir a número
        print("Caught input_temperature error: "
             f"invalid literal for int() with base 10: {temp_str}\n"
             f"It was received a invalid {type(temp_str).__name__}\n")
        return 0.0


def main() -> None:
    print("=== Garden Temperature ===\n")

    user_input = input("Input data is ")
    my_temperature = input_temperature(user_input)
    print(f"Temperature is now: {my_temperature:.2f}°C")

    print("All tests completed - program didn't crash!\n")


if __name__ == "__main__":
    main()

"""
=================
NOTA!
Creo que cuando salta el error no deberia de continuar con mi main, hay algoo raro, no?
Mirar el whatif



La clase Base Exception es:

class MiError(Exception):
    pass

try:
    raise MiError("Algo salió mal")
except Exception as e:
    print(f"Excepción capturada: {e}")

"""