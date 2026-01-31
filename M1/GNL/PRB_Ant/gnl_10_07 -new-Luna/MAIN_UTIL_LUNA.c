///PARA ESCRIBIR DESDE fd = 0  
//  - fd=0 es el terminal, estoy escribiendo desde teclado
//  - scanf() 

int main(void){
	while (1) {
		char *str = get_next_line(0);
		if (str == NULL)
			break;
		printf("Acabas de escribir: %s\n", str);
	}
	return 0;
}

///PARA  ESCRIBIR UNA LINEA DEL fd
//  - programa facilito

int main(void){
        int fd = open("file", O_RDONLY);
        while (1) {
                char *str = get_next_line(fd);
                if (str == NULL)
                        break;
                printf("Acabas de escribir: %s\n", str);
        }
	close(fd);
        return 0;
}



/* NOTAS SOBRE LOS LEAKS */
1. En el Make file tienes que compilar con el flag -g3
    Esto guarda informacion en el binarioo de salida
   
2. valgrind ./gnl
    Esto me dice si hay errores de leaks
 
3. valgrind --leak-check=full ./gnl 
    Esto me dice cuantos errores

4. valgrind --leak-check=full --show-leak-kinds=all ./gnl
    Esto me dice donde estan esos errores -- lineas




-> ERRORES DETECTDOS
1. Si fd =0 - tiene que escribir info por pantalla
2. si fd = NULL - si fd no existe o no tiene nada - return (0); - esto desde el principio, sin hacer llamada al read_line() - quue tiene un malloc
3. si fd = a (sin \nl) 

if (file < 0 || BUFFER_SIZE <= 0 || read(file, 0, 0) < 0)



BREAK POINTS
lldb (aqui pones EXEC)
b main
r (aqui pones arg)
gui

para pasar n
para entrar en funcion s
