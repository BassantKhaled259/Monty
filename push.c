#include "monty.h"

/**
 * _push - function that adds new node to the top of stack
 * @top: double top pointer to the stack
 * @counter: line counter
 *
 * Return: void
 */
void _push(stack_t **top, unsigned int counter)
{
	int y, x = 0, err = 0;

	if (code.value)
	{
		if (code.value[0] == '-')
			x++;
		for (; code.value[x] != '\0'; x++)
		{
			if (code.value[x] > 57 || code.value[x] < 48)
				err = 1; }
		if (err == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(code.file);
			free(code.number);
			free_stack(*top);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE); }
	y = atoi(code.value);
	if (code.lifo == 0)
		add_node(top, y);
	else
		add_queue(top, y);
}
