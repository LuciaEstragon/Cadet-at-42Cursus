# Nombre del ejecutable
NAME = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios
SRC_DIR = .  # ← Cambiado a directorio actual
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft

# Archivos fuente
SRC = ft_printf.c  # En directorio actual
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a

# Colores
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

# Regla principal
all: $(NAME)

# Crear librería combinada
$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)  # Empezar con libft
	@ar rcs $(NAME) $(OBJS)  # Añadir objetos de printf
	@echo "$(GREEN)✓ $(NAME) creada$(NC)"

# Compilar objetos de printf
$(OBJ_DIR)/%.o: %.c  # ← Sin $(SRC_DIR) si está en raíz
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Compilar libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Limpiar
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)✗ Objetos eliminados$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)✗ Todo eliminado$(NC)"

re: fclean all

nor:
	norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC_DIR)
	@make -C $(LIBFT_DIR) norm

.PHONY: all clean fclean re nor