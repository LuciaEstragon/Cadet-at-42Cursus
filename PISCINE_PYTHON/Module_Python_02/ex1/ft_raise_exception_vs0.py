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
    """
    - Verifica si la temperatura es razonable para las plantas (0 a 40 grados Celsius, límites incluidos)
    - Devuelve la temperatura si es válida; de lo contrario, lanza una excepción.
    """
    # Intentar convertir la entrada a entero
    try:
        temperature = int(temp_str.strip())
        print(f"Temperature is now {temperature}°C")
    except ValueError as e:
        # Si falla la conversión, relanzamos la excepción
        raise e
    
    # Validar rango para cultivos agrícolas
    if temperature < 0:
        raise IndexError(f"{temperature}°C is too cold for plants (min 0°C)")
    
    if temperature > 40:
        raise IndexError(f"{temperature}°C is too cold for plants (min 0°C)")

    # Temperatura válida
    return temperature


def test_temperature() -> None:
    """
    Agrega nuevas pruebas. Comprueba:
    - Valores normales dentro del rango
    - Valores no numéricos
    - Valores extremos fuera del rango ("100", "-50")
    """
    print("=== Garden Temperature Checker ===")
    print()
    
    # Caso 1: Temperatura válida
    print("Testing valid temperature:")
    print(f"Input data is '25'")
    try:
        temp = input_temperature("25")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    
    # Caso 2: Entrada no numérica
    print("Testing invalid input (non-numeric):")
    print(f"Input data is 'abc'")
    try:
        temp = input_temperature("abc")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    
    # Caso 3: Temperatura demasiado alta
    print("Testing extreme hot temperature:")
    print(f"Input data is '100'")
    try:
        temp = input_temperature("100")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    
    # Caso 4: Temperatura demasiado baja
    print("Testing extreme cold temperature:")
    print(f"Input data is '-50'")
    try:
        temp = input_temperature("-50")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    
    print("All tests completed - program didn't crash!")



if __name__ == "__main__":
    test_temperature()
