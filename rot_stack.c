#include "monty.h"

/**
 * _rotl- rotate stack element to the top (uptop)
 * @top: top element of stack
 * @counter: line counter
 *
 * Return: void
 */

void _rotl(stack_t **top,  __attribute__((unused)) unsigned int counter)
{
	stack_t *buf = *top, *uptop;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	uptop = (*top)->next;
	uptop->prev = NULL;
	while (buf->next != NULL)
	{
		buf = buf->next;
	}
	buf->next = *top;
	(*top)->next = NULL;
	(*top)->prev = buf;
	(*top) = uptop;
}

/**
 * _rotr - rotate stack element to the bottom (upside down)
 * @top: top node of stack
 * @counter: line counter
 *
 * Return: void
 */

void _rotr(stack_t **top, __attribute__((unused)) unsigned int counter)
{
	stack_t *updown;

	updown = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (updown->next)
	{
		updown = updown->next;
	}
	updown->next = *top;
	updown->prev->next = NULL;
	updown->prev = NULL;
	(*top)->prev = updown;
	(*top) = updown;
}
