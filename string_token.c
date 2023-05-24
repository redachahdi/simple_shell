#include "main.h"
/**
 * delim_to_check - function to Checks if the Character is more Char
 *
 * @c: is the Character 
 * @str: is the String 
 *
 * Return: if 1 is the Succes, if 0 is Failed
 */
unsigned int delim_to_check(char c, const char *str)
{
	unsigned int k;

	for (k = 0; str[k] != '\0'; k++)
	{
		if (c == str[k])
			return (1);
	}
	return (0);
}

/**
 * token_string - is the token of the String Into the token.
 *
 * @str: is the String
 * @delimi: is the delimiter
 
 * Return: to the Pointer to pointer next or null
 */
char *token_string(char *str, const char *delimi)
{
	static char *ss;
	static char *tt;
	unsigned int k;

	if (str != NULL)
		tt = str;
	ss = tt;
	if (ts == NULL)
		{
		    return (NULL);
		    }
	for (k = 0; ss[k] != '\0'; k++)
	{
		if (delim_to_check(ss[k], delimi) == 0)
			break;
	}
	if (tt[k] == '\0' || tt[k] == '#')
	{
		tt = NULL;
		return (NULL);
	}
	ss = tt + k;
	tt = ss;
	for (k = 0; tt[k] != '\0'; k++)
	{
		if (delim_to_check(tt[k], delimi) == 1)
			break;
	}
	if (tt[k] == '\0')
		tt = NULL;
	else
	{
		tt[k] = '\0';
		tt = tt + k + 1;
		if (*tt == '\0')
			tt = NULL;
	}
	return (ss);
}

