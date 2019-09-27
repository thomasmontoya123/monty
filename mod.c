#include "monty.h"

/**
 * _mod - mod two top elemnts
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int result = 0;

	if (!(*stack) || !(*stack)->next)
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number),
		exit(EXIT_FAILURE);

	temporal = *stack;

	if (temporal->n == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number),
		exit(EXIT_FAILURE);

	result = temporal->next->n % temporal->n;
	temporal->next->n = result;
	_pop(stack, line_number);
}
