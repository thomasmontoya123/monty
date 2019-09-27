#include "monty.h"

/**
 * launcher_error - check opcode and return struct with function pointer.
 * @arguments: splited line
 * @line_counter: number of lines
 * @check: Operation selector
 */
void launcher_error(char **arguments, int line_counter, instruction_t *check)
{
	if (check->opcode == NULL)
		fprintf(stderr, "L%d: unknown instruction %s\n",
		line_counter, arguments[0]), exit(EXIT_FAILURE);
	if (strcmp(check->opcode, "push") == 0 && !arguments[1])
		fprintf(stderr, "L%i: usage: push integer\n", line_counter),
		exit(EXIT_FAILURE);

}


/**
 * launcher - check opcode and return struct with function pointer.
 * @arguments: splited line
 * @line_counter: number of lines
 * Return: Struct with function pointer.
 */

instruction_t *launcher(char **arguments, int line_counter)
{
	unsigned int index = 0;
	instruction_t *check = NULL;
	instruction_t ops[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"swap", _swap},
	{"add", _add},
	{"nop", _nop},
	{"sub", _sub},
	{"mul", _mul},
	{"div", _div},
	{"mod", _mod},
	{"pchar", _pchar},
	{"pstr", _pstr},
	{"rotl", _rotl},
	{"rotr", _rotr},
	{NULL, NULL}
	};

	if (arguments[1])
		push_argument = arguments[1];
	check = _calloc(10, sizeof(instruction_t));
	check->opcode = NULL;
	check->f = NULL;
	if (!arguments[0] || arguments[0][0] == '#')
	{
		check->opcode = ops[6].opcode;
		check->f = ops[6].f;
		return (check);
	}
	while (ops[index].opcode && strcmp(arguments[0], ops[index].opcode) != 0)
		index++;
	check->opcode = ops[index].opcode;
	check->f = ops[index].f;
	launcher_error(arguments, line_counter, check);
	return (check);
}
