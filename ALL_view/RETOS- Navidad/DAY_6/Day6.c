
#include "get_next_line.h"

int main(void)
{
	char	*file_name;
	char	**myfilecontent;
	int		count_lines;

	file_name = "./prb1.txt";
	write(1, "HOLA MUNDO\n", 12);
	count_lines = 0;
	while (get_next_line(file_name) != '\0')
	{
		myfilecontent [count_lines] = malloc
		count_lines++;
	}
	printf("ADIOS");
	return (0);
}
