NAME = print_tree.a
SRC = print_tree.c
INCLUDE = print_tree.h
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	ar -crs $(NAME) $<
%.o: %.c $(INCLUDE)
	cc $(FLAGS) -c $<

clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
