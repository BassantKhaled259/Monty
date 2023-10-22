#include "monty.h"

/**
 * _pop - print top node of stack
 * @top: pointer to pointer of first node
 * @counter: line number
 *
 * Return: void
 */

void _pop(stack_t **top, unsigned int counter)
{
	stack_t *head;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	head = *top;
	*top = head->next;
	free(head);
}

/**
 * _pint - print top node of stack
 * @top: pointer to first node of stack
 * @counter: line counter
 *
 * Return: void
 */

void _pint(stack_t **top, unsigned int counter)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}

/**
 * _nop - do nothing
 * @top: pointer to first node
 * @counter: line counter
 *
 * Return: void
 */

void _nop(stack_t **top, unsigned int counter)
{
	(void) counter;
	(void) top;
}
