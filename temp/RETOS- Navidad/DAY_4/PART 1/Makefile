# Nombre del ejecutable
EXEC = rush-01

# Compilador y sus flags
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

# Archivos fuente
SRCS = Day4.c handle_file_content.c handle_input_content.c
OBJS = $(SRCS:.c=.o)

# Archivos de entrada
FILES = numbers.dict numbers

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXEC)

# Regla para compilar los archivos .c en .o
%.o: %.c unistd.h stdio.h stdlib.h handle_file_content.h
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
