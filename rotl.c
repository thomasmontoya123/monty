#include "monty.h"

/**
 * _rotl - swap stack values
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal, *new_node;
	int hold = 0;

	if (!(*stack) || !(*stack)->next)
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_t)); /* 1. allocate node */
	if (new_node == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	temporal = *stack;
	hold = temporal->n;
	new_node->n = hold; /* put in the data  */
	new_node->next = NULL; /* New node is last node, next of it as NULL*/

	_pop(stack, line_number);

	temporal = *stack;
	while (temporal->next) /* Traverse till the last node */
		temporal = temporal->next;

	temporal->next = new_node; /* Change the next of last node */
	new_node->prev = temporal; /* Prev of new node to last node */
}
