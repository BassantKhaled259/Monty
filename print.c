#include "monty.h"

/**
 * _pstr - print string at the top of stack
 * @top: first node of linked list
 * @counter: line number
 *
 * Return: void
 */

void _pstr(stack_t **top, unsigned int counter)
{
	stack_t *head;
	(void)counter;

	head = *top;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}


/**
 * _pchar - print the char at the top of stack
 * @top: stack head
 * @counter: line number
 *
 * Return: void
 */

void _pchar(stack_t **top, unsigned int counter)
{
	stack_t *head;

	head = *top;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
