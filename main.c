#define _POSIX_C_SOURCE 200809L
#include "main.h"

/**
 * main - The starting point
 * @ac: The number of arguments
 * @av: Array of arguments
 * Return: If successful return 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	globe.line = NULL;
	globe.file = NULL;
	globe.stack = NULL;
	globe.line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	globe.file = fopen(av[1], "r");
	if (globe.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, globe.file)) != -1)
	{
		globe.line_number++;

		globe.line = split(line, " \n\t\r");
		if (globe.line != NULL && globe.line[0] != NULL)
			get_op_func(globe.line[0])(&globe.stack, globe.line_number);

		free(globe.line);
	}

	free(line);
	free_all(globe.stack, globe.file);
	return (EXIT_SUCCESS);
}
