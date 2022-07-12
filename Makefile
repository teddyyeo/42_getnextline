NAME = get_next_line

SRC=get_next_line.c

FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): fclean $(SRC)
	gcc $(FLAG) $(SRC) -o $(NAME) && ./get_next_line

clean:
	rm -f $(OBJ) $(BOBJ) tester

fclean: clean
	rm -f $(NAME) tester

re: fclean all

.PHONY: all bonus clean fclean re test
