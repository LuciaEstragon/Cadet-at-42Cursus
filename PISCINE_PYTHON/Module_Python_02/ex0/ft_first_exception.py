#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_first_exception.py                            ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06          by lestrada        #+#    #+#             #
#   Updated: 2026/05/10          by lestrada       ###   ########.es       #
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
        print(f"Temperature is now: {temperature:.2f}°C")
        return temperature

    except ValueError:
        print("Caught input_temperature error: "
             f"invalid literal for int() with base 10: {temp_str}\n"
             f"It was received a invalid {type(temp_str).__name__}\n")
        return 0.0 ## sys.exit(1)  # Mata el programa completo


def main() -> None:
    print("=== Garden Temperature ===\n")

    user_input = input("Input data is ")
    input_temperature(user_input)

    ## AQUI! Aunque la excepcion esta recogida y sale un mensaje de error, 
    # y el programa no peta, el programa va a seguir con el dato usandolo mal
    # esta evitando solo que mi programa pete, pero lo protege del todo
    # my_temperature = input_temperature(user_input)
    # print(f"Temperature is now: {my_temperature:.2f}°C")
    # por eso, si puedes hacer lo requerido, opera con el numero en el try,
    # y no fuera

    print("All tests completed - program didn't crash!\n")


if __name__ == "__main__":
    main()
