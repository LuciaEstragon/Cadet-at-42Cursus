# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_count_harvest_recursive.py                    ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/04/02 09:30:00 by lestrada        #+#    #+#             #
#   Updated: 2026/04/02 09:30:00 by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #

'''
Tres enfoques:
1. Funcion anidada
2. Usar valores de parametros determinados
3. Funcion auxiliar independiente
'''


def ft_count_harvest_recursive():
    day = int(input("Days until harvest: "))

    def aux(current):
        if current > day:
            print("Harvest time!")
            return
        print(f"Day {current}")
        aux(current + 1)
    aux(1)


'''
# 2
def ft_count_harvest_recursive(day=None, current=1):
    # Pedimos el input solo si es la primera ejecución (day es None)
    if day is None:
        day = int(input("Days until harvest: "))
    if current <= day:
        print(f"Day {current}")
        # Llamada recursiva pasando el total y el incremento
        ft_count_harvest_recursive(day, current + 1)
    else:
        print("Harvest time!")

# Llamada inicial
ft_count_harvest_recursive()

# 3
def recursive_counter(current, target):
    if current > target:
        print("Harvest time!")
        return
    print(f"Day {current}")
    recursive_counter(current + 1, target)

# Función principal que prepara los datos
def ft_count_harvest_recursive():
    day = int(input("Days until harvest: "))
    recursive_counter(1, day)
'''


"""
Para el Main :
'''
from ex0.ft_hello_garden import ft_hello_garden
from ex1.ft_garden_name import ft_garden_name
from ex2.ft_plot_area import ft_plot_area
from ex3.ft_harvest_total import ft_harvest_total
from ex4.ft_plant_age import ft_plant_age
from ex5.ft_water_reminder import ft_water_reminder
from ex6.ft_count_harvest_iterative import ft_count_harvest_iterative
from ex6.ft_count_harvest_recursive import ft_count_harvest_recursive
from ex7.ft_seed_inventory import ft_seed_inventory
'''
"""