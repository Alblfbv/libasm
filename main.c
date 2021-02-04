#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/errno.h>

#include "libasm.h"

#define TEST_STRINGS_NB 10
#define MAX_STRLEN 40
#define ERROR "\033[31m"
#define SUCCESS "\033[32m"
#define RESET_COL "\033[39m"

const char str_tab[TEST_STRINGS_NB][MAX_STRLEN] = {
	"",
	" ",
	"Hello",
	"Hello World!",
	"#é&0@",
	"\n",
	"\0",
	"1 a 2 b 3 C 4 D",
	"50"};

void test_ft_strlen(void)
{
	int i;
	size_t real_len;
	size_t my_len;

	printf("----- ft_strlen tests -----\n\n");
	i = 0;
	while (i < TEST_STRINGS_NB)
	{
		real_len = strlen((char *)str_tab[i]);
		my_len = ft_strlen((char *)str_tab[i]);
		printf("test n°%d: ", i);
		if (my_len != real_len)
		{
			printf(ERROR "ERROR: different lengths\n" RESET_COL);
			printf("real strlen	=	%zu\n", real_len);
			printf("my strlen	=	%zu\n", my_len);
		}
		else
			printf(SUCCESS "SUCCESS\n" RESET_COL);
		i++;
	}
	printf("\n\n");
}

void test_ft_strcpy(void)
{
	char *real_str;
	char *my_str;
	int i;

	printf("----- ft_strcpy tests -----\n\n");
	i = 0;
	real_str = malloc(MAX_STRLEN);
	my_str = malloc(MAX_STRLEN);
	while (i < TEST_STRINGS_NB)
	{
		strcpy(real_str, (char *)str_tab[i]);
		ft_strcpy(my_str, (char *)str_tab[i]);
		printf("test n°%d: ", i);
		if (strcmp(my_str, real_str))
		{
			printf(ERROR "ERROR: different strings\n" RESET_COL);
			printf("real strcpy	=	%s\n", real_str);
			printf("my strcpy	=	%s\n", my_str);
		}
		else
			printf(SUCCESS "SUCCESS\n" RESET_COL);
		i++;
	}
	printf("\n\n");
}

void test_ft_strcmp(void)
{
	int i;
	int j;
	int real_ret;
	int my_ret;

	printf("----- ft_strcmp tests -----\n\n");
	i = 0;
	while (i < TEST_STRINGS_NB)
	{
		j = 0;
		while (j < TEST_STRINGS_NB)
		{
			real_ret = strcmp((char *)str_tab[i], (char *)str_tab[j]);
			my_ret = ft_strcmp((char *)str_tab[i], (char *)str_tab[j]);
			printf("test n°%d%d: ", i, j);
			if (my_ret != real_ret)
			{
				printf(ERROR "ERROR: different return values\n" RESET_COL);
				printf("real strcmp	=	%d\n", real_ret);
				printf("my strcmp	=	%d\n", my_ret);
			}
			else
				printf(SUCCESS "SUCCESS\n" RESET_COL);
			j++;
		}
		i++;
	}
	printf("\n\n");
}

void test_ft_strdup(void)
{
	char *real_str;
	char *my_str;
	int i;

	printf("----- ft_strdup tests -----\n\n");
	i = 0;
	while (i < TEST_STRINGS_NB)
	{
		real_str = strdup((char *)str_tab[i]);
		my_str = ft_strdup((char *)str_tab[i]);
		printf("test n°%d: ", i);
		if (strcmp(my_str, real_str))
		{
			printf(ERROR "ERROR: different strings\n" RESET_COL);
			printf("real strdup	=	%s\n", real_str);
			printf("my strdup	=	%s\n", my_str);
		}
		else
			printf(SUCCESS "SUCCESS\n" RESET_COL);
		i++;
	}
	printf("\n\n");
}

