# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_garden_intro.py                               :+:      :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/04/02 09:30:00 by lestrada        #+#    #+#             #
#   Updated: 2026/04/02 09:30:00 by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #

def ft_garden_intro(plant: str, height: int, age: int) -> None:
	print(f"Plant: {plant}")
	print(f"Height: {height}cm")
	print(f"Age: {age} days")	

if __name__ == "__main__":
	print("=== Welcome to My Garden ===")
	ft_garden_intro("Rose", 25, 30)
	print("=== End of Program ===")

