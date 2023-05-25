#include "shell.h"

/**
 * r_tokenize_func - function tokenizes the buffer with a delimiter
 * 
 * @buffer: is a buffer to tokenize
 * @delimiter: is a delimiter to tokenize along
 *
 * Return: array or tokens
 * 
 */
char **r_tokenize_func(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = r_new_strtok_func(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc_func(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
