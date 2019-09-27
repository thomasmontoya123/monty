#include "monty.h"

/**
 * _rotr - swap stack values
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int holder = 0;

	(void)line_number;

	if (!stack)
		return;

	temporal = *stack;

	while (temporal)
	{
		if (!temporal->next)
		{
			holder = temporal->n;
			temporal->prev->next = NULL;
			free(temporal);
			break;
		}
		temporal = temporal->next;
	}
	add_node_front(stack, holder);

}
