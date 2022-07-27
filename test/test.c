#include "../get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd1 = open("test/1-brouette.txt", O_RDONLY);
	int fd2 = open("test/2-otarie.txt", O_RDONLY);
	int fd3 = open("test/3-oneline.txt", O_RDONLY);
	int fd4 = open("test/4-u.txt", O_RDONLY);
	int fd5 = open("test/5-empty.txt", O_RDONLY);
	int fd6 = open("test/6-newline.txt", O_RDONLY);
	int fd7 = open("test/7-onechar.txt", O_RDONLY);
	int fd8 = open("test/8-twochar.txt", O_RDONLY);
	int fd9 = open("test/9-linew.txt", O_RDONLY);
	int fd10 = open("test/10-b.txt", O_RDONLY);
	int fd11 = open("test/11-bg.txt", O_RDONLY);
	int fd12 = open("test/12-bigben.txt", O_RDONLY);
	FILE *fp1 = fopen("test/output1.txt", "w");
	FILE *fp2 = fopen("test/output2.txt", "w");
	FILE *fp3 = fopen("test/output3.txt", "w");
	FILE *fp4 = fopen("test/output4.txt", "w");
	FILE *fp5 = fopen("test/output5.txt", "w");
	FILE *fp6 = fopen("test/output6.txt", "w");
	FILE *fp7 = fopen("test/output7.txt", "w");
	FILE *fp8 = fopen("test/output8.txt", "w");
	FILE *fp9 = fopen("test/output9.txt", "w");
	FILE *fp10 = fopen("test/output10.txt", "w");
	FILE *fp11 = fopen("test/output11.txt", "w");
	FILE *fp12 = fopen("test/output12.txt", "w");
	char *line;

	do
	{
		line = get_next_line(fd1);
		if (line != NULL)
			fprintf(fp1,"%s",line);
	}while (line != NULL);
	close(fd1);
	do
	{
		line = get_next_line(fd2);
		if (line != NULL)
			fprintf(fp2,"%s",line);
	}while (line != NULL);
	close(fd2);
	do
	{
		line = get_next_line(fd3);
		if (line != NULL)
			fprintf(fp3,"%s",line);
	}while (line != NULL);
	close(fd3);
	do
	{
		line = get_next_line(fd4);
		if (line != NULL)
			fprintf(fp4,"%s",line);
	}while (line != NULL);
	close(fd4);
	do
	{
		line = get_next_line(fd5);
		if (line != NULL)
			fprintf(fp5,"%s",line);
	}while (line != NULL);
	close(fd5);
	do
	{
		line = get_next_line(fd6);
		if (line != NULL)
			fprintf(fp6,"%s",line);
	}while (line != NULL);
	close(fd6);
	do
	{
		line = get_next_line(fd7);
		if (line != NULL)
			fprintf(fp7,"%s",line);
	}while (line != NULL);
	close(fd7);
	do
	{
		line = get_next_line(fd8);
		if (line != NULL)
			fprintf(fp8,"%s",line);
	}while (line != NULL);
	close(fd8);
	do
	{
		line = get_next_line(fd9);
		if (line != NULL)
			fprintf(fp9,"%s",line);
	}while (line != NULL);
	close(fd9);
	do
	{
		line = get_next_line(fd10);
		if (line != NULL)
			fprintf(fp10,"%s",line);
	}while (line != NULL);
	close(fd10);
	do
	{
		line = get_next_line(fd11);
		if (line != NULL)
			fprintf(fp11,"%s",line);
	}while (line != NULL);
	close(fd11);
	do
	{
		line = get_next_line(fd12);
		if (line != NULL)
			fprintf(fp12,"%s",line);
	}while (line != NULL);
	close(fd12);

	return (0);
}
