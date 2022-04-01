PUSH_SWAP_OBJ = functions.c \
	function2.c \
	check_function.c \
	ope_function.c \
	ope2_function.c \
	search_functions.c \
	list.c \
	modifer_stacka.c \
	remove_clean.c \
	control_stack.c \
	control_stack2.c \
	push_swap.c

CHECKER_SRC = function_checker.c \
			functions.c \
			function2.c \
			check_function.c \
			ope_function.c \
			ope2_function.c \
			search_functions.c \
			list.c \
			modifer_stacka.c \
			remove_clean.c \
			control_stack.c \
			control_stack2.c \
			checker.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(PUSH_SWAP_OBJ:%.c=%.o)
CHECKER_OBJ = $(CHECKER_SRC:%.c=%.o)
PUSH_SWAP = push_swap
CHECKER = checker

all:$(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PUSH_SWAP)

$(CHECKER):$(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(CHECKER)

%.o:%.c
	$(CC) $(CFLAGS) -c $^
clean:
	rm -f $(OBJECTS) $(CHECKER_OBJ)
fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER)
re: fclean all
.PHONY: all clean fclean re

bonus: all