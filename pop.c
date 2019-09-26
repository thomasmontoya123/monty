#include "monty.h"

/**
 * _pop - adds a new node at the beginning
 * @stack: stack head
 * @line_number: line nomber
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;

	if (!(*stack))
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number),
		exit(EXIT_FAILURE);

	temporal = *stack;
	*stack = temporal->next;
		if (temporal->next)
			temporal->next->prev = NULL;
	free(temporal);

}
