NAME = libft.a
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
	rm -f $(SRC)
fclean:clean
	rm -f $(NAME)
