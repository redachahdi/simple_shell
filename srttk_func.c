#include "shell.h"
/**
 * r_check_match_func - function that checks if character matches any in string
 * 
 * @c: is a character to check
 * @str: is a string to check
 *
 * Return: 1 match or 0 not
 * 
 */
unsigned int r_check_match_func(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * r_new_strtok_func - function that custom strtok
 * 
 * @str: is a string to tokenize
 * @delim: is a delimiter to tokenize against
 * 
 * Return: next token or NULL
 * 
 */
char *r_new_strtok_func(char *str, const char *delim)
{
	static char *_token_start;
	static char *_next_token;
	unsigned int k;

	if (str != NULL)
		_next_token = str;
	_token_start = _next_token;
	if (_token_start == NULL)
		return (NULL);
	for (k = 0; _next_token[k] != '\0'; k++)
	{
		if (r_check_match_func(_next_token[k], delim) == 0)
			break;
	}
	if (_next_token[k] == '\0' || _next_token[k] == '#')
	{
		_next_token = NULL;
		return (NULL);
	}
	_token_start = _next_token + k;
	_next_token = _token_start;
	for (k = 0; _next_token[k] != '\0'; k++)
	{
		if (r_check_match_func(_next_token[k], delim) == 1)
			break;
	}
	if (_next_token[k] == '\0')
		_next_token = NULL;
	else
	{
		_next_token[k] = '\0';
		_next_token = _next_token + k + 1;
		if (*_next_token == '\0')
			_next_token = NULL;
	}
	return (_token_start);
}
