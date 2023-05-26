#include "shell.h"

/**
 * _puts_func - function that writes the string
 * 
 * @str: is a string to write
 *
 * Return: number of chars or -1
 * 
 */
ssize_t _puts_func(char *str)
{
	ssize_t num, len;

	num = _strlen_func(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup_func - function that returns pointer to new malloc space
 * 
 * @strtodup: is a string to be duplicated
 * Return: new duplicated string
 * 
 */
char *_strdup_func(char *strtodup)
{
	char *copy;

	int len;
	int i;

	if (strtodup == 0)
		return (NULL);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strtodup[i];

	return (copy);
}

/**
 * _strcmpr_func - function that compares two strings
 * 
 * @strcmp1: is the first string, of two, to be compared in length
 * @strcmp2: is the second string, of two, to be compared
 * Return: 0 anything else is a failure
 * 
 */
int _strcmpr_func(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat_func - function that concatenates two strings
 * 
 * @strc1: is the first string
 * @strc2: is the second string
 * Return: pointer
 * 
 */
char *_strcat_func(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1;
	unsigned int len2, newlen, k, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (k = 0; k < len1; k++)
		newstring[k] = strc1[k];
	newstring[k] = '/';
	for (j = 0; j < len2; j++)
		newstring[k + 1 + j] = strc2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}

/**
 * _strlen_func - function that returns the length of a string
 * 
 * @str: is a string to be measured
 * Return: length of string
 * 
 */
unsigned int _strlen_func(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
