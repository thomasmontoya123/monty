#include "monty.h"

/**
 * _push - adds a new node at the beginning
 * @stack: stack head
 * @line_number: line nomber
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value = 0;
	int i = 0;

	new_node = _calloc(10, sizeof(stack_t));
	if (!new_node)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	if (push_argument[0] == '-' || push_argument[0] == '+')
		i = 1;

	for (; push_argument[i] != '\0'; i++)
	{
		if (isdigit(push_argument[i]) == 0)
			fprintf(stderr, "L%i: usage: push integer\n",
			line_number), exit(EXIT_FAILURE);
	}


	value = atoi(push_argument);

	new_node->n = value;
	new_node->prev = NULL;

	if (!*stack)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}

}
