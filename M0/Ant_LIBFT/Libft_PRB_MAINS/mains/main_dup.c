
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *cadena_original = "Hola Mundo";
    char *cadena_copiada;

    // Duplicar la cadena
    cadena_copiada = strdup(cadena_original);

    if (cadena_copiada == NULL) {
        fprintf(stderr, "Error al duplicar la cadena\n");
        return 1;
    }

    printf("Cadena original: %s\n", cadena_original);
    printf("Cadena copiada: %s\n", cadena_copiada);

    // Liberar la memoria asignada por strdup
    free(cadena_copiada);

    return 0;
}

