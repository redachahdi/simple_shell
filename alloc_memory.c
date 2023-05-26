#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _realloc_func - s the function reallocates is a pointer
 *
 * @ptr: is a pointer to the old array
 * @size: is a pointer to number of elements in the old array
 *
 * Return: is the new
 *
 */
char **_realloc_func(char **ptr, size_t *size)
{
	char **new;
	size_t k;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (k = 0; k < (*size); k++)
	{
		new[k] = ptr[k];
	}
	*size += 10;
	free(ptr);
	return (new);
}
