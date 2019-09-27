#include "monty.h"

/**
 * _pchar -  prints the char at the top of the stack, followed by a new line.
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int ascii_value = 0;

	temporal = *stack;

	if (!temporal)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number),
		exit(EXIT_FAILURE);

	ascii_value = temporal->n;
	if (!isascii(ascii_value))
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number),
		exit(EXIT_FAILURE);

	printf("%c\n", ascii_value);
}
