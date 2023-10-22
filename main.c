#include "monty.h"
#define _GNU_SOURCE

code_t code = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char *argv[])
{
	char *number;
	FILE *file;
	size_t n = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	code.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read > 0)
	{
		number = NULL;
		read = getline(&number, &n, file);
		code.number = number;
		counter++;

		if (read > 0)
			instruction(number, &stack, counter, file);

		free(number);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
