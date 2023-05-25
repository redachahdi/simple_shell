#include "shell.h"

/**
 * _realloc_func - function reallocates is a pointer
 * 
 * @ptr: is a pointer to the old array
 * @size: is a pointer to number of elements in the old array
 *
 * Return: new
 *
 */
char **_realloc_func(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}
