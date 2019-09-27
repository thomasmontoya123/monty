#include "monty.h"

/**
 * _add - add two top elemnts
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int result = 0;


	if (!(*stack) || !(*stack)->next)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number),
		exit(EXIT_FAILURE);

	temporal = *stack;

	result = temporal->n + temporal->next->n;
	temporal->next->n = result;
	_pop(stack, line_number);
}
