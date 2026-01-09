/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 07:56:07 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/06 08:02:39 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void *ft_memset(void *s, int c, size_t n) 
{
    unsigned char *ptr = (unsigned char *)s;
    unsigned char value = (unsigned char)c;
    size_t i;
    
    i = 0;
    while ( i < n) 
    {
        ptr[i] = value;
        i++;
    }
    return (ptr);
}

// Función para imprimir memoria en hexadecimal
void print_memory(const void *addr, size_t size) {
    const unsigned char *p = (const unsigned char *)addr;
    printf("Memoria [");
    for (size_t i = 0; i < size; i++) {
        printf("%02X", p[i]);
        if (i < size - 1) printf(" ");
    }
    printf("]\n");
}

// Función para imprimir cadena mostrando caracteres no imprimibles
void print_string(const char *str, size_t size) {
    printf("Como cadena: \"");
    for (size_t i = 0; i < size; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            printf("%c", str[i]);
        } else {
            printf("\\x%02X", (unsigned char)str[i]);
        }
    }
    printf("\"\n");
}

int main(void) {
    printf("=== PRUEBAS DE MEMSET ===\n\n");
    
    // Test 1: Rellenar con caracteres normales
    printf("1. Rellenar con caracteres ASCII:\n");
    char buffer1[20] = "Hola Mundo123456789";
    char buffer1_std[20] = "Hola Mundo123456789";
    
    printf("   Antes:  ");
    print_string(buffer1, 15);
    
    ft_memset(buffer1, 'X', 10);
    memset(buffer1_std, 'X', 10);
    
    printf("   Custom: ");
    print_string(buffer1, 15);
    printf("   Estándar: ");
    print_string(buffer1_std, 15);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer1, buffer1_std, 15) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 2: Rellenar con cero
    printf("2. Rellenar con ceros (\\0):\n");
    char buffer2[10] = "ABCDEFGHI";
    char buffer2_std[10] = "ABCDEFGHI";
    
    printf("   Antes:  ");
    print_memory(buffer2, 10);
    
    ft_memset(buffer2, 0, 5);
    memset(buffer2_std, 0, 5);
    
    printf("   Custom: ");
    print_memory(buffer2, 10);
    printf("   Estándar: ");
    print_memory(buffer2_std, 10);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer2, buffer2_std, 10) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 3: Rellenar con valor numérico
    printf("3. Rellenar con valor 65 ('A'):\n");
    char buffer3[8];
    char buffer3_std[8];
    
    ft_memset(buffer3, 65, 8);
    memset(buffer3_std, 65, 8);
    
    printf("   Custom: ");
    print_memory(buffer3, 8);
    print_string(buffer3, 8);
    printf("   Estándar: ");
    print_memory(buffer3_std, 8);
    print_string(buffer3_std, 8);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer3, buffer3_std, 8) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 4: Rellenar con valor hexadecimal
    printf("4. Rellenar con valor 0xFF:\n");
    unsigned char buffer4[6];
    unsigned char buffer4_std[6];
    
    ft_memset(buffer4, 0xFF, 6);
    memset(buffer4_std, 0xFF, 6);
    
    printf("   Custom: ");
    print_memory(buffer4, 6);
    printf("   Estándar: ");
    print_memory(buffer4_std, 6);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer4, buffer4_std, 6) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 5: Tamaño cero
    printf("5. Tamaño cero (no debería modificar):\n");
    char buffer5[10] = "Original";
    char buffer5_std[10] = "Original";
    
    printf("   Antes:  %s\n", buffer5);
    ft_memset(buffer5, 'Z', 0);
    memset(buffer5_std, 'Z', 0);
    printf("   Después: %s\n", buffer5);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer5, buffer5_std, 10) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 6: Entero con signo (valor negativo)
    printf("6. Rellenar con valor negativo (-1):\n");
    char buffer6[5];
    char buffer6_std[5];
    
    ft_memset(buffer6, -1, 5);
    memset(buffer6_std, -1, 5);
    
    printf("   Custom: ");
    print_memory(buffer6, 5);
    printf("   Estándar: ");
    print_memory(buffer6_std, 5);
    printf("   ¿Coinciden? %s\n\n", 
           memcmp(buffer6, buffer6_std, 5) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 7: Array de enteros
    printf("7. Rellenar array de enteros:\n");
    int int_buffer[4];
    int int_buffer_std[4];
    
    // Inicializar con valores conocidos
    for (int i = 0; i < 4; i++) {
        int_buffer[i] = i + 100;
        int_buffer_std[i] = i + 100;
    }
    
    printf("   Antes:  ");
    for (int i = 0; i < 4; i++) printf("%d ", int_buffer[i]);
    printf("\n");
    
    ft_memset(int_buffer, 0, sizeof(int_buffer));
    memset(int_buffer_std, 0, sizeof(int_buffer_std));
    
    printf("   Custom: ");
    for (int i = 0; i < 4; i++) printf("%d ", int_buffer[i]);
    printf("\n   Estándar: ");
    for (int i = 0; i < 4; i++) printf("%d ", int_buffer_std[i]);
    printf("\n   ¿Coinciden? %s\n\n", 
           memcmp(int_buffer, int_buffer_std, sizeof(int_buffer)) == 0 ? "✓ SÍ" : "✗ NO");
    
    // Test 8: Verificar valor de retorno
    printf("8. Verificar valor de retorno:\n");
    char buffer8[10];
    char *ret_custom = ft_memset(buffer8, 'R', 5);
    char *ret_std = memset(buffer8, 'R', 5);
    
    printf("   Custom retorna: %p\n", (void*)ret_custom);
    printf("   Estándar retorna: %p\n", (void*)ret_std);
    printf("   ¿Misma dirección? %s\n", 
           ret_custom == buffer8 ? "✓ SÍ" : "✗ NO");
    
    return 0;
}
