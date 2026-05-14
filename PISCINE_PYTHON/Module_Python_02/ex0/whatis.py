import sys

def main():
    assert len(sys.argv) != 2, "more than one argument is provided"
    
    try:
        numero = int(sys.argv[1])
        if numero % 2 == 0:
            print("I'm Even.\n")
        else:
            print("I'm Odd.\n")
    except ValueError:
        raise AssertionError("argument is not an integer")

if __name__ == "__main__":
    main()

'''
assert es para DEPURACIÓN (encontrar bugs)
if es para CONTROL DE FLUJO (decisiones normales del programa)

assert se usa para:
    Detectar errores lógicos tempranos o algo que no deberia dar este resultado segun el programador
    Validar "invariantes" (cosas que SIEMPRE deberían ser ciertas)
    Depuración (se pueden desactivar globalmente)

if se usa para tomar una decision en el codigo

try-except	Manejar errores que no puedes controlar que salgan
'''

'''
raise	Lanza una excepción explícitamente
raise AssertionError()	Crea y lanza un nuevo AssertionError
raise sin argumentos	Vuelve a lanzar la última excepción capturada
'''


'''
Usa assert solo para condiciones que TÚ, como programador, garantizas que son verdad. 
Por defecto: matan el programa inmediatamente.
'''

'''
return - raise - exit

# return - Para funciones normales
def calcular():
    return 42  # Vuelve a quien llamó la función

# raise - Para errores que otros deben manejar
def validar():
    if algo_mal:
        raise ValueError("Error")  # Quien llama decide qué hacer

# sys.exit() - Para terminar TODO el programa
def main():
    if error_fatal:
        sys.exit(1)  # Mata el programa completo

sys.exit(0)	Éxito	Todo funcionó correctamente
sys.exit(1)	Error genérico	Algo salió mal (error general)
sys.exit(2)	Error específico	Diferentes códigos para diferentes errores
sys.exit()	Éxito	Igual que sys.exit(0)

Regla de oro: Usa sys.exit() en scripts y programas principales para indicar éxito/fracaso.
No lo uses en librerías o funciones reutilizables (ahí usa raise).
'''