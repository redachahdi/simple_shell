#include "shell.h"

/**
 * strdup_func - function returns a pointer to a newly allocated space
 *
 * @str: is a pointer to a string
 * Return: new
 */
char *strdup_func(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}

	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];

	return (new);
}

/**
 * all_func - function 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: result
 */
char *all_func(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = strlen_func(name);
	l2 = strlen_func(sep);
	l3 = strlen_func(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * strlen_func - function gives the length of a string
 * @s: pointer to the string
 * Return: i
 */
int strlen_func(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - function writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * puts_func - function prints a string
 * @str: pointer to string
 * return: 0
 */

void puts_func(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
