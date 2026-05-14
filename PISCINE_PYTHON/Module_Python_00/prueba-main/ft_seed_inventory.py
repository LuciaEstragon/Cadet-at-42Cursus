# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_seed_inventory.py                             ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/04/02 09:30:00 by lestrada        #+#    #+#             #
#   Updated: 2026/04/02 09:30:00 by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    print(f"{seed_type} seeds: {quantity} ", end=" ")
    if unit == "packets":
        print("packets available")
    elif unit == "grams":
        print("grams total")
    elif unit == "area":
        print("square meters")
    else:
        print("Unknown unit type")


'''
EL TEST QUE HACE ES MUY INTERESANTE, MAS QUE EL EJERCICIO EN SI


def test_ft_exercise(exercise_file_name):
    """
    This function tries to run one of your exercises.

    For example: test_ft_exercise("ft_plot_area") will:
    - Look for a file called ft_plot_area.py
    - Import it
    - Call the function ft_plot_area() inside it
    """
    print(f"\n=== Testing {exercise_file_name} ===")

    try:
        # Import your exercise file
        # This is like doing: import ft_plot_area
        import sys
        sys.path.append(".")
        ft_module = __import__(exercise_file_name)

        # Get the function from your file
        # This is like doing: ft_plot_area.ft_plot_area
        ft_function = getattr(ft_module, exercise_file_name)

        # Special handling for ft_seed_inventory (Exercise 7)
        # This function takes parameters, unlike the others
        if exercise_file_name == "ft_seed_inventory":
            print("Testing with different seed types and units:\n")
            # Test with packets
            ft_function("tomato", 15, "packets")
            # Test with grams
            ft_function("carrot", 8, "grams")
            # Test with area
            ft_function("lettuce", 12, "area")
            # Test with unknown unit
            print("\nTesting with unknown unit:")
            ft_function("basil", 5, "unknown")
        else:
            # Run your function normally (no parameters)
            ft_function()

    except ImportError:
        print(f"❌ Could not find {exercise_file_name}.py")
        print(
            """   Make sure your file exists and is in the same
            folder as main.py"""
        )

    except AttributeError:
        print(f"❌ Could not find function {exercise_file_name}() in your file")
        print(f"   Make sure you have: def {exercise_file_name}():")

    except TypeError as error:
        msg = str(error)
        print(f"❌ Type error: {error}")
        if exercise_file_name == "ft_seed_inventory":
            if "missing" in msg and "required positional argument" in msg:
                print(
                    """   For exercise 7, make sure your

                    function takes parameters:"""
                )
                print(
                    f"   def {exercise_file_name}"
                    "(seed_type: str, quantity: int, unit: str) -> None:"
                )
        else:
            print("   Your function should not take any parameters")

    except Exception as error:
        print(f"❌ Error running your function: {error}")
        print("   Check your code for syntax errors")


'''