void test_ft_write(void)
{
	ssize_t real_ret;
	ssize_t my_ret;
	char *real_buff;
	char *my_buff;
	const char *real_file;
	const char *my_file;
	int real_fd;
	int my_fd;
	int real_errno;
	int my_errno;
	int i;

	printf("----- ft_write tests -----\n\n");
	i = 0;
	real_file = strdup("real_file");
	my_file = strdup("my_file");
	real_buff = malloc(MAX_STRLEN);
	my_buff = malloc(MAX_STRLEN);
	while (i < TEST_STRINGS_NB)
	{
		real_fd = open(real_file, O_RDWR | O_CREAT);
		my_fd = open(my_file, O_RDWR | O_CREAT);
		real_ret = write(real_fd, str_tab[i], strlen(str_tab[i]));
		my_ret = ft_write(my_fd, str_tab[i], strlen(str_tab[i]));
		bzero(real_buff, MAX_STRLEN);
		bzero(my_buff, MAX_STRLEN);
		read(real_fd, real_buff, MAX_STRLEN);
		read(my_fd, my_buff, MAX_STRLEN);
		close(real_fd);
		close(my_fd);
		printf("test n°%d: ", i);
		if (real_ret != my_ret)
		{
			printf(ERROR "ERROR: different return values\n" RESET_COL);
			printf("real ret	=	%ld\n", real_ret);
			printf("my ret		=	%ld\n", my_ret);
		}
		else
		{
			if (strcmp(real_buff, my_buff))
			{
				printf(ERROR "ERROR: different buffer contents\n" RESET_COL);
				printf("real buffer	=	%s\n", real_buff);
				printf("my buffer	=	%s\n", my_buff);
			}
			else
				printf(SUCCESS "SUCCESS\n" RESET_COL);
		}
		i++;
	}
	my_ret = ft_write(56, "hello", 5);
	my_errno = errno;
	real_ret = write(56, "hello", 5);
	real_errno = errno;
	printf("test n°%d: ", i);
	if (real_ret != my_ret || real_errno != my_errno)
	{
		if (real_ret != my_ret)
		{
			printf(ERROR "ERROR: different return values\n" RESET_COL);
			printf("real ret	=	%ld\n", real_ret);
			printf("my ret		=	%ld\n", my_ret);
		}
		if (real_errno != my_errno)
		{
			printf(ERROR "ERROR: different errno values\n" RESET_COL);
			printf("real errno	=	%d\n", real_errno);
			printf("my errno	=	%d\n", my_errno);
		}
	}
	else
		printf(SUCCESS "SUCCESS\n" RESET_COL);
	remove(real_file);
	remove(my_file);
	printf("\n\n");
}

void test_ft_read(void)
{
	ssize_t real_ret;
	ssize_t my_ret;
	char *real_buff;
	char *my_buff;
	const char *real_file;
	const char *my_file;
	int real_fd;
	int my_fd;
	int real_errno;
	int my_errno;
	int i;

	printf("----- ft_read tests -----\n\n");
	i = 0;
	real_file = strdup("real_file");
	my_file = strdup("my_file");
	real_buff = malloc(MAX_STRLEN);
	my_buff = malloc(MAX_STRLEN);
	while (i < TEST_STRINGS_NB)
	{
		real_fd = open(real_file, O_RDWR | O_CREAT);
		my_fd = open(my_file, O_RDWR | O_CREAT);
		write(real_fd, str_tab[i], strlen(str_tab[i]));
		write(my_fd, str_tab[i], strlen(str_tab[i]));
		bzero(real_buff, MAX_STRLEN);
		bzero(my_buff, MAX_STRLEN);
		real_ret = read(real_fd, real_buff, MAX_STRLEN);
		my_ret = ft_read(my_fd, my_buff, MAX_STRLEN);
		close(real_fd);
		close(my_fd);
		printf("test n°%d: ", i);
		if (real_ret != my_ret)
		{
			printf(ERROR "ERROR: different return values\n" RESET_COL);
			printf("real ret	=	%ld\n", real_ret);
			printf("my ret		=	%ld\n", my_ret);
		}
		else
		{
			if (strcmp(real_buff, my_buff))
			{
				printf(ERROR "ERROR: different buffer contents\n" RESET_COL);
				printf("real buffer	=	%s\n", real_buff);
				printf("my buffer	=	%s\n", my_buff);
			}
			else
				printf(SUCCESS "SUCCESS\n" RESET_COL);
		}
		i++;
	}
	my_ret = ft_read(56, "hello", 5);
	my_errno = errno;
	real_ret = read(56, "hello", 5);
	real_errno = errno;
	printf("test n°%d: ", i);
	if (real_ret != my_ret || real_errno != my_errno)
	{
		if (real_ret != my_ret)
		{
			printf(ERROR "ERROR: different return values\n" RESET_COL);
			printf("real ret	=	%ld\n", real_ret);
			printf("my ret	=	%ld\n", my_ret);
		}
		if (real_errno != my_errno)
		{
			printf(ERROR "ERROR: different errno values\n" RESET_COL);
			printf("real errno	=	%d\n", real_errno);
			printf("my errno	=	%d\n", my_errno);
		}
	}
	else
		printf(SUCCESS "SUCCESS\n" RESET_COL);
	remove(real_file);
	remove(my_file);
	printf("\n\n");
}

int main(void)
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_strdup();
	test_ft_write();
	test_ft_read();
	return (0);
}
