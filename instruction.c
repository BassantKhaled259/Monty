#include "monty.h"

/**
* instruction - execute opcode
* @stack: stack of linked list
* @counter: line counter
* @file: the monty file
* @number: line content
*
* Return: void
*/
int instruction(char *number, stack_t **stack,
unsigned int counter, FILE *file)
{
instruction_t opoo[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *op;

	op = strtok(number, " \n\t");
	if (op && op[0] == '#')
		return (0);
	code.value = strtok(NULL, " \n\t");
	while (opoo[a].opcode && op)
	{
		if (strcmp(op, opoo[a].opcode) == 0)
		{	opoo[a].f(stack, counter);
			return (0);
		}
		a++;
	}
	if (op && opoo[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(number);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
