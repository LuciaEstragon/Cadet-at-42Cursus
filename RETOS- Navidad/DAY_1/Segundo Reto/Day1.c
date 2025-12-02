

#include "handle_file_content.h"
#include "handle_input_content.h"

int main(void)
{
	char *file_name;
	char dictionary[16500];

	file_name = "./numbers_VALORES";
	if (handle_file_content(file_name, dictionary) == -1)
		write(2, "Dict Error\n", 12);
	else
		write(1, "fichero abierto\n", 17);
	write(1, "HOLA MUNDO\n", 17);
	find_numb(dictionary);
	printf("ADIOS");
	printf("\n RESULTADO: FIN OK\n");
	return (0);
}
