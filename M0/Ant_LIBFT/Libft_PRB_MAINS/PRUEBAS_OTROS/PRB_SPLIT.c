#include <stdio.h>
#include <stdlib.h>
/*
char	**ft_split_1_BIEN(char const *s, char c)
{
	char	**result;
	int		total_word;
	int		ind_words;
	int		len_word;

	total_word = count_words(s, c);
	result = (char **)ft_calloc(total_word + 1, sizeof(char *));
	if (!result)
		return (0);
	ind_words = 0;
	while (ind_words < total_word)
	{
		len_word = ft_strlen(s) - ft_strlen(ft_strchr(s, c)) + 1;
		if (len_word > 0)
		{
			printf("len_word: '%d'\n", len_word);
			printf("word: '%s'\n", ft_strchr(s, c));
			result[ind_words] = (char *)ft_calloc(len_word, sizeof(char *));
			if (!result)
				return (0);
			ft_strlcpy(result[ind_words], s, len_word);
			ind_words++;
		}
		s = s + len_word;
	}
	return (result);
}*/
/*
char	**ft_split_2_BIEN(char const *s, char c)
{
	char	**result;
	int		total_word;
	int		ind_words;
	int		len_word;
	int		ind_s;

	total_word = count_words(s, c);
	result = (char **)ft_calloc(total_word + 1, sizeof(char *));
	if (!result)
		return (NULL);
	ind_words = 0;
	ind_s = 0;
	while (ind_words < total_word)
	{
		if (s[ind_s] == c)
			ind_s++;
		else 
		{
			len_word = 0;
			while (s[ind_s + len_word] != c && s[ind_s + len_word] != '\0')
				len_word++;
			result[ind_words] = (char *)ft_calloc(len_word + 1, sizeof(char));
			if (!result[ind_words])
			{
				while (ind_words-- > 0)
					free(result[ind_words]);
				free(result);
				return (NULL);
			}
			ft_strlcpy(result[ind_words], &s[ind_s], len_word + 1);
			ind_s += len_word;
			ind_words++;
		}
	}
	return (result);
}
*/


/*
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
	char *s = "0 0 0 0 0 0 0 0";//"....hola..q.u.e..t..al\n\t.";
	char c = ' ';
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

*/
