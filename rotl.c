#include "monty.h"

/**
 * _rotl - swap stack values
 * @stack: stack head
 * @line_number: line nomber
 * return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temporal, *aux, *new_node;
	int hold = 0;

	(void)line_number;
	temporal = *stack;

	if (!(*stack) || !(*stack)->next)
		return;

	hold = temporal->n;
	_pop(stack, line_number);

	new_node = malloc(sizeof(stack_t)); /* allocate node */
	if (new_node == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	new_node->n = hold; /* put in the data  */
	new_node->next = NULL; /* New node is last node, next of it as NULL*/

	aux = *stack;

	if (aux == NULL)
		{	new_node->prev = NULL;
			aux = new_node;
		}

	while (temporal->next) /* Traverse till the last node */
		temporal = temporal->next;

	temporal->next = new_node; /* Change the next of last node */
	new_node->prev = temporal; /* Prev of new node to last node */
}
