
#include "monty.h"

/**
 * _getline - get the user input
 * @line: input line
 * @n: Buffer size
 * @fd: File descriptor
 * Return: pointer to the input line
 */

ssize_t _getline(char **line, size_t *n, ssize_t fd)
{
	int index = 0;
	int ascii_character = 0;

	(void) n;

	/*Return -3 for exit on failure from the main*/
	/* Memory allocation for buffer */
	*line = _calloc(10, sizeof(char) * 1024);
	if (!*line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-3);
	}

	while (1)
	{
	       /* Read a character */
		ascii_character = _getc(fd);
	       /* If we hit EOF, replace it with a null character and return */
		if (ascii_character == EOF || ascii_character == '\n')
		{
			line[index] = '\0';
			if (ascii_character == EOF)
				return (-1);
			else
				return (index + 1);
		}
		else
		{
			*(*line + index) = ascii_character;
			index++;
		}
	}
}
