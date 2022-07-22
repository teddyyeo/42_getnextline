#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char *line;

	for (int i = 1; i <= 10;i++)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line %d: %s", i, line);
		else
			printf("line %d: %s\n", i, line);
		printf("\n\n");
	}
	close(fd);
	return (0);
}
