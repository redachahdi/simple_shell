#include "main.h"

/**
 * _putchar - function that writes the character
 *
 * @c: is the character 
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * cp_string - function that copie the string
 *
 * @dest:is the char destination
 * @src:is the char source 
 * @n:int
 *
 * Return:return the char 
 */

char *cp_string(char *dest, char *src, int n)
{
int k;

k = 0;
	while (k < n && *(src + k))
	{
	*(dest + k) = *(src + k);
	k++;
	}
	while (k < n)
	{
	*(dest + k) = '\0';
	k++;
	}
	return (dest);
}

/**
 * lengh_strg - function that lenght of  the string
 *
 * @st: is the char
 *
 * Return: is the integer
 */

int lengh_strg(char *s)
{
	int k;

		for (k = 0; s[k] != '\0'; k++)
		{
			continue;
		}
return (k);
}

/**
 * atoi_func - function that convert to the integer
 *
 * @s:is the string
 *
 * Return: is the integer
 */
int atoi_func(char *s)
{
int a, b, c, d;

	a = c = 0;
	d = 1;
	while ((s[a] < '0' || s[a] > '9') && (s[a] != '\0'))
	{
		if (s[a] == '-')
			d *= -1;
		a++;
	}
	b = a;
	while ((s[b] >= '0') && (s[b] <= '9'))
	{
		n = (n * 10) + d * ((s[b]) - '0');
		b++;
	}
	return (c);
}
/**
 * puts_func - function that print the  string
 *
 * @str: is the pointer
 *
 * return: is the void
 */
void puts_func(char *str)
{
	int k;

	for (k = 0; str[k] != '\0'; k++)
	{
		_putchar(str[k]);
	}
_putchar('\n');
return;
}
