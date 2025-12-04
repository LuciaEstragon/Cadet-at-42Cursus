

#include "handle_file_content.h"
#include "handle_input_content.h"

int main(void)
{
	char *file_name;
	char myfilecontent[16500];

	file_name = "./prb1.txt"; //numbersPRUEBA.txt"; numCLAVEprueba2; numCLAVE
	if (handle_file_content(file_name, myfilecontent) == -1)
		write(2, "Dict Error\n", 12);
	else
		write(1, "fichero abierto\n", 17);
	write(1, "HOLA MUNDO\n", 12);
	find_numb(myfilecontent);
	printf("ADIOS");
	return (0);
}
