NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Werror -Wextra

RM   = rm -f

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)
LIBS = unistd.h stddef.h stdlib.h libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(LIBS)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(BONUS_OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

nor:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re nor
