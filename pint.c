#include "monty.h"

/**
 * _pint - Print the stack top
 * @stack: head
 * @line_number: number of lines
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;

	(void) line_number;
	temporal = *stack;
	if (temporal)
		printf("%d\n", temporal->n);
}
