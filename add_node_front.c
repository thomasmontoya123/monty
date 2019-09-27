#include "monty.h"

/**
 * add_node_front - adds a new node at the beginning
 * @head: head
 * @n: integer data
 * Return: address of the new element, or NULL if it failed
 */

void add_node_front(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return;

	new_node = _calloc(10, sizeof(stack_t));

	if (!new_node)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
}
