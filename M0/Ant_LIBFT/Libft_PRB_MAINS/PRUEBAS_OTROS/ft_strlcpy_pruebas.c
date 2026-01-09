/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:38:27 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/26 18:08:48 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Función strlcpy personalizada para comparar
size_t ft_strlcpy(char *dst, const char *src, size_t size) {
    size_t i = 0;
    
    if (size > 0) {
        while (i < size - 1 && src[i] != '\0') {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    
    // Calcular longitud de src
    while (src[i] != '\0') {
        i++;
    }
    return i;
}

// Función para imprimir cadena con caracteres especiales visibles
void print_string_visible(const char *str) {
    printf("\"");
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            printf("%c", str[i]);
        } else {
            printf("\\x%02X", (unsigned char)str[i]);
        }
    }
    printf("\"");
}

// Función para imprimir buffer completo con contenido
void print_buffer(const char *buffer, size_t size, const char *label) {
    printf("%s: [", label);
    for (size_t i = 0; i < size; i++) {
        if (buffer[i] == '\0') {
            printf("\\0");
        } else if (buffer[i] >= 32 && buffer[i] <= 126) {
            printf("%c", buffer[i]);
        } else {
            printf("\\x%02X", (unsigned char)buffer[i]);
        }
        if (i < size - 1) printf(" ");
    }
    printf("]\n");
}

