TARGET	= libft.a
SRCS   	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	      ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c
CFLAGS	= -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY : clean fclean re test

test: $(TARGET)
	gcc $(CFLAGS) main.c -L. -lft -o test_program
	./test_program

test_clean:
	rm -f test_program
