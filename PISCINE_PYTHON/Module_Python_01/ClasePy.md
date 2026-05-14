# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_garden_intro.py                               ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/04/02 09:30:00 by lestrada        #+#    #+#             #
#   Updated: 2026/04/27 09:30:00 by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #

# Crear una Clase simple 
# esto son atributos que tiene la clase planta: name, height, and age.
# debe tener un metodo para poder pintar

# 1. Crear la clase
class Plant:
    # Constructor con atributos
    def __init__(self, my_name, my_height, my_age):
        self.name = my_name
        self.height = my_height
        self.age = my_age

    # Método para imprimir los atributos
    def display_info(self):
        print(f"Plant: {self.name} \n" +
            f"Height: {self.height} cm \n" + 
            f"Age: {self.age} days \n " )

# 2. Función main para llamar a la clase
def main():
    # Crear Iinstancias de la clase (objetos)
    plant1 = Plant("Rose", 25, 300)
    plant2 = Plant("my_plant", 35, "five")
    # plant3 = Plant("mini plant", 40) # error, needs an other parameter

    # Llamar al método del objeto
    plant1.display_info()
    plant2.display_info()

# 3. Llamada del main
if __name__ == "__main__":
    main()

