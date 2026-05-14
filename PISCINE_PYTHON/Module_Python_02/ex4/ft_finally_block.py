#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_finally_block.py                              ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06 by lestrada                 #+#    #+#             #
#   Updated: 2026/05/10 by lestrada                ###   ########.es       #
#                                                                          #
# ************************************************************************ #

class PlantError(Exception):
    def __init__(self, message: str = "Error de planta"):
        super().__init__(message)

def water_plant(plant_name: str) -> None:
    if plant_name != plant_name.capitalize():
        raise PlantError(f"Caught PlantError: Invalid plant name to water: '{plant_name}'"
                        ".. ending tests and returning to main")
    print(f"Watering {plant_name}: [OK]")

def test_watering_system() -> None:
    try:
        print("Testing valid plants...")
        print("Opening watering system")
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrot")

        print()
        print("Testing invalid plants...")
        print("Opening watering system")
        water_plant("Tomato")
        water_plant("lettuce")
        water_plant("Carrot")
    except PlantError as e:
        print(f"Capturado PlantError: {e}")
        print("Terminando pruebas y volviendo a main")
        return
    finally:
        print("Closing watering system")

def main():
    print("=== Garden Error Types Demo ===\n")
    test_watering_system()
    print()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    main()
