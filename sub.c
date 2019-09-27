#include "monty.h"

/**
 * _sub - sub two top elemnts
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int result = 0;

	if (!(*stack) || !(*stack)->next)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number),
		exit(EXIT_FAILURE);

	temporal = *stack;

	result = temporal->next->n - temporal->n;
	temporal->next->n = result;
	_pop(stack, line_number);
}
