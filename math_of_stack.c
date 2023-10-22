#include "monty.h"

/**
 * _add - add first douple link list to stack
 * @top: pointer to top of stack
 * @counter: line counter
 *
 * Return: void
 */

void _add(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	buf = head->n + head->next->n;
	head->next->n = buf;
	*top = head->next;
	free(head);
}

/**
 * _sub - subtract douple link list to stack
 * @top: pointer to top of stack
 * @counter: line counter
 *
 * Return: void
 */

void _sub(stack_t **top, unsigned int counter)
{
	stack_t *buf;
	int sub, end;

	buf = *top;
	for (end = 0; buf != NULL; end++)
		buf = buf->next;

	if (end < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	buf = *top;
	sub = buf->next->n - buf->n;
	buf->next->n = sub;
	*top = buf->next;
	free(buf);
}

/**
 * _mul - multiply first douple elements of the stack
 * @top: pointer to top of stack
 * @counter: line counter
 *
 * Return: void
 */

void _mul(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	buf = head->next->n * head->n;
	head->next->n = buf;
	*top = head->next;
	free(head);
}

/**
 * _div - divide first douple element of stack
 * @top: pointer to top of stack
 * @counter: line counter
 *
 * Return: void
 */

void _div(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	buf = head->next->n / head->n;
	head->next->n = buf;
	*top = head->next;
	free(head);
}

/**
 * _mod - modulos of two elements in stack
 * @top: pointer to top of stack
 * @counter: line counter
 *
 * Return: void
 */

void _mod(stack_t **top, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(code.file);
		free(code.number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	buf = head->next->n % head->n;
	head->next->n = buf;
	*top = head->next;
	free(head);
}
