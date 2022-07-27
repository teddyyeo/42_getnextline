NAME = get_next_line

SRC=get_next_line.c get_next_line_utils.c test/test.c

FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=1

all: $(NAME)

$(NAME): fclean $(SRC)
	gcc $(FLAG) $(SRC) -o $(NAME)

test: all
	./get_next_line
	diff test/output1.txt test/1-brouette.txt
	diff test/output2.txt test/2-otarie.txt
	diff test/output3.txt test/3-oneline.txt
	diff test/output4.txt test/4-u.txt
	diff test/output5.txt test/5-empty.txt
	diff test/output6.txt test/6-newline.txt
	diff test/output7.txt test/7-onechar.txt
	diff test/output8.txt test/8-twochar.txt
	diff test/output9.txt test/9-linew.txt
	diff test/output10.txt test/10-b.txt
	diff test/output11.txt test/11-bg.txt
	diff test/output12.txt test/12-bigben.txt

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
