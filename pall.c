#include "monty.h"

/**
 * _pall - Prints all elements of a list stack_l.
 * @stack: Stack head
 * @line_number: Line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;

	(void) line_number;
	temporal = *stack;


	while (temporal)
	{
		printf("%d\n", temporal->n);
		temporal = temporal->next;
	}
}
