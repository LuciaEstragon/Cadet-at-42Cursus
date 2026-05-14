Resumen de conocimientos teóricos requeridos por ejercicio
Ejercicio 0 – Recuperación de texto antiguo
Argumentos de línea de comandos: uso de sys.argv para obtener el nombre del archivo.

Apertura y cierre de archivos: función open(), modos de apertura (predeterminado lectura).

Lectura de archivos: método .read().

Manejo de excepciones: try/except para capturar FileNotFoundError, PermissionError, etc.

Salida formateada: uso de print() con formato similar al ejemplo.

Tipo de retorno de open(): objeto _io.TextIOWrapper (un flujo de texto).

Ejercicio 1 – Creación de archivo
Reutilización de código: partir del ejercicio 0 y extender funcionalidad.

Manipulación de cadenas: agregar carácter # al final de cada línea.

Entrada de usuario: función input() para obtener nombre de archivo destino.

Escritura de archivos: modo 'w' en open() (crea o sobrescribe).

Método .write(): escribir cadenas en el archivo.

Control de flujo: condicional para decidir si guardar o no.

Ejercicio 2 – Gestión de flujos
Flujos estándar: sys.stdout (salida normal), sys.stderr (salida de error).

Redirección de errores: imprimir mensajes de error en stderr usando print(..., file=sys.stderr).

Lectura desde teclado sin input(): usar sys.stdin.readline() y eliminar el salto de línea final con .rstrip('\n').

Persistencia de la lógica anterior: mantener adición de # y escritura opcional.

Manejo de excepciones al escribir: capturar errores de permisos o rutas inválidas y reportarlos por stderr.

Ejercicio 3 – Seguridad de la bóveda
Context managers: uso de la sentencia with para asegurar cierre automático de archivos.

Diseño de función reutilizable: secure_archive(filename, action='read', content=None).

Parámetros opcionales y anotaciones de tipo.

Lógica de acción: distinguir entre lectura y escritura.

Manejo de errores dentro del context manager.

Tupla como valor de retorno: (bool, str) indicando éxito y mensaje o contenido.

Escritura segura: abrir en modo 'w' dentro de with, escribir contenido, capturar excepciones.
