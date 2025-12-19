# Nombre del ejecutable
EXEC = rush-02

# Compilador y sus flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Archivos fuente
SRCS = main.c handle_file_content.c handle_dictionary_content.c handle_dictionary_utils.c
OBJS = $(SRCS:.c=.o)

# Archivos de entrada
FILES = numbers.dict

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXEC)

# Regla para compilar los archivos .c en .o
%.o: %.c unistd.h stdio.h stdlib.h handle_file_content.h handle_dictionary_content.h lib_error_main.h
	$(CC) $(CFLAGS) -c $<

# Regla para limpiar todo, incluyendo el ejecutable
clean:
	rm -f $(OBJS)
	
# Regla para limpiar los archivos objeto y el ejecutable
fclean:clean
	rm -f $(EXEC)

# Regla para leer los archivos y ejecutar el programa
run: $(EXEC)
	./$(EXEC) $(FILES)

.PHONY: all clean run
