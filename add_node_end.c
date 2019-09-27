#include "monty.h"

/**
 * add_node_end - adds a new node at the end
 * @stack: head
 * @n: integer data
 * Return: void
 */

void add_node_end(stack_t **stack, const int n)
{
	stack_t *new_node, *last_node;

	new_node = _calloc(10, sizeof(stack_t));
	if (!new_node)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	new_node->next = NULL;
	new_node->n = n;

	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
	}

	last_node = *stack;

	while (last_node->next)
		last_node = last_node->next;

	last_node->next = new_node;
	new_node->prev = last_node;
}
