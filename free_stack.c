#include "monty.h"

/**
 * free_stack - freedoubly linked list
 * @top: top of stack
 * Return: void
 */

void free_stack(stack_t *top)
{
	stack_t *buf;

	buf = top;
	while (top)
	{
		buf = top->next;
		free(top);
		top = buf;
	}
}

/**
 * _stack - free stack
 * @top: first node(unused)
 * @counter: line counter (unused)
 *
 * Return: none
*/

void _stack(stack_t **top, unsigned int counter)
{
	(void)top;
	(void)counter;

	code.lifo = 0;
}
