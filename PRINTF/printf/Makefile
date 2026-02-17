# Nombre del ejecutable
NAME = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_itoa.c

OBJS = $(SRCS:.c=.o)
LIBS = unistd.h stddef.h stdlib.h libft.h

# Colores
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

# Regla principal
all: $(NAME)

# Crear librería combinada
$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) creada$(NC)"

# Compilar objetos de printf
%.o: %.c $(LIBS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpiar
clean:
	@rm -rf $(OBJS)
	@echo "$(RED)✗ Objetos eliminados$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ Todo eliminado$(NC)"

re: fclean all

nor:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re nor