int main(void) {
    printf("=== PRUEBAS DE STRCPY ===\n\n");
    
    // Buffer para pruebas
    char dst_custom[20];
    char dst_std[20];
    size_t ret_custom, ret_std;
    
    // Test 1: Copia normal con espacio suficiente
    printf("1. Copia normal (espacio suficiente):\n");
    const char *src1 = "Hola Mundo";
    
    // Inicializar buffers con valores conocidos
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src1, sizeof(dst_custom));
    ret_std = strlcpy(dst_std, src1, sizeof(dst_std));
    
    printf("   Fuente: "); print_string_visible(src1); printf("\n");
    printf("   Custom: ret=%zu, dst=", ret_custom); print_string_visible(dst_custom); printf("\n");
    printf("   Estándar: ret=%zu, dst=", ret_std); print_string_visible(dst_std); printf("\n");
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && strcmp(dst_custom, dst_std) == 0) ? "✓ SÍ" : "✗ NO");
    
    // Test 2: Copia con tamaño justo
    printf("2. Copia con tamaño justo:\n");
    const char *src2 = "Exacto";
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src2, 7); // "Exacto" + null = 7
    ret_std = strlcpy(dst_std, src2, 7);
    
    printf("   Fuente: "); print_string_visible(src2); printf("\n");
    printf("   Tamaño: 7\n");
    print_buffer(dst_custom, 10, "   Custom");
    print_buffer(dst_std, 10, "   Estándar");
    printf("   Retorno custom: %zu, estándar: %zu\n", ret_custom, ret_std);
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && strcmp(dst_custom, dst_std) == 0) ? "✓ SÍ" : "✗ NO");
    
    // Test 3: Copia con truncamiento
    printf("3. Copia con truncamiento:\n");
    const char *src3 = "Cadena muy larga para el buffer";
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src3, 10);
    ret_std = strlcpy(dst_std, src3, 10);
    
    printf("   Fuente: "); print_string_visible(src3); printf("\n");
    printf("   Tamaño: 10\n");
    printf("   Custom: ret=%zu, dst=", ret_custom); print_string_visible(dst_custom); printf("\n");
    printf("   Estándar: ret=%zu, dst=", ret_std); print_string_visible(dst_std); printf("\n");
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && strcmp(dst_custom, dst_std) == 0) ? "✓ SÍ" : "✗ NO");
    
    // Test 4: Tamaño 1 (solo null terminator)
    printf("4. Tamaño 1 (solo null terminator):\n");
    const char *src4 = "No debería copiar nada";
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src4, 1);
    ret_std = strlcpy(dst_std, src4, 1);
    
    printf("   Fuente: "); print_string_visible(src4); printf("\n");
    printf("   Tamaño: 1\n");
    print_buffer(dst_custom, 5, "   Custom");
    print_buffer(dst_std, 5, "   Estándar");
    printf("   Retorno custom: %zu, estándar: %zu\n", ret_custom, ret_std);
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && dst_custom[0] == '\0') ? "✓ SÍ" : "✗ NO");
    
    // Test 5: Tamaño 0
    printf("5. Tamaño 0:\n");
    const char *src5 = "Cadena cualquiera";
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src5, 0);
    ret_std = strlcpy(dst_std, src5, 0);
    
    printf("   Fuente: "); print_string_visible(src5); printf("\n");
    printf("   Tamaño: 0\n");
    printf("   Buffer no debería modificarse:\n");
    print_buffer(dst_custom, 5, "   Custom");
    print_buffer(dst_std, 5, "   Estándar");
    printf("   Retorno custom: %zu, estándar: %zu\n", ret_custom, ret_std);
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std) ? "✓ SÍ" : "✗ NO");
    
    // Test 6: Cadena vacía
    printf("6. Cadena vacía:\n");
    const char *src6 = "";
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src6, sizeof(dst_custom));
    ret_std = strlcpy(dst_std, src6, sizeof(dst_std));
    
    printf("   Fuente: \"\"\n");
    printf("   Custom: ret=%zu, dst=", ret_custom); print_string_visible(dst_custom); printf("\n");
    printf("   Estándar: ret=%zu, dst=", ret_std); print_string_visible(dst_std); printf("\n");
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && strcmp(dst_custom, dst_std) == 0) ? "✓ SÍ" : "✗ NO");
    
    // Test 7: Cadena fuente NULL
    printf("7. Cadena fuente NULL:\n");
    char buffer[10];
    
    printf("   Probando con src=NULL...\n");
    
    // Esto causaría segfault, así que lo comentamos
    // ret_custom = ft_strlcpy(buffer, NULL, 10);
    // ret_std = strlcpy(buffer, NULL, 10);
    
    printf("   ❌ No probado - causaría segfault\n\n");
    
    // Test 8: Buffer destino NULL
    printf("8. Buffer destino NULL:\n");
    
    printf("   Probando con dst=NULL...\n");
    // Esto también causaría segfault
    // ret_custom = ft_strlcpy(NULL, "test", 10);
    // ret_std = strlcpy(NULL, "test", 10);
    
    printf("   ❌ No probado - causaría segfault\n\n");
    
    // Test 9: Caracteres especiales
    printf("9. Caracteres especiales y nulos internos:\n");
    const char src9[] = "Hola\0Mundo"; // Cadena con null interno
    
    memset(dst_custom, 'X', sizeof(dst_custom));
    memset(dst_std, 'X', sizeof(dst_std));
    
    ret_custom = ft_strlcpy(dst_custom, src9, sizeof(dst_custom));
    ret_std = strlcpy(dst_std, src9, sizeof(dst_std));
    
    printf("   Fuente con null interno: \"Hola\\0Mundo\"\n");
    printf("   Custom: ret=%zu, dst=", ret_custom); print_string_visible(dst_custom); printf("\n");
    printf("   Estándar: ret=%zu, dst=", ret_std); print_string_visible(dst_std); printf("\n");
    printf("   ¿Coinciden? %s\n\n", 
           (ret_custom == ret_std && strcmp(dst_custom, dst_std) == 0) ? "✓ SÍ" : "✗ NO");
    
    // Resumen final
    printf("=== RESUMEN ===\n");
    printf("strlcpy es más seguro que strcpy porque:\n");
    printf("• Siempre null-termina el resultado\n");
    printf("• Retorna la longitud de src para detectar truncamiento\n");
    printf("• Permite saber si hubo truncamiento comparando retorno con tamaño\n");
    
    return 0;
}
