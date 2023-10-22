#include "monty.h"

/**
* _pall - print the stack
* @top: pointer to first node
* @counter: line number (not used)
*
* Return: void
*/

void _pall(stack_t **top, unsigned int counter)
{
	stack_t *head;
	(void)counter;

	head = *top;
	if (head == NULL)
		return;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
* _swap - swap first two elements of stack
* @top: first node
* @counter: line counter
*
* Return: void
*/

void _swap(stack_t **top, unsigned int counter)
{
	stack_t *head;
	int size = 0, buf;

	head = *top;
	while (head)
	{
		head = head->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	buf = head->n;
	head->n = head->next->n;
	head->next->n = buf;
}
