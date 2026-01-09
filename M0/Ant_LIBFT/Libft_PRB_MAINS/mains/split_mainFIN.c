
/////// MAIN ///////
#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz_char(char **matriz) {
	if (!matriz)
		return;
	
	for (int i = 0; matriz[i] != NULL; i++) {
		printf("Palabra %d: '%s'\n", i, matriz[i]);
	}
}

// Función para liberar la matriz correctamente
void liberar_matriz(char **matriz) {
	if (!matriz)
		return;
	
	for (int i = 0; matriz[i] != NULL; i++) {
		free(matriz[i]);
	}
	free(matriz);
}

int main() {
	char *s = "....hola..que..tal.";
	char c = '.';
	char **mi_matriz;

	mi_matriz = ft_split(s, c);
	
	printf("Cadena original: '%s'\n", s);
	printf("Delimitador: '%c'\n", c);
	printf("Resultado:\n");
	imprimir_matriz_char(mi_matriz);

	// Liberar la memoria correctamente
	liberar_matriz(mi_matriz);

	return 0;
}

