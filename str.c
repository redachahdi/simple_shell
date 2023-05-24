#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *strdup_func(char *str)
{
        int a;
        int b;
	char *n;

	if (!str)
	{
		return (NULL);
	}
	for (b = 0; str[b] != '\0';)
	{
		b++;
	}
	n = malloc(sizeof(char) * b + 1);
	if (!n)
	{
		return (NULL);
	}
	for (a = 0; a < b; a++)
	{
		n[a] = str[a];
	}
	n[b] = str[b];
	return (n);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *all_func(char *name, char *sep, char *value)
{
	char *r;
	int a1;
	int a2;
	int a3;
	int b;
	int c;

	a1 = strlen_func(name);
	a2 = strlen_func(sep);
	a3 = strlen_func(value);

	r = malloc(a1 + a2 + a3 + 1);
	if (!r)
		return (NULL);

	for (b = 0; name[b]; b++)
		r[b] = name[b];
	c = b;

	for (b = 0; sep[b]; b++)
		r[c + b] = sep[b];
	c = c + b;

	for (b = 0; value[b]; b++)
		r[c + b] = value[b];
	c = c + b;

	r[b] = '\0';

	return (r);
}

/**
 * _strlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int strlen_func(char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * _putchar - writes the character c to stdout
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
 * _puts - prints a string
 * @str: pointer to string
 */

void puts_func(char *str)
{
	int a = 0;

	while (str[a])
	{
		_putchar(str[a]);
		a++;
	}
}
