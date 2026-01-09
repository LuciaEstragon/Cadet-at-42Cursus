//Funciones memcpy y memmmove

//  --
// COMO SABEMOS SI HAY SoLAPAMIENTOS DE MEMORIA
//  --

#include <stdio.h>
#include <string.h>

int hay_solapamiento(const void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    char *s = (char *)src;
    
    // Verificar si las áreas se solapan
    if (s < d && s + n > d) {
        return 1; // Solapamiento: src empieza antes y se extiende hasta dest
    }
    if (d < s && d + n > s) {
        return 1; // Solapamiento: dest empieza antes y se extiende hasta src
    }
    return 0; // No hay solapamiento
}

int main() {
    char buffer[20] = "abcdefghij";
    
    // Caso 1: Solapamiento (peligroso)
    printf("Caso 1 - Solapamiento: %d\n", 
           hay_solapamiento(buffer + 2, buffer, 5));
    
    // Caso 2: Sin solapamiento (seguro)
    printf("Caso 2 - Sin solapamiento: %d\n", 
           hay_solapamiento(buffer + 10, buffer, 5));
    
    return 0;
}

//  --
// COMO COMPARAR DIRECCIONES DE MEMORIA Y CONTENIDO DE ESAS DIRECCIONES DE MEMORIA
//  --
/*
ptr1 == ptr2: ¿Apuntan al MISMO lugar en memoria?
*ptr1 == *ptr2: ¿Los VALORES en esas direcciones son iguales?
memcmp(ptr1, ptr2, n): ¿Los primeros n bytes son iguales?
*/

#include <stdio.h>

int main() {
    int valor1 = 100;
    int valor2 = 100;
    
    int *ptrA = &valor1;
    int *ptrB = &valor1;  // Misma dirección que ptrA
    int *ptrC = &valor2;  // Diferente dirección, mismo valor
    
    printf("=== RESUMEN ===\n");
    printf("Comparar DIRECCIONES (¿mismo lugar en memoria?):\n");
    printf("ptrA == ptrB: %d (SÍ - misma dirección)\n", ptrA == ptrB);
    printf("ptrA == ptrC: %d (NO - diferente dirección)\n", ptrA == ptrC);
    
    printf("\nComparar CONTENIDO (¿mismo valor?):\n");
    printf("*ptrA == *ptrB: %d (SÍ - mismo valor)\n", *ptrA == *ptrB);
    printf("*ptrA == *ptrC: %d (SÍ - mismo valor)\n", *ptrA == *ptrC);
    
    printf("\nRegla práctica:\n");
    printf("- Usar 'ptr1 == ptr2' para saber si apuntan al MISMO objeto\n");
    printf("- Usar '*ptr1 == *ptr2' para comparar los VALORES apuntados\n");
    
    return 0;
}


void comparar_arrays() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int *ptr1 = arr1;
    int *ptr2 = arr2;

    printf("=== COMPARAR ARRAYS ===\n");
    printf("arr1: %p, arr2: %p\n", arr1, arr2);

    // COMPARACIÓN INCORRECTA de arrays
    printf("arr1 == arr2: %d (¡CUIDADO! compara direcciones, no contenido)\n",
           arr1 == arr2); // 0

    // COMPARACIÓN CORRECTA de contenido
    int contenido_igual = 1;
    for(int i = 0; i < 3; i++) {
        if(arr1[i] != arr2[i]) {
            contenido_igual = 0;
            break;
        }
    }
    printf("¿Contenido igual?: %d\n", contenido_igual); // 1
}
