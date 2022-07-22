NAME = get_next_line

SRC=get_next_line.c get_next_line_utils.c test.c

FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=1

all: $(NAME)

$(NAME): fclean $(SRC)
	gcc $(FLAG) $(SRC) -o $(NAME) && ./get_next_line | cat -e

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
