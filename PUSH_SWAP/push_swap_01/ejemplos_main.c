#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        // argv[i] nos da el puntero a la palabra completa
        printf("Argumento [%d]: %s\n", i, argv[i]);
        
        // argv[i][0] nos da la primera letra de esa palabra
        printf("Primera letra: %c\n", argv[i][0]);
    }
    return 0;
}


///////////////////////////////////////////////////////////

#include <stdio.h>

int main(int argc, char **argv) {
    while (*argv != NULL) { // Recuerda: el último elemento de argv siempre es NULL
        // *argv es el contenido (la palabra actual)
        printf("Palabra actual: %s\n", *argv);
        
        // **argv es el contenido del contenido (la primera letra)
        printf("Letra inicial: %c\n", **argv);
        
        argv++; // Movemos el puntero a la siguiente dirección de la lista
    }
    return 0;
}