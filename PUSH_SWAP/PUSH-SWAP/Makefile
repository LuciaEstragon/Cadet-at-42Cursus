#Compiler and linker
CC 		:=	cc

#Remove tool
RM 		:=	rm -f

#Flags
LIBFT	:=	libft/libft.a
CFLAGS 	:=	-Wall -Wextra -Werror -g3 -Isrc
LIB 	:=	$(LIBFT)

#Project stuff 
NAME 	:=	push_swap
SRC 	:=	src/push_swap.c\
			src/check_error/check_error.c\
			src/util_stack/operation_stack.c\
			src/util_stack/indexize.c\
			src/sorting_algorithms/sort.c\
			src/sorting_algorithms/small_sort.c\
			src/sorting_algorithms/ksort.c\
			src/movements/allowed_operations.c\
			src/movements/push.c\
			src/movements/reverse_rotate.c\
			src/movements/rotate.c\
			src/movements/swap.c\
			src/util_oplist/operation_oplist.c\
			src/util_oplist/print.c
OBJ		:=	$(SRC:.c=.o)

#-----------------------------------------------------------------------------#
#                                    Rules                                    #
#-----------------------------------------------------------------------------#

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ)

fclean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean $(NAME)

nor:
	cd src
	norminette -R CheckForbiddenSourceHeader 

.PHONY: all clean fclean re nor
