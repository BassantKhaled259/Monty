#include "monty.h"

/**
 * _queue - print first node of queue
 * @top: first node of queue (unused)
 * @counter: line counter (unused)
 *
 * Return: void
 */

void _queue(stack_t **top, unsigned int counter)
{
	(void)top;
	(void)counter;

	code.lifo = 1;
}

/**
 * add_queue - add node to end of queue
 * @n: new value
 * @top: head of the queue
 *
 * Return: void
 */

void add_queue(stack_t **top, int n)
{
	stack_t *new_node, *buf;

	buf = *top;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;

	if (buf)
	{
		while (buf->next)
			buf = buf->next;
	}
	if (!buf)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		buf->next = new_node;
		new_node->prev = buf;
	}
}
