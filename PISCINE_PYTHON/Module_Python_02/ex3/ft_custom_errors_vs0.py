#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_custom_errors.py                              ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06 by lestrada                 #+#    #+#             #
#   Updated: 2026/05/10 by lestrada                ###   ########.es       #
#                                                                          #
# ************************************************************************ #

class GardenError(Exception):
    def __init__(self, message: str = "Error general del jardín"):
        self.message = message
        super().__init__(message)

class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!"):
        super().__init__(message)

class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!"):
        super().__init__(message)

def test_plant() -> None:
    try:
        raise PlantError()
    except PlantError as e:
        print(f"Caught PlantError: {e}")

def test_water() -> None:
    try:
        raise WaterError()
    except WaterError as e:
        print(f"Caught WaterError: {e}")

def test_garden_error() -> None:
    try:
        raise GardenError()
    except GardenError as e:
        print(f"Caught GardenError: {e}")

def main() -> None:
    print("=== Garden Error Types Demo ===\n")
    print("Testing PlantError...")
    test_plant()
    print()
    print("Testing WaterError...")
    test_water()
    print()
    print("Testing catching all garden errors...")
    test_garden_error()
    print()
    print("All custom error types work correctly!\n")

if __name__ == "__main__":
    main()
