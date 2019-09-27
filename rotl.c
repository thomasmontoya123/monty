#include "monty.h"

/**
 * _rotl - swap stack values
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	int holder = 0;


	if (*stack && stack && (*stack)->next)
	{
		holder = (*stack)->n;
		_pop(stack, line_number);
		add_node_end(stack, holder);
	}

}
