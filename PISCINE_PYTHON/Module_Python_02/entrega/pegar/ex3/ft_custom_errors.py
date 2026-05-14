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
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error"):
        super().__init__(message)


def test_plant() -> None:
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")


def test_water() -> None:
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")


def test_garden_error() -> None:
    # Primero lanzamos PlantError y lo capturamos como GardenError
    try:
        raise PlantError("The tomato plant is wilting!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    # Luego lanzamos WaterError y también lo capturamos como GardenError
    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")


def main() -> None:
    print("=== Custom Garden Errors Demo ===\n")
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
