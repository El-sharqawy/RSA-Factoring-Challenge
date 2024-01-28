#include "factoring.h"

/**
 * main - check the code
 * @argc: number of arguments passed
 * @argv: arguments passed
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *buf = NULL;
	size_t count;
	ssize_t line;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: rsa <filename>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: failed to open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buf, &count, file)) != -1)
	{
		factoring(buf);
	}
	return (0);
}
