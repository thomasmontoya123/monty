#include "monty.h"

/**
 * _pstr - prints the string.
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal;
	int ascii_value = 0;

	(void)line_number;
	temporal = *stack;

	if (!(*stack))
		printf("\n");
	else
	{
		while (temporal->next)
		{
			ascii_value = temporal->n;
			if (isascii(ascii_value) && ascii_value != 0)
				printf("%c", ascii_value);
			else
				break;
			temporal = temporal->next;
		}
		printf("\n");
	}
}
