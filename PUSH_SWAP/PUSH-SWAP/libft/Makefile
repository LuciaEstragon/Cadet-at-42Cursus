# Name of the library file
NAME = libft.a
# Compiler to use
CC = cc
# Flags to use when compiling
CFLAGS = -Wall -Wextra -Werror -g3 -I.
# Archiver to use
AR = ar
# Flags to use when archiving
ARFLAGS = -rc
# Command to use to remove files
RM = rm -f
# List of all the .c files for the library
SRC = char/ft_isalpha.c\
char/ft_isdigit.c\
char/ft_isalnum.c\
char/ft_isascii.c\
char/ft_isprint.c\
char/ft_toupper.c\
char/ft_tolower.c\
memory/ft_memset.c\
memory/ft_memmove.c\
memory/ft_memcpy.c\
memory/ft_bzero.c\
memory/ft_calloc.c\
memory/ft_memchr.c\
memory/ft_memcmp.c\
string/ft_strcpy.c\
string/ft_strncpy.c\
string/ft_strlcpy.c\
string/ft_strcat.c\
string/ft_strncat.c\
string/ft_strlcat.c\
string/ft_strlen.c\
string/ft_strchr.c\
string/ft_strrchr.c\
string/ft_strstr.c\
string/ft_strnstr.c\
string/ft_strncmp.c\
string/ft_strcapitalize.c\
string/ft_strdup.c\
string/ft_substr.c\
string/ft_strjoin.c\
string/ft_strtrim.c\
string/ft_split.c\
string/ft_free_strarray.c\
string/ft_strappend.c\
string/ft_strmapi.c\
string/ft_striteri.c\
conversion/ft_atoi.c\
conversion/ft_itob.c\
conversion/ft_itoa.c\
conversion/ft_itoa_base.c\
conversion/ft_itoa_base_ptr.c\
io/output/ft_putchar_fd.c\
io/output/ft_putstr_fd.c\
io/output/ft_putendl_fd.c\
io/output/ft_putnbr_fd.c\
io/output/ft_putchar.c\
io/output/ft_putstr.c\
io/output/ft_putendl.c\
io/output/ft_putnbr.c\
io/input/get_next_line.c\
lists/ft_lstnew.c\
lists/ft_lstadd_front.c\
lists/ft_lstsize.c\
lists/ft_lstlast.c\
lists/ft_lstadd_back.c\
lists/ft_lstdelone.c\
lists/ft_lstclear.c\
lists/ft_lstiter.c\
lists/ft_lstmap.c\
io/output/ft_printf.c\
operations/math.c\


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

nor:
	norminette -R CheckForbiddenSourceHeader #$(SRC_DIR) $(INC_DIR)

.PHONY: all re clean fclean nor
