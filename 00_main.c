#include "monty.h"
/**
* main - Simple shell
* @argc: argument count
* @argv: argument values vector.
* Return: Always 0.
*/
int main(int argc, char **argv)
{
	int line_counter = 1;
	FILE *fd;
	char *input_line = NULL,  **arguments = NULL;
	ssize_t readed_chars = 0;
	size_t size = 1024;
	stack_t *stack = NULL;
	instruction_t *main_checker = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (access(argv[1], R_OK) != 0)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	do {
		readed_chars = getline(&input_line, &size, fd);
		if (readed_chars == -1)
		{
			free(input_line);
			break;
		}
		if (input_line)
		{
			arguments = line_spliter(input_line);
			main_checker = launcher(arguments, line_counter);
			if (main_checker->opcode == NULL)
			{
				free_handler(input_line, arguments, main_checker);
				free_stack(stack), exit(EXIT_FAILURE);
			}
			main_checker->f(&stack, line_counter);
			free_handler(input_line, arguments, main_checker);
		}
		line_counter++;
	} while (1);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
