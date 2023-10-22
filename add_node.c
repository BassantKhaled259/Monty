#include "monty.h"

/**
* add_node - add node to top of stack
* @top: first node
* @n: new value
*
* Return:void
*/

void add_node(stack_t **top, int n)
{
	stack_t *new_node, *element;

	element = *top;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (element)
		element->prev = new_node;

	new_node->n = n;
	new_node->next = *top;
	new_node->prev = NULL;
	*top = new_node;
}
