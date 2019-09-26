#include "monty.h"

/**
 * free_stack - free a stack_t list
 * @stack: Stack head
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temporal;

	if (!stack)
		return;

	while (stack)
	{
		temporal = stack;
		stack = stack->next;
		free(temporal);
	}
}
