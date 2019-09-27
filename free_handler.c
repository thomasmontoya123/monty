#include"monty.h"

/**
 * free_handler - handles the free operations
 * @input_line: full line
 * @arguments: splited line
 * @main_checker: return of function handler
 * Return: void.
 */

void free_handler(char *input_line, char **arguments,
instruction_t *main_checker)
{
	(void) input_line;
	free(main_checker);
	free(arguments);
	/*free(input_line);*/
}
