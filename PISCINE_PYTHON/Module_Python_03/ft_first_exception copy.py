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


import random


NAMES = ["aRagorn", "Legolas", "GIMLI", "Frodo", "sam", "GANDALF", "arWeN"]

def capitalizer_case(list_name) -> list:
    list_lower = [name.lower() for name in list_name]
    list_capitalizer = [name[0].upper() for name in list_lower]
    return list_capitalizer

def are_capitalizer(list_name) -> list:
    return [name for name in original_names if name.isupper()]

def give_score(list_name) -> list:

def main() -> None:
    print("=== Game Data Archemist===")
    original_names = NAMES
    print("Initial names of players:", original_names)

    # Capitalizer
    names_capitalizer = []
    names_capitalizer = append.upper_case(original_names)
    print(f"New list with all names capitalized: {names_capitalizer}")

    # Only those already capitalizer in original
    already_cap = are_capitalizer(original_names)
    print(f"New list of capitalized names only: {already_cap}")

    # give scores - sum scores - high
    dic = {name.upper(): random.randint(50, 200) for name in names_capitalizer} 
    print("Score dict: {dic}")
    avg_score = sum(dic.values()) / len(dic)
    print("Score average is {avg_score}")
    high_performers = {
        name: score for name, score in scores.items() if score > avg_score
    }
    print("High scores: {high_performers}")


if __name__ == "__main__":
    main()

