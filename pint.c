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

	temporal = *stack;
	if (temporal)
		printf("%d\n", temporal->n);
	else
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number),
		exit(EXIT_FAILURE);
}
