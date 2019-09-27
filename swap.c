#include "monty.h"

/**
 * _swap - swap stack values
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int hold = 0;

	if (!(*stack) || !(*stack)->next)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number),
		exit(EXIT_FAILURE);

	temporal = *stack;

	hold = temporal->n;
	temporal->n = temporal->next->n;
	temporal->next->n = hold;
}
