Python Modulo 02


Data Pipeline y manejo de excepciones - Sistemas más robustos
 'try', 'except', 'finally' y 'raise' 

 Excepciones y tipos de error: ValueError, TypeError, ZeroDivisionError, FileNotFoundError, KeyError, IndexError, AttributeError y la clase base Exception.
 
Exception		Error generico (base)
ValueError		Tipo correcto pero valor incorrecto 	: Recivo "veinticinco" en lugar de "25". El tipo es str (correcto), pero el valor no es numérico.
TypeError		Operación entre tipos incorrectos	: Quieren sumar temperatura (int) con humedad (str) por error.
ZeroDivisionError       División por cero
FileNotFoundError	Archivo inexistente
KeyError		Clave de diccionario inexistente
IndexError		Índice fuera de rango	
AttributeError		Atributo inexistente			: confundes una variable que es un número con un objeto Planta


Ex0: Capturar excepciones básicas (try/except).

Ex1: Lanzar excepciones (raise) con condiciones (rango válido).

Ex2: Distinguir y capturar múltiples tipos de excepción.

Ex3: Crear jerarquías de excepciones personalizadas.

Ex4: Usar finally para liberar recursos.



ERROR raise -> ejecuta lo que sea y genera un error en tu codigo (metiendole un mensaje propio) y se va al primer except qe encuentre.
def dividir(a, b):
    if b == 0:
        raise ZeroDivisionError("No se puede dividir por cero")
    return a / b
raise convierte una condicion anomala en una excepcion activa. Asi separas el manejo de los errores y la logica. 

finally: sirve para poder cerrar las cosas que se hallan quedado abiertas antes de que todo se cierre por el error.


JERARQUIAS DE ERRORES:  (builtins.pyi)

Todos los eerores predefinidos que he utilizado funcionan porque estan ya predefinidos, y heredan todos de Exception

class SystemError(Exception): ...
class TypeError(Exception): ...
class ValueError(Exception): ...
class FloatingPointError(ArithmeticError): ...
class OverflowError(ArithmeticError): ...
class ZeroDivisionError(ArithmeticError): ...
class ModuleNotFoundError(ImportError): ...
class IndexError(LookupError): ...
class KeyError(LookupError): ...
class UnboundLocalError(NameError): ...

voy a crearme un error personalizado que se llame 
class GardenError(Exception):

Hereda de exception, por eso va a poder hacer lo mismo que cualquier otro error
class PlantError(GardenError):

Ete hereda de Garden, asi que hace todo lo que puede hacer una herencia

