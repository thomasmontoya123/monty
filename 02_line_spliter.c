#include "monty.h"

/**
 * line_spliter - split the input string into tokens
 *
 * @inputLine: input string
 *
 * Return:addres of substrings
 */


char **line_spliter(char *inputLine)
{
	char *token, **tokens;
	int index = 0;
	const char tokenDelimiter[] = {" \n\r\t\a"};

	tokens = _calloc(10, sizeof(char *) * 1024);

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	token = strtok(inputLine, tokenDelimiter);

	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, tokenDelimiter);
		index++;
	}

	tokens[index] = NULL;

	if (!tokens)
		free(inputLine), exit(EXIT_FAILURE);

	return (tokens);
}
