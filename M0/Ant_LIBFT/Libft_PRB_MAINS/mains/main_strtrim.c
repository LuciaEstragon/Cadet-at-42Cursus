
#include <stdio.h>

// Aquí iría tu función ft_strtrim corregida

int main(void)
{
	char *result;
	
	printf("=== PRUEBAS ft_strtrim ===\n\n");
	
	// Prueba 1: Caso normal
	printf("1. Caso normal:\n");
	result = ft_strtrim("  hello world  ", " ");
	printf("'  hello world  ' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 2: Múltiples caracteres en set
	printf("2. Múltiples caracteres en set:\n");
	result = ft_strtrim("abcHOLAabc", "abc");
	printf("'abcHOLAabc' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 1: Caso Ultra
	printf("1. Caso ultra - se contiene a si mismo:\n");
	result = ft_strtrim("accbabbaccaabc", "abc");
	printf("'  accbabbaccaabc  ' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 3: String vacío después del trim
	printf("3. String vacío después del trim:\n");
	result = ft_strtrim("aaa", "a");
	printf("'aaa' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 4: String original vacío
	printf("4. String original vacío:\n");
	result = ft_strtrim("", "abc");
	printf("'' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 5: Set vacío
	printf("5. Set vacío:\n");
	result = ft_strtrim("hello world", "");
	printf("'hello world' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 6: Sin caracteres para recortar
	printf("6. Sin caracteres para recortar:\n");
	result = ft_strtrim("hello", "xyz");
	printf("'hello' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 7: Solo recorte al inicio
	printf("7. Solo recorte al inicio:\n");
	result = ft_strtrim("xxxhello", "x");
	printf("'xxxhello' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 8: Solo recorte al final
	printf("8. Solo recorte al final:\n");
	result = ft_strtrim("helloyyy", "y");
	printf("'helloyyy' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 9: Caracteres especiales
	printf("9. Caracteres especiales:\n");
	result = ft_strtrim("\t\nhello\t\n", "\t\n");
	printf("'\\t\\nhello\\t\\n' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 10: NULL parameters
	printf("10. NULL parameters:\n");
	result = ft_strtrim(NULL, "abc");
	printf("NULL -> %s\n", result);
	result = ft_strtrim("hello", NULL);
	printf("'hello', NULL -> %s\n\n", result);
	
	// Prueba 11: String de un solo carácter
	printf("11. String de un solo carácter:\n");
	result = ft_strtrim("a", "a");
	printf("'a' -> '%s'\n\n", result);
	free(result);
	
	// Prueba 12: Caracteres mezclados
	printf("12. Caracteres mezclados:\n");
	result = ft_strtrim("xyhelloxy", "xyz");
	printf("'xyhelloxy' -> '%s'\n\n", result);
	free(result);

	return 0;
}

/*evalua todo el *set pasando por cada i, y evaluandolo sobre cada j de la palabra*/
